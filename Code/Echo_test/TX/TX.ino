#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

#define CLIENT_ADDRESS 1
#define SERVER_ADDRESS 2

static const int SDN = 10;
uint8_t data[RH_RF22_MAX_MESSAGE_LEN];
uint8_t buf[RH_RF22_MAX_MESSAGE_LEN]; 
uint8_t randomData[10][255];
int i, j, k, counter, aciertos, msn_size, msgsTotales;
int aciertosTotales = 0;

// Singleton instance of the radio driver.
RH_RF22 driver(4,2);

// Class to manage message delivery and receipt, using the driver declared above.
RHReliableDatagram rf22(driver, CLIENT_ADDRESS);

/**
 * The transceiver is initialized and some parameters are selected,
 */
void setup() {
    Serial.begin(115200);
    pinMode(SDN, OUTPUT);
    digitalWrite(SDN, LOW);
    delay(1500);
    if (!rf22.init()) {
        Serial.println(F("Initialization failed"));
    }
    Serial.println(F("Echo test (TX)"));
    driver.setCRCPolynomial(driver.CRC_CCITT);
    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(433.0, 0.05); 
    driver.setTxPower(RH_RF22_TXPOW_20DBM); 
    if (!driver.setModemConfig(driver.FSK_Rb2Fd5)) { 
        Serial.println(F("Configuration error"));
    }
    rf22.setRetries(3);   
    Serial.println(F("Set Tx Power = RH_RF22_TXPOW_20DB"));
    Serial.println(F("Set configuration = FSK_Rb2Fd5"));
    
    Test();    
    Serial.print(F("\n Aciertos totales: "));
    Serial.print(aciertosTotales);
    Serial.print(F(" de "));
    Serial.print(k*10);
} 

void loop() { 
    
}
/**
 * Generates 10 packets of 255 bytes of random numbers.
 */
void generateRandomData() {
    for (i = 0; i < 10; i++) {
        for (j = 0; j < RH_RF22_MAX_MESSAGE_LEN; j++){
            randomData[i][j] = random(0,255);   
        }        
    }
}
/**
 * This function sends a total of 1000 packets of 255 bytes each,
 * with random numbers between 0 and 255. Every 10 packets sent,
 * an information is printed on screen about how many of them have
 * succesfully arrived and the current number of packets received.
 */
void Test() {
    for (k = 0; k < 100; k++) {
        generateRandomData();
        for (i = 0; i < 10; i++) {
            for (j = 0; j < RH_RF22_MAX_MESSAGE_LEN; j++) {
                data[j] = randomData[i][j];
            }
            sendPacket(data, RH_RF22_MAX_MESSAGE_LEN);    
        }
        msgsTotales += 10;
        aciertosTotales += aciertos; 
        Serial.print(F("   Aciertos: "));
        Serial.print(aciertos);
        Serial.print(F(" de "));
        Serial.print(i);
        Serial.print(F("       Aciertos parciales: "));
        Serial.print(aciertosTotales);
        Serial.print(F(" de "));
        Serial.println(msgsTotales);
        Serial.print(F("\n"));  
        aciertos = 0;   
    }
}
/**
 * This function sends a packet to the server and then waits for a
 * confirmation, if it does not arrive, an error is printed on 
 * screen. If it arrives, waits for the forwarded packet to compare
 * it with the original, adding a counter.
 * @param data[] Data sent to the server.
 * @param data_size SIze of the packet to be sent.
 */
void sendPacket(uint8_t data[], int data_size) {
    if (rf22.sendtoWait(data, data_size, SERVER_ADDRESS)) {
        uint8_t len = sizeof(buf);
        uint8_t from;  
        if (rf22.recvfromAckTimeout(buf, &len, 2000, &from)) {
            for (j = 0; j < data_size; j++) {
                counter += (data[j] == buf[j]);
            }
            aciertos += (counter == data_size);
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
