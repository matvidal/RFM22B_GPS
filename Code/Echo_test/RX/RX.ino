#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

static const int SDN = 10;
uint8_t buf[RH_RF22_MAX_MESSAGE_LEN]; 

// Singleton instance of the radio driver
RH_RF22 driver(4,2);

// Class to manage message delivery and receipt, using the driver declared above.
RHReliableDatagram rf22(driver, SERVER_ADDRESS);

/**
 * The transceiver is initialized and some parameters are selected,
 */
void setup() {
    Serial.begin(115200);
    pinMode(SDN, OUTPUT);
    digitalWrite(SDN, LOW);
    delay(1500);
    if (!rf22.init()) {
        Serial.println("Initialization failed");
    }
    Serial.println("Echo test (RX)");
    driver.setCRCPolynomial(driver.CRC_CCITT);
    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(433.0, 0.05); 
    driver.setTxPower(RH_RF22_TXPOW_20DBM);
    if (!driver.setModemConfig(driver.FSK_Rb2Fd5)) {
        Serial.println(F("Configuration error"));
    }
    rf22.setRetries(5); 
}

void loop() {  
    receivePacket();
}

/**
 * It waits until a message is available. If that happens, the packet is forwarded.
 */
void receivePacket() {
    if (rf22.available()) {
        uint8_t len = sizeof(buf);
        uint8_t from;
        if (rf22.recvfromAck(buf, &len, &from)) {
            Serial.print("\n");
            if (!rf22.sendtoWait(buf, len, from)) {
                Serial.println("Confirmation failed");
            }
        }
    }
}
