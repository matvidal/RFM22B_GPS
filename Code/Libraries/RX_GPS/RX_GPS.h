#ifndef RX_GPS_h
#define RX_GPS_h

#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

/*                          Parameters                         */
static const double deg2rad = 0.0174532925199433; //PI/180;
static const double rad2deg = 57.295779513082321; //180/PI;
extern uint8_t hh;
extern uint8_t mm;
extern uint8_t ss;
extern uint8_t len;
extern uint8_t from;
extern uint8_t packet[27];
extern uint32_t sat;
extern int tmp;
extern double stationsLat;
extern double stationsLon;
extern double stationsAlt;
extern double cos_stationsLat;
extern double lat_dbl;
extern double lng_dbl;
extern double alt_dbl;
extern double crse_dbl;
extern double spd_dbl;
extern double gnd_dist;
extern double z_dist;
extern double dlat;
extern double dlon;
extern double haversin_dlat;
extern double haversin_dlon;
extern double a, c, d, az; 

/*                           Functions                            */
extern void setStationsLat(double newLat);
extern void setStationsLon(double newLon);
extern void setStationsAlt(double newAlt);
extern void setCosStationsLat(double newCosLat);
extern void decodePacket();
extern void displayInfo();
extern double azimuth(double lat2, double lon2);
extern double elevation(double lat2, double lon2, double alt);
extern double coord_dist(double lat2, double lon2);
extern double realDistance(double lat2, double lon2, double alt);

#endif
