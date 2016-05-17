#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

static const int SDN = 10;
uint8_t data[RH_RF22_MAX_MESSAGE_LEN];
uint8_t from;
uint8_t len;

// Singleton instance of the radio driver
RH_RF22 driver(4,2);

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram rf22(driver, SERVER_ADDRESS);

void setup() {
    Serial.begin(115200);
    pinMode(SDN, OUTPUT);
    digitalWrite(SDN, LOW);
    delay(2000);
    if (!rf22.init()) {
        Serial.println(F("Initialization failed"));
    }
    Serial.println(F("Unidirectional test (RX)"));
    driver.setCRCPolynomial(driver.CRC_CCITT);
    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(437.225, 0.05); 
    driver.setTxPower(RH_RF22_TXPOW_20DBM);
    if (!driver.setModemConfig(driver.GFSK_Rb2Fd5)) {
        Serial.println(F("Configuration error"));    
    }
    rf22.setRetries(3);
    Serial.println(F("Set Tx Power = RH_RF22_TXPOW_20DB"));
    Serial.println(F("Set configuration = GFSK_Rb2Fd5")); 
}

void loop() {
    receivePacket();
}
/**
 * The packet is received and displayed on screen.
 */
void receivePacket() {
    if (rf22.available()) {
        len = sizeof(data);
        if (rf22.recvfromAck(data, &len, &from)) {
            Serial.print(F("Got request from : 0x"));
            Serial.print(from, HEX);
            Serial.print(F(": "));
            Serial.println((char*)data);
        }
    }
}
