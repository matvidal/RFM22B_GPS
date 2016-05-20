EESchema Schematic File Version 2
LIBS:freetronics_schematic
LIBS:power
LIBS:device
LIBS:transistors
LIBS:conn
LIBS:linear
LIBS:regul
LIBS:74xx
LIBS:cmos4000
LIBS:adc-dac
LIBS:memory
LIBS:xilinx
LIBS:microcontrollers
LIBS:dsp
LIBS:microchip
LIBS:analog_switches
LIBS:motorola
LIBS:texas
LIBS:intel
LIBS:audio
LIBS:interface
LIBS:digital-audio
LIBS:philips
LIBS:display
LIBS:cypress
LIBS:siliconi
LIBS:opto
LIBS:atmel
LIBS:contrib
LIBS:valves
LIBS:rfvtShield-cache
EELAYER 25 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title ""
Date "9 nov 2015"
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text Label 3150 3000 0    60   ~ 0
GND
Text Label 8400 2950 0    60   ~ 0
GND
Text Label 8400 3050 0    60   ~ 0
SDO
Text Label 8400 3150 0    60   ~ 0
SDI
Text Label 8400 3250 0    60   ~ 0
SCK
Text Label 8400 3350 0    60   ~ 0
NSEL
Text Label 8400 3450 0    60   ~ 0
NIRQ
Text Label 8400 3550 0    60   ~ 0
SDN
Text Label 9000 3150 2    60   ~ 0
GPIO_0
Text Label 9000 3050 2    60   ~ 0
GPIO_1
Text Label 9000 2950 2    60   ~ 0
GPIO_2
Text Label 9000 3350 2    60   ~ 0
RXON
Text Label 9000 3450 2    60   ~ 0
TXON
Text Label 9000 3550 2    60   ~ 0
GND
Text Label 7450 2100 0    60   ~ 0
GND
Text Label 9000 3250 2    60   ~ 0
TX_VIN
Text Label 7450 3200 0    60   ~ 0
NSEL
Text Label 7450 3400 0    60   ~ 0
NIRQ
Text Label 6100 1400 2    60   ~ 0
SCK
Text Label 7450 1400 0    60   ~ 0
SDI
Text Label 6100 1300 2    60   ~ 0
SDO
$Comp
L GND #PWR01
U 1 1 56424BFB
P 4900 3800
F 0 "#PWR01" H 4900 3550 50  0001 C CNN
F 1 "GND" H 4900 3650 50  0000 C CNN
F 2 "" H 4900 3800 60  0000 C CNN
F 3 "" H 4900 3800 60  0000 C CNN
	1    4900 3800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 56424C5E
P 3700 3800
F 0 "#PWR02" H 3700 3550 50  0001 C CNN
F 1 "GND" H 3700 3650 50  0000 C CNN
F 2 "" H 3700 3800 60  0000 C CNN
F 3 "" H 3700 3800 60  0000 C CNN
	1    3700 3800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR03
U 1 1 56424DC5
P 3350 3000
F 0 "#PWR03" H 3350 2750 50  0001 C CNN
F 1 "GND" H 3350 2850 50  0000 C CNN
F 2 "" H 3350 3000 60  0000 C CNN
F 3 "" H 3350 3000 60  0000 C CNN
	1    3350 3000
	0    -1   -1   0   
$EndComp
$Comp
L GND #PWR04
U 1 1 56424EC2
P 7450 2100
F 0 "#PWR04" H 7450 1850 50  0001 C CNN
F 1 "GND" H 7450 1950 50  0000 C CNN
F 2 "" H 7450 2100 60  0000 C CNN
F 3 "" H 7450 2100 60  0000 C CNN
	1    7450 2100
	1    0    0    -1  
$EndComp
$Comp
L C C1
U 1 1 564252EA
P 3700 3650
F 0 "C1" H 3725 3750 50  0000 L CNN
F 1 "C" H 3725 3550 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7_W2_P5" H 3738 3500 30  0001 C CNN
F 3 "" H 3700 3650 60  0000 C CNN
	1    3700 3650
	1    0    0    -1  
$EndComp
$Comp
L C C2
U 1 1 5642534C
P 4900 3650
F 0 "C2" H 4925 3750 50  0000 L CNN
F 1 "C" H 4925 3550 50  0000 L CNN
F 2 "Capacitors_ThroughHole:C_Rect_L7_W2_P5" H 4938 3500 30  0001 C CNN
F 3 "" H 4900 3650 60  0000 C CNN
	1    4900 3650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR05
U 1 1 5642563B
P 4300 3600
F 0 "#PWR05" H 4300 3350 50  0001 C CNN
F 1 "GND" H 4300 3450 50  0000 C CNN
F 2 "" H 4300 3600 60  0000 C CNN
F 3 "" H 4300 3600 60  0000 C CNN
	1    4300 3600
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X02 P1
U 1 1 5642590E
P 2950 3250
F 0 "P1" H 2950 3400 50  0000 C CNN
F 1 "CONN_01X02" V 3050 3250 50  0000 C CNN
F 2 "Connect:AK300-2" H 2950 3250 60  0001 C CNN
F 3 "" H 2950 3250 60  0000 C CNN
	1    2950 3250
	-1   0    0    -1  
$EndComp
$Comp
L ARDUINO_SHIELD SHIELD1
U 1 1 56452B21
P 6350 2800
F 0 "SHIELD1" H 5900 3950 60  0000 C CNN
F 1 "ARDUINO_SHIELD" H 6400 1850 60  0000 C CNN
F 2 "FT:ARDUINO_SHIELD" H 6350 2600 50  0001 C CNN
F 3 "" H 6350 2800 60  0000 C CNN
	1    6350 2800
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR06
U 1 1 56453535
P 5250 2700
F 0 "#PWR06" H 5250 2450 50  0001 C CNN
F 1 "GND" H 5250 2550 50  0000 C CNN
F 2 "" H 5250 2700 60  0000 C CNN
F 3 "" H 5250 2700 60  0000 C CNN
	1    5250 2700
	0    1    1    0   
$EndComp
Text Label 5250 2700 0    60   ~ 0
GND
$Comp
L 7805 U1
U 1 1 56561756
P 4300 3350
F 0 "U1" H 4450 3154 60  0000 C CNN
F 1 "7805" H 4300 3550 60  0000 C CNN
F 2 "TO_SOT_Packages_THT:TO-220_Neutral123_Vertical" H 4300 3350 60  0001 C CNN
F 3 "" H 4300 3350 60  0000 C CNN
	1    4300 3350
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 In_L1
U 1 1 56561BA3
P 8000 3300
F 0 "In_L1" H 8000 3750 50  0000 C CNN
F 1 "CONN_01X08" V 8100 3300 50  0000 C CNN
F 2 "Comm_lib:Pin_Header_1x08" H 8000 3300 60  0001 C CNN
F 3 "" H 8000 3300 60  0000 C CNN
	1    8000 3300
	-1   0    0    -1  
$EndComp
$Comp
L CONN_01X08 In_R1
U 1 1 56561C5C
P 9350 3300
F 0 "In_R1" H 9350 3750 50  0000 C CNN
F 1 "CONN_01X08" V 9450 3300 50  0000 C CNN
F 2 "Comm_lib:Pin_Header_1x08" H 9350 3300 60  0001 C CNN
F 3 "" H 9350 3300 60  0000 C CNN
	1    9350 3300
	1    0    0    -1  
$EndComp
Text Label 8400 3650 0    60   ~ 0
GND
Text Label 9000 3650 2    60   ~ 0
ANT
$Comp
L CONN_01X05 SMA1
U 1 1 56561FDD
P 9350 4150
F 0 "SMA1" H 9350 4450 50  0000 C CNN
F 1 "CONN_01X05" V 9450 4150 50  0000 C CNN
F 2 "Comm_lib:SMA" H 9350 4150 60  0001 C CNN
F 3 "" H 9350 4150 60  0000 C CNN
	1    9350 4150
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR07
U 1 1 565621E0
P 9100 4400
F 0 "#PWR07" H 9100 4150 50  0001 C CNN
F 1 "GND" H 9100 4250 50  0000 C CNN
F 2 "" H 9100 4400 60  0000 C CNN
F 3 "" H 9100 4400 60  0000 C CNN
	1    9100 4400
	1    0    0    -1  
$EndComp
Text Label 9100 4150 2    60   ~ 0
GND
Text Label 7450 3300 0    60   ~ 0
SDN
Text Label 4750 2300 0    60   ~ 0
TX_VIN
Text Label 4750 2500 0    60   ~ 0
ARD_5V
Text Label 4750 2100 0    60   ~ 0
REG
$Comp
L CONN_01X06 Jumper1
U 1 1 566F51FF
P 4450 2250
F 0 "Jumper1" H 4450 2600 50  0000 C CNN
F 1 "CONN_01X06" V 4550 2250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_2x03" H 4450 2250 50  0001 C CNN
F 3 "" H 4450 2250 50  0000 C CNN
	1    4450 2250
	-1   0    0    -1  
$EndComp
Text Label 4750 2400 0    60   ~ 0
ARD_VIN
Text Label 4750 2200 0    60   ~ 0
BATT
Text Label 4750 2000 0    60   ~ 0
NC
Text Label 5250 2600 2    60   ~ 0
ARD_5V
Text Label 4900 3300 0    60   ~ 0
REG
Wire Wire Line
	4900 3300 4900 3500
Wire Wire Line
	8200 2950 8400 2950
Wire Wire Line
	8200 3050 8400 3050
Wire Wire Line
	8200 3150 8400 3150
Wire Wire Line
	8200 3250 8400 3250
Wire Wire Line
	8200 3350 8400 3350
Wire Wire Line
	8200 3450 8400 3450
Wire Wire Line
	7300 2100 7450 2100
Wire Wire Line
	7300 3200 7450 3200
Wire Wire Line
	7300 3400 7450 3400
Wire Wire Line
	7300 1400 7450 1400
Wire Wire Line
	3150 3200 3150 3000
Wire Wire Line
	3150 3000 3350 3000
Wire Wire Line
	6250 1400 6100 1400
Wire Wire Line
	5400 2800 5400 2700
Wire Wire Line
	5400 2700 5250 2700
Wire Wire Line
	6250 1300 6100 1300
Wire Wire Line
	9150 3050 9000 3050
Wire Wire Line
	9150 3150 9000 3150
Wire Wire Line
	9150 3250 9000 3250
Wire Wire Line
	9150 3350 9000 3350
Wire Wire Line
	9150 3450 9000 3450
Wire Wire Line
	9150 3550 9000 3550
Connection ~ 3700 3300
Wire Wire Line
	9150 2950 9000 2950
Wire Wire Line
	8200 3550 8400 3550
Wire Wire Line
	3150 3300 3900 3300
Wire Wire Line
	4700 3300 4900 3300
Wire Wire Line
	8200 3650 8400 3650
Wire Wire Line
	9150 3650 9000 3650
Wire Wire Line
	9150 3950 9100 3950
Wire Wire Line
	9100 3950 9100 3650
Connection ~ 9100 3650
Wire Wire Line
	9150 4050 9100 4050
Wire Wire Line
	9100 4050 9100 4400
Wire Wire Line
	9100 4350 9150 4350
Wire Wire Line
	9150 4250 9100 4250
Connection ~ 9100 4250
Wire Wire Line
	9150 4150 9100 4150
Connection ~ 9100 4150
Connection ~ 9100 4350
Connection ~ 9100 3150
Connection ~ 9050 3050
Connection ~ 9050 3450
Connection ~ 9100 3350
Wire Wire Line
	9100 3150 9100 3350
Wire Wire Line
	9050 3450 9050 3050
Wire Wire Line
	7300 3300 7450 3300
Wire Wire Line
	4650 2400 4750 2400
Wire Wire Line
	4650 2000 4750 2000
Wire Wire Line
	4650 2100 4750 2100
Wire Wire Line
	4650 2200 4750 2200
Wire Wire Line
	5400 2600 5250 2600
Wire Wire Line
	4650 2300 4750 2300
Wire Wire Line
	4650 2500 4750 2500
Wire Wire Line
	3700 3500 3700 3300
Wire Wire Line
	5400 2900 5250 2900
Text Label 5250 2900 2    60   ~ 0
ARD_VIN
Text Label 3700 3300 2    60   ~ 0
BATT
$EndSCHEMATC
