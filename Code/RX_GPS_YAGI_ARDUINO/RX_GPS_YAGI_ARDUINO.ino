#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

#define RADIOSONDE_ADDRESS 1
#define YAGI_ARDUINO_ADDRESS 3

static const int SDN = 10;
uint8_t hh;
uint8_t mm;
uint8_t ss;
uint8_t len;
uint8_t from;
uint8_t packet[27];
uint32_t sat;
int tmp;
double lat_dbl;
double lng_dbl;
double alt_dbl;
double crse_dbl;
double spd_dbl;

// Singleton instance of the radio driver
RH_RF22 driver(4,2);

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram rf22(driver, YAGI_ARDUINO_ADDRESS);

/**
 * The serial communication and the transceiver are initialized. 
 */
void setup() {
    Serial.begin(115200);
    delay(2000);
    pinMode(SDN, OUTPUT);
    digitalWrite(SDN, LOW);
    if (!rf22.init()) {
        Serial.println(F("Initialization failed"));
    }
    Serial.println(F("GPS telemetry receiver  (Arduino with Yagi antenna)"));
    driver.setCRCPolynomial(driver.CRC_CCITT);
    driver.setHeaderFlags(0x7E); 
    driver.setFrequency(437.225, 0.05); 
    driver.setTxPower(RH_RF22_TXPOW_20DBM);
    if (!driver.setModemConfig(driver.GFSK_Rb2Fd5)) {
        Serial.println(F("Configuration error"));    
    }
    rf22.setRetries(5);  
    Serial.println(F("Set Tx Power = RH_RF22_TXPOW_20DB"));
    Serial.println(F("Set configuration = GFSK_Rb2Fd5"));  
}

void loop() {  
    recibir();
}

/**
 * The packet is received and decoded in order to display it's information.
 */
void recibir() {
    if (rf22.available()) {
        len = sizeof(packet);
        if (rf22.recvfromAck(packet, &len, &from)) {
            decodePacket();
            displayInfo();
        }
    }
}
/**
 *  The packet is decoded transforming uint8_t to double if it's necesary
 *  and saving the data in the corresponding variables (latitude, longitude,
 *  altitude, course, speed, time and the number of satellites detected).
 */
void decodePacket() {
  tmp = packet[0];
  tmp = (tmp << 8) + packet[1];
  tmp = (tmp << 8) + packet[2];
  tmp = (tmp << 8) + packet[3];
  lat_dbl = tmp/1000000.0;
  
  tmp = packet[4];
  tmp = (tmp << 8) + packet[5];
  tmp = (tmp << 8) + packet[6];
  tmp = (tmp << 8) + packet[7];
  lng_dbl = tmp/1000000.0;
  
  tmp = packet[8];
  tmp = (tmp << 8) + packet[9];
  tmp = (tmp << 8) + packet[10];
  tmp = (tmp << 8) + packet[11];
  alt_dbl = tmp/1000.0;

  tmp = packet[12];
  tmp = (tmp << 8) + packet[13];
  tmp = (tmp << 8) + packet[14];
  tmp = (tmp << 8) + packet[15];
  crse_dbl = tmp/1000.0;

  tmp = packet[16];
  tmp = (tmp << 8) + packet[17];
  tmp = (tmp << 8) + packet[18];
  tmp = (tmp << 8) + packet[19];
  spd_dbl = tmp/1000.0;

  hh = packet[20];
  mm = packet[21];
  ss = packet[22];

  sat = packet[23];
  sat = (sat << 8) + packet[24];
  sat = (sat << 8) + packet[25];
  sat = (sat << 8) + packet[26];
}
/**
 * Displays the data in a comprehensible way.
 */
void displayInfo() {
  Serial.print(F("Location: ")); 
  Serial.print(lat_dbl, 6);
  Serial.print(F(","));
  Serial.print(lng_dbl, 6);

  Serial.print(F("   Altitude(GPS): ")); 
  Serial.print(alt_dbl);
  Serial.print(F(" [m]"));

  Serial.print(F("   Course: ")); 
  Serial.print(crse_dbl);

  Serial.print(F("   Speed: ")); 
  Serial.print(spd_dbl);
  Serial.print(F(" [mph]"));

  Serial.print(F("   Time: "));
  if (hh < 10) {
    Serial.print(F("0"));
  }
  Serial.print(hh);
  Serial.print(F(":"));
  if (mm < 10) {
    Serial.print(F("0"));
  }
  Serial.print(mm);
  Serial.print(F(":"));
  if (ss < 10) {
    Serial.print(F("0"));
  }
  Serial.print(ss);
  
  Serial.print(F("   Satellites: ")); 
  Serial.println(sat);
}
