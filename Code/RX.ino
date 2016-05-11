#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

// Instancia singleton del driver de la radio.
RH_RF22 driver(4,2);

// La clase que maneja el envio y recibo de mensajes, usando el driver
// declarado arriba.
RHReliableDatagram rf22(driver, SERVER_ADDRESS);

uint8_t buf[RH_RF22_MAX_MESSAGE_LEN]; 
/**
 * Se inicializa el transceiver y se selecciona el flag, la frecuencia,
 * y el CRC.
 */
void setup() {
    SerialUSB.begin(38400);
    pinMode(10, OUTPUT);
    digitalWrite(10, LOW);
    driver.setCRCPolynomial(driver.CRC_CCITT);
    if (!rf22.init())
        SerialUSB.println("Fallo la inicializacion");

    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(433.0, 0.05); 
    driver.setTxPower(RH_RF22_TXPOW_20DBM);
    rf22.setRetries(5);  

    driver.setModemConfig(driver.FSK_Rb2Fd5);
}

void loop() {  
    recibir();
}

/**
 * Se espera que llege un mensaje con esta direccion de parte
 * del cliente y luego se reenvia.
 */
void recibir() {
    if (rf22.available()) {
        uint8_t len = sizeof(buf);
        uint8_t from;
        if (rf22.recvfromAck(buf, &len, &from)) {
            SerialUSB.print("\n");
            if (!rf22.sendtoWait(buf, len, from)) {
                SerialUSB.println("Fallo la confirmacion");
            }
        }
    }
}
