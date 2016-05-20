#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

// Singleton instance of the radio driver.
RH_RF22 driver(4,2);

// Class to manage message delivery and receipt, using the driver declared above.
RHReliableDatagram rf22(driver, SERVER_ADDRESS);

static const int SDN = 10;
uint8_t array[RH_RF22_MAX_MESSAGE_LEN];
uint8_t received_msg[RH_RF22_MAX_MESSAGE_LEN];
uint8_t buf[RH_RF22_MAX_MESSAGE_LEN]; 
int i, j, msn_size, counter, successes;
char letter;

void setup() {
    Serial.begin(115200);
    pinMode(SDN, OUTPUT);
    digitalWrite(SDN, LOW);
    delay(500);
    if (!rf22.init()) {
        Serial.println(F("Initialization failed"));
    }
    driver.setCRCPolynomial(driver.CRC_CCITT);
    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(433.0, 0.05); 
    driver.setTxPower(RH_RF22_TXPOW_20DBM);
    if (!driver.setModemConfig(driver.FSK_Rb2Fd5)) {
        Serial.println(F("Configuration error"));    
    }    rf22.setRetries(5);  
}

void loop() {  
    if (Serial.available()) {
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
        Serial.print(bin);
    }
}

void recibir() {
    if (rf22.available()) {
        uint8_t len = sizeof(buf);
        uint8_t from;
        if (rf22.recvfromAck(buf, &len, &from)) { 
            for (j = 0; j < len; j++) {
                Serial.print((char)buf[j]);
                //printByte(buf[j]);
            }
            Serial.print("\n");
            if (!rf22.sendtoWait(buf, len, from)) {
                Serial.println(F("Confirmation failed"));
            }
        }
    }
}

void chat() {
    msn_size = 0;  
    while (Serial.available()) {
        letter = Serial.read();
        if (letter == '\0' || msn_size == 255) {
            break;
        }
        array[msn_size] = letter;
        msn_size++;
        delay(3);
    }  
    uint8_t datos[msn_size];
    for (i = 0; i < msn_size; i++) {
        datos[i] = array[i];
        Serial.print((char)array[i]);
    }
    sendPacket(datos, msn_size);
}

void sendPacket(uint8_t data[], int data_size) {
    if (rf22.sendtoWait(data, data_size, CLIENT_ADDRESS)) {
        uint8_t len = sizeof(buf);
        uint8_t from;  
        if (rf22.recvfromAckTimeout(buf, &len, 2000, &from)) {
            for (j = 0; j < data_size; j++) {
                counter += (data[j] == buf[j]);
            }
            Serial.print(F("\nAre they equal?: "));
            Serial.println(counter == data_size);
            successes += (counter == data_size);
            counter = 0;          
        }
        else {
            Serial.println(F("Echo failed"));
        }
    }
    else {
      Serial.println(F("Confirmation failed"));
    } 
}



