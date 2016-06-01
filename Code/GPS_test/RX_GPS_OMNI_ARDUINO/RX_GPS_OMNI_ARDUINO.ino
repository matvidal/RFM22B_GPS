 #include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>
#include "RX.h"

#define RADIOSONDE_ADDRESS 1
#define OMNI_ARDUINO_ADDRESS 2

static const int SDN = 10;

// Singleton instance of the radio driver
RH_RF22 driver(4,2);

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram rf22(driver, OMNI_ARDUINO_ADDRESS);

/**
 * The serial communication and the transceiver are initialized. 
 */
void setup() {
    Serial.begin(115200);
    delay(1500);
    pinMode(SDN, OUTPUT);
    digitalWrite(SDN, LOW);
    if (!rf22.init()) {
        Serial.println(F("Initialization failed"));
    }
    Serial.println(F("GPS telemetry receiver (Arduino with omnidirectional antenna)"));
    driver.setCRCPolynomial(driver.CRC_CCITT);
    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(437.225, 0.05); 
    driver.setTxPower(RH_RF22_TXPOW_20DBM);
    if (!driver.setModemConfig(driver.FSK_Rb2Fd5)) {
        Serial.println(F("Configuration error"));    
    }
    rf22.setRetries(5);  
    Serial.println(F("Set Tx Power = RH_RF22_TXPOW_20DB"));
    Serial.println(F("Set configuration = FSK_Rb2Fd5")); 
}

void loop() {  
    receivePacket();
}

/**
 * The packet is received and decoded in order to display it's information.
 */
void receivePacket() {
    if (rf22.available()) {
        len = sizeof(packet);
        if (rf22.recvfromAck(packet, &len, &from)) {
            decodePacket();
            displayInfo();
        }
    }
}

