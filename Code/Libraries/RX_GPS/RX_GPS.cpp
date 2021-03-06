#include <RX_GPS.h>

/*                          Parameters                         */
uint8_t hh;
uint8_t mm;
uint8_t ss;
uint8_t len;
uint8_t from;
uint8_t packet[27];
uint32_t sat;
int tmp;
double stationsLat;
double stationsLon;
double stationsAlt;
double cos_stationsLat;
double lat_dbl;
double lng_dbl;
double alt_dbl;
double crse_dbl;
double spd_dbl;
double gnd_dist;
double z_dist;
double dlat;
double dlon;
double haversin_dlat;
double haversin_dlon;
double a, c, d, az; 

/*                           Functions                            */

/**
 * Sets the receiver station's latitude.
 * @param newLat The new latitude of the receiver in degrees.
 */
void setStationsLat(double newLat) {
    stationsLat = newLat;
}

/**
 * Sets the receiver station's longitude.
 * @param newLon The new longitude of the receiver in degrees.
 */
void setStationsLon(double newLon) {
    stationsLon = newLon;
}

/**
 * Sets the receiver station's altitude.
 * @param newAlt The new altitude of the receiver in meters.
 */
void setStationsAlt(double newAlt) {
    stationsAlt = newAlt;
}

/**
 * Sets the receiver station's cosine of the station's latitude in
 * radians. This calculation is made frequently, so it is better to set
 * this value at the beginning for better performance.
 * @param newCosLat cos(stationsLat * deg2rad);
 */
void setCosStationsLat(double newCosLat){
    cos_stationsLat = newCosLat;
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
    Serial.print(F("Loc: ")); 
    Serial.print(lat_dbl, 6);
    Serial.print(F(","));
    Serial.print(lng_dbl, 6);

    Serial.print(F("   Alt: ")); 
    Serial.print(alt_dbl, 1);
    Serial.print(F(" [m]"));

    Serial.print(F("   Dist: ")); 
    Serial.print(realDistance(lat_dbl, lng_dbl, alt_dbl));
    Serial.print(F(" [m]"));

    Serial.print(F("   Course: ")); 
    Serial.print(crse_dbl);

    Serial.print(F("   Speed: ")); 
    Serial.print(spd_dbl);
    Serial.print(F(" [mps]"));

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
  
    Serial.print(F("   Sat: ")); 
    Serial.print(sat);

    Serial.print(F("   Az/El: "));
    Serial.print(azimuth(lat_dbl, lng_dbl), 1);
    Serial.print(F("/"));
    Serial.println(elevation(lat_dbl, lng_dbl, alt_dbl), 1);
}

/**
 * Calculates the azimuth angle between the TX and the RX given a fixed position
 * for the receiver.
 * @param lat2 The latitude of the transmiter.
 * @param lon2 The longitude of the transmiter.
 * @return The azimuth angle in degrees between the TX and the RX.
 */
double azimuth(double lat2, double lon2) {
    dlat = (lat2 - stationsLat) * deg2rad;
    dlon = (lon2 - stationsLon) * deg2rad; 
    az = atan2(dlon, dlat) * rad2deg;
    if(az < 0) {
        az = 360 + az;
    }
    return az;
}

/**
 * This function calculates the elevation of the transmiter given the altitude of
 * the receiver.
 * @param lat2 The latitude of the transmiter.
 * @param lon2 The longitude of the transmiter.
 * @param alt The altitude of the transmiter.
 * @return The elevation angle in degrees of the transmiter with respect to the receiver.
 */
double elevation(double lat2, double lon2, double alt) {
    gnd_dist = coord_dist(lat2, lon2);
    return atan((alt - stationsAlt) / gnd_dist) * rad2deg;
}

/**
 * Calculates the distance in the ground between the transmiter and the receiver,
 * with the last one being in a fixed position. This function also takes into 
 * consideration the curvature of the Earth.
 * @param lat2 The latitude of the transmiter.
 * @param lon2 The longitude of the transmiter.
 * @return The distance in meters between TX and RX in the XY plane.
 */
double coord_dist(double lat2, double lon2) {
    dlat = (lat2 - stationsLat) * deg2rad;
    dlon = (lon2 - stationsLon) * deg2rad;
    haversin_dlat = sin(dlat / 2.0);
    haversin_dlon = sin(dlon / 2.0);
    a = haversin_dlat * haversin_dlat + cos_stationsLat * cos(lat2 * deg2rad) * haversin_dlon * haversin_dlon;
    c = 2 * atan2(sqrt(a), sqrt(1 - a));
    d = 6371 * c;
    return d *1000;
}

/**
 * Calculates the distance between the transmiter and the receiver, considering the altitudes
 * and the coordinates. The receiver must be in a fixed position.
 * @param lat2 The latitude of the transmiter.
 * @param lon2 The longitude of the transmiter.
 * @param alt The altitude of the transmiter.
 * @return The distance in meters between TX and RX in the space.
 */
double realDistance(double lat2, double lon2, double alt) {
    gnd_dist = coord_dist(lat2, lon2);
    z_dist = alt - stationsAlt;
    return sqrt((z_dist * z_dist) + (gnd_dist * gnd_dist));
}
