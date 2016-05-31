#ifndef RX_h
#define RX_h

#include <RHReliableDatagram.h>
#include <SPI.h>
#include <RH_RF22.h>

/*                          Parameters                         */
static const double stationsLat = -33.458155;
static const double stationsLng = -70.661971;
static const double stationsAlt = 557.0;
static const double deg2rad = 0.0174532925199433; //PI/180;
static const double rad2deg = 57.295779513082321; //180/PI;
static const double cos_stationsLat = 0.834289; //cos(stationsLat * deg2rad);
extern uint8_t hh;
extern uint8_t mm;
extern uint8_t ss;
extern uint8_t len;
extern uint8_t from;
extern uint8_t packet[27];
extern uint32_t sat;
extern int tmp;
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
extern void decodePacket();
extern void displayInfo();
extern double azimuth(double lat2, double lon2);
extern double elevation(double lat2, double lon2, double alt);
extern double coord_dist(double lat2, double lon2);
extern double realDistance(double lat2, double lon2, double alt);

#endif
