#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

// Singleton instance of the radio driver
RH_RF22 driver(4,2);

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram rf22(driver, SERVER_ADDRESS);

uint8_t array[RH_RF22_MAX_MESSAGE_LEN];
uint8_t received_msg[RH_RF22_MAX_MESSAGE_LEN];
uint8_t buf[RH_RF22_MAX_MESSAGE_LEN]; 
int i, j, msn_size, counter, aciertos;
char letra;

void setup() {
    SerialUSB.begin(38400);
    pinMode(10, OUTPUT);
    digitalWrite(10, LOW);
    delay(500);
    driver.setCRCPolynomial(driver.CRC_CCITT);
    if (!rf22.init())
        SerialUSB.println("init failed");

    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(433.0, 0.05); 
    driver.setTxPower(RH_RF22_TXPOW_20DBM);
    rf22.setRetries(5);  

    driver.setModemConfig(driver.FSK_Rb2Fd5);
}

void loop() {  
    if (SerialUSB.available()) {
        chat();    
    }
    recibir();
    recibir();
    
}

void printByte(uint8_t octet) {
    int i, bin;
    for (i = 0; i < 8; i++) {
        bin = (octet << i) & 128;
        bin = bin >> 7;
        SerialUSB.print(bin);
    }
}

void recibir() {
    if (rf22.available()) {
        uint8_t len = sizeof(buf);
        uint8_t from;
        if (rf22.recvfromAck(buf, &len, &from)) { 
            for (j = 0; j < len; j++) {
                SerialUSB.print((char)buf[j]);
                //printByte(buf[j]);
            }
            SerialUSB.print("\n");
            if (!rf22.sendtoWait(buf, len, from)) {
                SerialUSB.println("Fallo la confirmacion");
            }
        }
    }
}

void chat() {
    msn_size = 0;  
    while (SerialUSB.available()) {
        letra = SerialUSB.read();
        if (letra == '\0' || msn_size == 255) {
            break;
        }
        array[msn_size] = letra;
        msn_size++;
        delay(3);
    }  
    uint8_t datos[msn_size];
    for (i = 0; i < msn_size; i++) {
        datos[i] = array[i];
        SerialUSB.print((char)array[i]);
    }
    enviar(datos, msn_size);
}

void enviar(uint8_t data[], int data_size) {
    if (rf22.sendtoWait(data, data_size, CLIENT_ADDRESS)) {
        uint8_t len = sizeof(buf);
        uint8_t from;  
        if (rf22.recvfromAckTimeout(buf, &len, 2000, &from)) {
            for (j = 0; j < data_size; j++) {
                counter += (data[j] == buf[j]);
            }
            SerialUSB.print("\nSon iguales?: ");
            SerialUSB.println(counter == data_size);
            aciertos += (counter == data_size);
            counter = 0;          
        }
        else {
            SerialUSB.println("Fallo el eco");
        }
    }
    else {
      SerialUSB.println("Fallo la confirmacion");
    } 
}



