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
LIBS:CommShield-cache
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
Text Label 3350 3300 0    60   ~ 0
BATT
Text Label 4800 3300 0    60   ~ 0
3.3V
Text Label 3150 3400 0    60   ~ 0
GND
Text Label 8400 2950 0    60   ~ 0
GND
Text Label 9000 3450 2    60   ~ 0
SDO
Text Label 9000 3350 2    60   ~ 0
SDI
Text Label 9000 3250 2    60   ~ 0
SCK
Text Label 9000 3150 2    60   ~ 0
NSEL
Text Label 9000 3050 2    60   ~ 0
NIRQ
Text Label 9000 2950 2    60   ~ 0
SDN
Text Label 8400 3350 0    60   ~ 0
GPIO_0
Text Label 8400 3450 0    60   ~ 0
GPIO_1
Text Label 8400 3550 0    60   ~ 0
GPIO_2
Text Label 8400 3150 0    60   ~ 0
RXON
Text Label 8400 3250 0    60   ~ 0
TXON
Text Label 9000 3550 2    60   ~ 0
GND
Text Label 7450 2100 0    60   ~ 0
GND
Text Label 8400 3050 0    60   ~ 0
Vin
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
P 3400 3500
F 0 "#PWR03" H 3400 3250 50  0001 C CNN
F 1 "GND" H 3400 3350 50  0000 C CNN
F 2 "" H 3400 3500 60  0000 C CNN
F 3 "" H 3400 3500 60  0000 C CNN
	1    3400 3500
	1    0    0    -1  
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
F 2 "Capacitors_SMD:C_0805" H 3738 3500 30  0001 C CNN
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
F 2 "Capacitors_SMD:C_0805" H 4938 3500 30  0001 C CNN
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
P 2950 3350
F 0 "P1" H 2950 3500 50  0000 C CNN
F 1 "CONN_01X02" V 3050 3350 50  0000 C CNN
F 2 "Connect:AK300-2" H 2950 3350 60  0001 C CNN
F 3 "" H 2950 3350 60  0000 C CNN
	1    2950 3350
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
L CONN_01X07 In_R1
U 1 1 564F8A95
P 9350 3250
F 0 "In_R1" H 9350 3650 50  0000 C CNN
F 1 "CONN_01X07" V 9450 3250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07" H 9350 3250 60  0001 C CNN
F 3 "" H 9350 3250 60  0000 C CNN
	1    9350 3250
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X07 In_L1
U 1 1 564F8AED
P 8000 3250
F 0 "In_L1" H 8000 3650 50  0000 C CNN
F 1 "CONN_01X07" V 8100 3250 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07" H 8000 3250 60  0001 C CNN
F 3 "" H 8000 3250 60  0000 C CNN
	1    8000 3250
	-1   0    0    -1  
$EndComp
$Comp
L AP1117D33 U1
U 1 1 5665DF75
P 4300 3300
F 0 "U1" H 4400 3050 50  0000 C CNN
F 1 "AP1117D33" H 4300 3550 50  0000 C CNN
F 2 "TO_SOT_Packages_SMD:TO-252-2Lead" H 4300 3300 50  0001 C CNN
F 3 "" H 4300 3300 50  0000 C CNN
	1    4300 3300
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X03 V_Sel1
U 1 1 5665E388
P 4750 2300
F 0 "V_Sel1" H 4750 2500 50  0000 C CNN
F 1 "CONN_01X03" V 4850 2300 50  0000 C CNN
F 2 "Socket_Strips:Socket_Strip_Straight_1x03" H 4750 2300 50  0001 C CNN
F 3 "" H 4750 2300 50  0000 C CNN
	1    4750 2300
	0    1    -1   0   
$EndComp
Text Label 4750 2600 0    60   ~ 0
Vin
Text Label 5100 2500 0    60   ~ 0
A3V3
$Comp
L CONN_01X02 A_jumper1
U 1 1 566F5E0D
P 4050 2200
F 0 "A_jumper1" H 4050 2350 50  0000 C CNN
F 1 "CONN_01X02" V 4150 2200 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x02" H 4050 2200 50  0001 C CNN
F 3 "" H 4050 2200 50  0000 C CNN
	1    4050 2200
	1    0    0    -1  
$EndComp
Text Label 3750 2150 2    60   ~ 0
ARD_VIN
Text Label 3750 2250 2    60   ~ 0
BATT
Text Label 5250 2900 2    60   ~ 0
ARD_VIN
Wire Wire Line
	3150 3300 4000 3300
Wire Wire Line
	4900 2750 4900 3500
Wire Wire Line
	4600 3300 4900 3300
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
Connection ~ 9100 2950
Wire Wire Line
	8250 3150 8250 3450
Connection ~ 8250 3450
Connection ~ 8250 3150
Wire Wire Line
	8350 3250 8350 3350
Connection ~ 8350 3350
Connection ~ 8350 3250
Wire Wire Line
	4900 2750 4650 2750
Wire Wire Line
	4650 2750 4650 2500
Connection ~ 4900 3300
Wire Wire Line
	4850 2500 5400 2500
Wire Wire Line
	4750 2500 4750 2600
Wire Wire Line
	9100 2500 9100 2950
Wire Wire Line
	7300 2500 9100 2500
Wire Wire Line
	3850 2150 3750 2150
Wire Wire Line
	3750 2250 3850 2250
Wire Wire Line
	3700 3300 3700 3500
Wire Wire Line
	5400 2900 5250 2900
Wire Wire Line
	3150 3400 3400 3400
Wire Wire Line
	3400 3400 3400 3500
$EndSCHEMATC