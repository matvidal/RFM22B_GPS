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
LIBS:CommSensors-cache
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
Text Label 7950 2250 0    60   ~ 0
GND
Text Label 8550 2750 2    60   ~ 0
SDO
Text Label 8550 2650 2    60   ~ 0
SDI
Text Label 8550 2550 2    60   ~ 0
SCK
Text Label 8550 2450 2    60   ~ 0
NSEL
Text Label 8550 2350 2    60   ~ 0
NIRQ
Text Label 8550 2250 2    60   ~ 0
SDN
Text Label 7950 2650 0    60   ~ 0
GPIO_0
Text Label 7950 2750 0    60   ~ 0
GPIO_1
Text Label 7950 2850 0    60   ~ 0
GPIO_2
Text Label 7950 2450 0    60   ~ 0
RXON
Text Label 7950 2550 0    60   ~ 0
TXON
Text Label 8550 2850 2    60   ~ 0
GND
Text Label 7000 1600 0    60   ~ 0
GND
Text Label 7950 2350 0    60   ~ 0
3V3
Text Label 7000 2700 0    60   ~ 0
NSEL
Text Label 7000 2900 0    60   ~ 0
NIRQ
Text Label 5600 1000 2    60   ~ 0
SCK
Text Label 7000 1000 0    60   ~ 0
SDI
Text Label 5600 900  2    60   ~ 0
SDO
$Comp
L GND #PWR01
U 1 1 56424EC2
P 7000 1600
F 0 "#PWR01" H 7000 1350 50  0001 C CNN
F 1 "GND" H 7000 1450 50  0000 C CNN
F 2 "" H 7000 1600 60  0000 C CNN
F 3 "" H 7000 1600 60  0000 C CNN
	1    7000 1600
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR02
U 1 1 56453535
P 4800 2200
F 0 "#PWR02" H 4800 1950 50  0001 C CNN
F 1 "GND" H 4800 2050 50  0000 C CNN
F 2 "" H 4800 2200 60  0000 C CNN
F 3 "" H 4800 2200 60  0000 C CNN
	1    4800 2200
	0    1    1    0   
$EndComp
Text Label 4800 2200 0    60   ~ 0
GND
$Comp
L CONN_01X07 In_R1
U 1 1 564F8A95
P 8900 2550
F 0 "In_R1" H 8900 2950 50  0000 C CNN
F 1 "CONN_01X07" V 9000 2550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07" H 8900 2550 60  0001 C CNN
F 3 "" H 8900 2550 60  0000 C CNN
	1    8900 2550
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X07 In_L1
U 1 1 564F8AED
P 7550 2550
F 0 "In_L1" H 7550 2950 50  0000 C CNN
F 1 "CONN_01X07" V 7650 2550 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x07" H 7550 2550 60  0001 C CNN
F 3 "" H 7550 2550 60  0000 C CNN
	1    7550 2550
	-1   0    0    -1  
$EndComp
Text Label 4800 2000 2    60   ~ 0
3V3
$Comp
L ARDUINO_DUE_SHIELD CommSensors1
U 1 1 572FAF38
P 5950 3850
F 0 "CommSensors1" H 5550 6500 60  0000 C CNN
F 1 "ARDUINO_DUE_SHIELD" H 5950 3850 60  0000 C CNN
F 2 "FT:ARDUINO_DUE_SHIELD" H 5950 3650 50  0001 C CNN
F 3 "" H 5950 3850 60  0000 C CNN
	1    5950 3850
	1    0    0    -1  
$EndComp
$Comp
L CONN_01X08 GPS1
U 1 1 572FB51D
P 8900 3450
F 0 "GPS1" H 8900 3900 50  0000 C CNN
F 1 "CONN_01X08" V 9000 3450 50  0000 C CNN
F 2 "Pin_Headers:Pin_Header_Straight_1x08" H 8900 3450 50  0001 C CNN
F 3 "" H 8900 3450 50  0000 C CNN
	1    8900 3450
	1    0    0    -1  
$EndComp
Text Label 8600 3100 2    60   ~ 0
3V3
Text Label 8600 3200 2    60   ~ 0
V_B
Text Label 8600 3300 2    60   ~ 0
GND
Text Label 8600 3400 2    60   ~ 0
1PPS
Text Label 8600 3500 2    60   ~ 0
RX
Text Label 8600 3600 2    60   ~ 0
TX
Text Label 8600 3700 2    60   ~ 0
TM
Text Label 8600 3800 2    60   ~ 0
RST
Text Label 7000 1400 0    60   ~ 0
SDA1
Text Label 7000 1300 0    60   ~ 0
SCL1
Wire Wire Line
	7750 2250 7950 2250
Wire Wire Line
	7750 2350 7950 2350
Wire Wire Line
	7750 2450 7950 2450
Wire Wire Line
	7750 2550 7950 2550
Wire Wire Line
	7750 2650 7950 2650
Wire Wire Line
	7750 2750 7950 2750
Wire Wire Line
	6850 1600 7000 1600
Wire Wire Line
	6850 2700 7000 2700
Wire Wire Line
	6850 2900 7000 2900
Wire Wire Line
	4950 2300 4950 2200
Wire Wire Line
	4950 2200 4800 2200
Wire Wire Line
	8700 2350 8550 2350
Wire Wire Line
	8700 2450 8550 2450
Wire Wire Line
	8700 2550 8550 2550
Wire Wire Line
	8700 2650 8550 2650
Wire Wire Line
	8700 2750 8550 2750
Wire Wire Line
	8700 2850 8550 2850
Wire Wire Line
	8700 2250 8550 2250
Wire Wire Line
	7750 2850 7950 2850
Connection ~ 8650 2250
Wire Wire Line
	7800 2450 7800 2750
Connection ~ 7800 2750
Connection ~ 7800 2450
Wire Wire Line
	7900 2550 7900 2650
Connection ~ 7900 2650
Connection ~ 7900 2550
Wire Wire Line
	6850 2000 8650 2000
Wire Wire Line
	6850 1000 7000 1000
Wire Wire Line
	5750 1000 5600 1000
Wire Wire Line
	5600 900  5750 900 
Wire Wire Line
	8700 3100 8600 3100
Wire Wire Line
	8700 3200 8600 3200
Wire Wire Line
	8700 3300 8600 3300
Wire Wire Line
	8700 3400 8600 3400
Wire Wire Line
	6850 3500 8700 3500
Wire Wire Line
	6850 3600 8700 3600
Wire Wire Line
	8700 3700 8600 3700
Wire Wire Line
	8700 3800 8600 3800
Wire Wire Line
	6850 1400 7000 1400
Wire Wire Line
	6850 1300 7000 1300
Wire Wire Line
	4950 2000 4800 2000
Wire Wire Line
	8650 2000 8650 2250
$EndSCHEMATC
