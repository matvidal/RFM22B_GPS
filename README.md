# RFM22B_GPS
In this repository you can find multiple tests using the transceiver RFM22B and the L80 GPS. Given that both devices use a logic level of 3.3 V, they are both connected to an Arduino Due board. 

The echo test is used to try different combinations of bit rate and modulation at different distances and analize which combination permorms better. The purpose of the GPS test is to determine which is the maximum distance that this transceiver can reach with uncorrupted data using the best configuration obtained before. In order to do that, a GPS is added to obtain at what distance the communication link is lost.

The GPS test consists on using a radiosonde to transport one Arduino Due, one GPS L80 and one RFM22B acting as a transmiter. On the ground there will be three RFM22B with arduinos to receive the data from the GPS. One will use an omnidirectional antenna, another a personal Yagi antenna, and the third will be connected to the Earth Station of the Department of Electrical Engineering of Universidad de Chile.

## Code
In this folder you will find some tests you can run using the Radiohead library for the transceiver and the TinyGPS+ library for the GPS.

### Chat test
Two Arduinos are hooked up to two different computers. Using the serial monitor, two persons can write messages to each other and send them using the transceiver RFM22B.

### Normal test
One transceiver is the transmiter and the other the receiver. Random packets are sent continually from TX to RX. If there is no confirmation of the packet being received correctly by the RX, an error message is printed on screen.

### Echo test
In this test, one Arduino generates 1000 packets of random data and transmit it to another Arduino. Then, the receiver only retransmit the same packet to the TX. The TX compares the data generated and the packet received and evaluates if they are the same and use a counter to save the number of successes.
 
### GPS test

The transmiter with the microcontroler and the GPS is transported by a balloon with helium. It transmit the data adquired by the GPS to three different receivers.

## Doc
All the datasheets of the components used are in this folder. There is also an .ods file with the results of the radiosonde test.

## Hardware
Here there are all the designs of the shields to plug the breakout board of the RFM22B to the Arduino Due, the GPS with the TRX and the arduino and the RFM23BP transceiver to also an Arduino Due.
