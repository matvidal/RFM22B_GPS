#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

static const int SDN = 10;
uint8_t data[RH_RF22_MAX_MESSAGE_LEN];

// Singleton instance of the radio driver.
RH_RF22 driver(4,2);

// Class to manage message delivery and receipt, using the driver declared above.
RHReliableDatagram rf22(driver, CLIENT_ADDRESS);

void setup() {
    Serial.begin(115200);
    pinMode(SDN, OUTPUT);
    digitalWrite(SDN, LOW);
    delay(2000);
    if (!rf22.init()) {
        Serial.println(F("Initialization failed"));
    }
    Serial.println(F("Unidirectional test (TX)"));
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
    sendPacket(data, RH_RF22_MAX_MESSAGE_LEN);
}
/**
 * Generates an array of random numbers between 0 and 255.
 */
void generateRandomData() {
    for (int i = 0; i < RH_RF22_MAX_MESSAGE_LEN; i++){
        data[i] = random(0,255);              
    }
}
/**
 * This function sends a packet to the receiver and then it waits for a confirmation,
 * if there is no acknowledge, an error is printed on screen.
 * @param data[] Data sent to the receiver..
 * @param data_size Size of the packet to be sent.
 */
void sendPacket(uint8_t data[], int data_size) {
    generateRandomData();
    if (!rf22.sendtoWait(data, data_size, SERVER_ADDRESS))
        Serial.println(F("sendtoWait failed"));
}
