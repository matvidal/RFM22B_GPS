# RFM22B_GPS
This is a test using RFM22B and the L80 GPS. Given that both devices use a logic level of 3.3 V, they are both connected to an Arduino Due board. 

The purpose of this test is to determine which is the maximum distance that this transceiver can reach with uncorrupted data. In order to do that, a GPS is added to obtain at what distance the communication link is lost.

The test consists on using a radiosonde to transport one Arduino Due, one GPS L80 and one RFM22B acting as a transmiter. On the ground there will be three RFM22B with arduinos to receive the data from the GPS. One will use an omnidirectional antenna, another a personal Yagi antenna, and the third will be connected to the Earth Station of the Department of Electrical Engineering of Universidad de Chile.

## Code
In this folder you will find some tests you can run using the Radiohead library for the transceiver and the TinyGPS+ library for the GPS.

## Hardware
Here there are all the designs of the shields to plug the breakout board of the RFM22B to the Arduino Due, and the RFM23BP transciver to also an Arduino Due.
