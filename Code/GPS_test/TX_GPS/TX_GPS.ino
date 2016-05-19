#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>
#include <TinyGPS++.h>

#define RADIOSONDE_ADDRESS 1
#define OMNI_ARDUINO_ADDRESS 2
#define YAGI_ARDUINO_ADDRESS 3
#define EARTH_STATION_ADDRESS 4

static const uint32_t GPSBaud = 9600;
static const int SDN = 10;
uint8_t packet[27];
uint8_t buf[RH_RF22_MAX_MESSAGE_LEN]; 
uint8_t len;
uint8_t from;
uint32_t sat;
int lttd;
int lgtd;
int alt;
int crse;
int spd;

// Singleton instance of the radio driver
RH_RF22 driver(4,2);

// Class to manage message delivery and receipt, using the driver declared above
RHReliableDatagram rf22(driver, RADIOSONDE_ADDRESS);

// The TinyGPS++ object
TinyGPSPlus gps;

/**
 * Se inicializa el transceiver y se selecciona el flag, la frecuencia,
 * y el CRC.
 */
void setup() {
    Serial.begin(115200);
    Serial2.begin(GPSBaud);
    pinMode(SDN, OUTPUT);
    digitalWrite(SDN, LOW);
    delay(2000);
    if (!rf22.init()) {
        Serial.println(F("Initialization failed"));
    }
    Serial.println(F("GPS telemetry transmitter"));
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
    while (Serial2.available() > 0) {
        if (gps.encode(Serial2.read())) {
            encodePacket();
            enviar(packet, sizeof(packet));
        }
    }
    if (millis() > 5000 && gps.charsProcessed() < 10) {
        Serial.println(F("No GPS detected: check wiring."));
    }
}
/**
 * Esta funcion envia un paquete al servidor y luego espera una
 * confirmacion, si no llega imprime un error en pantalla.
 * @param data[] Datos enviados al servidor.
 * @param data_size Tamano del paquete enviado.
 */
void enviar(uint8_t data[], int data_size) {
    if (!rf22.sendtoWait(data, data_size, OMNI_ARDUINO_ADDRESS))
        Serial.println(F("sendtoWait failed (Omnidirectional arduino)"));
    if (!rf22.sendtoWait(data, data_size, YAGI_ARDUINO_ADDRESS))
        Serial.println(F("sendtoWait failed (Yagi arduino)"));
    if (!rf22.sendtoWait(data, data_size, EARTH_STATION_ADDRESS))
        Serial.println(F("sendtoWait failed (Earth station)"));
}
/**
 * Se espera que llege un mensaje con esta direccion de parte
 * del cliente y luego se reenvia.
 */
void recibir() {
    if (rf22.available()) {
        len = sizeof(buf);
        if (rf22.recvfromAck(buf, &len, &from)) {
            Serial.print("\n");
            if (!rf22.sendtoWait(buf, len, from)) {
                Serial.println(F("sendtoWait failed"));
            }
        }
    }
}
void encodePacket() {
    if (gps.location.isValid()) {
        lttd = gps.location.lat()*1000000;
        lgtd = gps.location.lng()*1000000;

        packet[0] = lttd >> 24;
        packet[1] = lttd >> 16;
        packet[2] = lttd >> 8;
        packet[3] = lttd;
        packet[4] = lgtd >> 24;
        packet[5] = lgtd >> 16;
        packet[6] = lgtd >> 8;
        packet[7] = lgtd;
    }
    if (gps.altitude.isValid()) {
        alt = gps.altitude.meters()*1000;
    
        packet[8] = alt >> 24;
        packet[9] = alt >> 16;
        packet[10] = alt >> 8;
        packet[11] = alt;
    }
    if (gps.course.isValid()) {
        crse = gps.course.deg()*1000;
    
        packet[12] = crse >> 24;
        packet[13] = crse >> 16;
        packet[14] = crse >> 8;
        packet[15] = crse;
    }
    if (gps.speed.isValid()) {
        spd = gps.speed.mph()*1000;
    
        packet[16] = spd >> 24;
        packet[17] = spd >> 16;
        packet[18] = spd >> 8;
        packet[19] = spd;
    }
    if (gps.time.isValid()) {
        packet[20] = gps.time.hour();
        packet[21] = gps.time.minute();
        packet[22] = gps.time.second();
    }
    if (gps.satellites.isValid()) {
        sat = gps.satellites.value();
    
        packet[23] = sat >> 24;
        packet[24] = sat >> 16;
        packet[25] = sat >> 8;
        packet[26] = sat;
    }
}
