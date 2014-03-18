EESchema Schematic File Version 2
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
LIBS:special
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
LIBS:Vinokuh-cache
LIBS:Vinokuh-cache
EELAYER 27 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 1 1
Title "Vinokuh"
Date "27 sep 2013"
Rev "0"
Comp "Rok Rupnik && Ozbolt Menegatti"
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L R R_T1b1
U 1 1 524322ED
P 4850 3500
F 0 "R_T1b1" V 4930 3500 40  0000 C CNN
F 1 "R" V 4857 3501 40  0000 C CNN
F 2 "~" V 4780 3500 30  0000 C CNN
F 3 "~" H 4850 3500 30  0000 C CNN
	1    4850 3500
	0    -1   -1   0   
$EndComp
$Comp
L R R_T1a1
U 1 1 524322EE
P 4600 3250
F 0 "R_T1a1" V 4680 3250 40  0000 C CNN
F 1 "R" V 4607 3251 40  0000 C CNN
F 2 "~" V 4530 3250 30  0000 C CNN
F 3 "~" H 4600 3250 30  0000 C CNN
	1    4600 3250
	1    0    0    -1  
$EndComp
$Comp
L R R_RED8
U 1 1 524322F8
P 9400 6650
F 0 "R_RED8" V 9480 6650 40  0000 C CNN
F 1 "R" V 9407 6651 40  0000 C CNN
F 2 "~" V 9330 6650 30  0000 C CNN
F 3 "~" H 9400 6650 30  0000 C CNN
	1    9400 6650
	0    -1   -1   0   
$EndComp
$Comp
L R R_RED4
U 1 1 524322F9
P 8300 6650
F 0 "R_RED4" V 8380 6650 40  0000 C CNN
F 1 "R" V 8307 6651 40  0000 C CNN
F 2 "~" V 8230 6650 30  0000 C CNN
F 3 "~" H 8300 6650 30  0000 C CNN
	1    8300 6650
	0    -1   -1   0   
$EndComp
$Comp
L R R_RED3
U 1 1 524322FA
P 8300 6400
F 0 "R_RED3" V 8380 6400 40  0000 C CNN
F 1 "R" V 8307 6401 40  0000 C CNN
F 2 "~" V 8230 6400 30  0000 C CNN
F 3 "~" H 8300 6400 30  0000 C CNN
	1    8300 6400
	0    -1   -1   0   
$EndComp
$Comp
L R R_RED6
U 1 1 524322FB
P 9400 6150
F 0 "R_RED6" V 9480 6150 40  0000 C CNN
F 1 "R" V 9407 6151 40  0000 C CNN
F 2 "~" V 9330 6150 30  0000 C CNN
F 3 "~" H 9400 6150 30  0000 C CNN
	1    9400 6150
	0    -1   -1   0   
$EndComp
$Comp
L R R_RED5
U 1 1 524322FC
P 9400 5900
F 0 "R_RED5" V 9480 5900 40  0000 C CNN
F 1 "R" V 9407 5901 40  0000 C CNN
F 2 "~" V 9330 5900 30  0000 C CNN
F 3 "~" H 9400 5900 30  0000 C CNN
	1    9400 5900
	0    -1   -1   0   
$EndComp
$Comp
L R R_RED2
U 1 1 524322FD
P 8300 6150
F 0 "R_RED2" V 8380 6150 40  0000 C CNN
F 1 "R" V 8307 6151 40  0000 C CNN
F 2 "~" V 8230 6150 30  0000 C CNN
F 3 "~" H 8300 6150 30  0000 C CNN
	1    8300 6150
	0    -1   -1   0   
$EndComp
$Comp
L R R_RED1
U 1 1 524322FE
P 8300 5900
F 0 "R_RED1" V 8380 5900 40  0000 C CNN
F 1 "R" V 8307 5901 40  0000 C CNN
F 2 "~" V 8230 5900 30  0000 C CNN
F 3 "~" H 8300 5900 30  0000 C CNN
	1    8300 5900
	0    -1   -1   0   
$EndComp
$Comp
L 7805 DCDC1
U 1 1 52432307
P 2350 5100
F 0 "DCDC1" H 2500 4904 60  0001 C CNN
F 1 "7805" H 2350 5300 60  0000 C CNN
F 2 "~" H 2350 5100 60  0000 C CNN
F 3 "~" H 2350 5100 60  0000 C CNN
	1    2350 5100
	1    0    0    -1  
$EndComp
Text Label 9200 1300 0    40   ~ 0
5V
NoConn ~ 2700 1400
NoConn ~ 2450 3500
Text Label 2650 1200 2    39   ~ 8
GND
Text Label 2650 1400 2    39   ~ 8
NRST
Text Label 2650 1500 2    39   ~ 8
PC0
Text Label 2650 1600 2    39   ~ 8
PC2
Text Label 2650 1700 2    39   ~ 8
PA0
Text Label 2650 1800 2    39   ~ 8
PA2
Text Label 2650 1900 2    39   ~ 8
PA4
Text Label 2650 2000 2    39   ~ 8
PA6
Text Label 2650 2100 2    39   ~ 8
PC4
Text Label 2650 2200 2    39   ~ 8
PB0
Text Label 2650 2300 2    39   ~ 8
PB2
Text Label 2650 2400 2    39   ~ 8
PE8
Text Label 2650 2500 2    39   ~ 8
PE10
Text Label 2650 2600 2    39   ~ 8
PE12
Text Label 2650 2700 2    39   ~ 8
PE14
Text Label 2650 2800 2    39   ~ 8
PB10
Text Label 2650 2900 2    39   ~ 8
PB12
Text Label 2650 3000 2    39   ~ 8
PB14
Text Label 2650 3100 2    39   ~ 8
PD8
Text Label 2650 3200 2    39   ~ 8
PD10
Text Label 2650 3300 2    39   ~ 8
PD12
Text Label 2650 3400 2    39   ~ 8
PD14
Text Label 2650 3600 2    39   ~ 8
GND
Text Label 9200 1400 0    40   ~ 0
3V
Text Label 9200 1500 0    40   ~ 0
PH0
Text Label 9200 1600 0    40   ~ 0
PC14
Text Label 9200 1700 0    40   ~ 0
PE6
Text Label 9200 1800 0    40   ~ 0
PE4
Text Label 9200 1900 0    40   ~ 0
PE2
Text Label 9200 2000 0    40   ~ 0
PE0
Text Label 9200 2100 0    40   ~ 0
PB8
Text Label 9200 2300 0    40   ~ 0
PB6
Text Label 9200 2400 0    40   ~ 0
PB4
Text Label 9200 2500 0    40   ~ 0
PD7
Text Label 9200 2600 0    40   ~ 0
PD5
Text Label 9200 2700 0    40   ~ 0
PD3
Text Label 9200 2800 0    40   ~ 0
PD1
Text Label 9200 2900 0    40   ~ 0
PC12
Text Label 9200 3000 0    40   ~ 0
PC10
Text Label 9200 3100 0    40   ~ 0
PA14
Text Label 9200 3200 0    40   ~ 0
PA10
Text Label 9200 3300 0    40   ~ 0
PA8
Text Label 9200 3400 0    40   ~ 0
PC8
Text Label 9200 3500 0    40   ~ 0
PC6
Text Label 9200 3600 0    40   ~ 0
GND
Text Label 9200 1200 0    40   ~ 0
GND
$Comp
L CONN_25X2 DSC_D1
U 1 1 5243289E
P 9800 2400
F 0 "DSC_D1" H 9800 3700 60  0001 C CNN
F 1 "DISCOVERY DESNA" V 9800 2400 50  0000 C CNN
F 2 "" H 9800 2400 60  0000 C CNN
F 3 "" H 9800 2400 60  0000 C CNN
	1    9800 2400
	1    0    0    -1  
$EndComp
NoConn ~ 1400 3500
Text Label 1450 1200 0    39   ~ 8
GND
Text Label 1450 1400 0    39   ~ 8
GND
Text Label 1450 1500 0    39   ~ 8
PC1
Text Label 1450 1600 0    39   ~ 8
PC3
Text Label 1450 1700 0    39   ~ 8
PA1
Text Label 1450 1800 0    39   ~ 8
PA3
Text Label 1450 1900 0    39   ~ 8
PA5
Text Label 1450 2000 0    39   ~ 8
PA7
Text Label 1450 2100 0    39   ~ 8
PC5
Text Label 1450 2200 0    39   ~ 8
PB1
Text Label 1450 2300 0    39   ~ 8
GND
Text Label 1450 2400 0    39   ~ 8
PE7
Text Label 1450 2500 0    39   ~ 8
PE9
Text Label 1450 2600 0    39   ~ 8
PE11
Text Label 1450 2700 0    39   ~ 8
PE13
Text Label 1450 2800 0    39   ~ 8
PE15
Text Label 1450 2900 0    39   ~ 8
PB11
Text Label 1450 3000 0    39   ~ 8
PB13
Text Label 1450 3100 0    39   ~ 8
PB15
Text Label 1450 3200 0    39   ~ 8
PD9
Text Label 1450 3300 0    39   ~ 8
PD11
Text Label 1450 3400 0    39   ~ 8
PD13
Text Label 1450 3500 0    39   ~ 8
PD15
Text Label 1450 3600 0    39   ~ 8
GND
NoConn ~ 1650 1300
NoConn ~ 2450 1300
$Comp
L GND #PWR3
U 1 1 52432CC3
P 2350 5400
F 0 "#PWR3" H 2350 5400 30  0001 C CNN
F 1 "GND" H 2350 5330 30  0001 C CNN
F 2 "" H 2350 5400 60  0000 C CNN
F 3 "" H 2350 5400 60  0000 C CNN
	1    2350 5400
	-1   0    0    -1  
$EndComp
Text Label 10400 1200 2    39   ~ 8
GND
Text Label 10400 1400 2    39   ~ 8
3V
Text Label 10400 1500 2    39   ~ 8
PH1
Text Label 10400 1600 2    39   ~ 8
PC15
Text Label 10400 1700 2    39   ~ 8
PC13
Text Label 10400 1800 2    39   ~ 8
PE5
Text Label 10400 1900 2    39   ~ 8
PE3
Text Label 10400 2000 2    39   ~ 8
PE1
Text Label 10400 2100 2    39   ~ 8
PB9
Text Label 10400 2300 2    39   ~ 8
PB7
Text Label 10400 2400 2    39   ~ 8
PB5
Text Label 10400 2500 2    39   ~ 8
PB3
Text Label 10400 2600 2    39   ~ 8
PD6
Text Label 10400 2700 2    39   ~ 8
PD4
Text Label 10400 2800 2    39   ~ 8
PD2
Text Label 10400 2900 2    39   ~ 8
PD0
Text Label 10400 3000 2    39   ~ 8
PC11
Text Label 10400 3100 2    39   ~ 8
PA15
Text Label 10400 3200 2    39   ~ 8
PA13
Text Label 10400 3300 2    39   ~ 8
PA9
Text Label 10400 3400 2    39   ~ 8
PC9
Text Label 10400 3500 2    39   ~ 8
PC7
Text Label 10400 3600 2    39   ~ 8
GND
Text Label 10400 1300 2    39   ~ 8
5V
NoConn ~ 9400 2200
NoConn ~ 10200 2200
$Comp
L DIODESCH D_REL1
U 1 1 52433174
P 5200 2100
F 0 "D_REL1" H 5200 2200 40  0000 C CNN
F 1 "DIODESCH" H 5200 2000 40  0001 C CNN
F 2 "~" H 5200 2100 60  0000 C CNN
F 3 "~" H 5200 2100 60  0000 C CNN
	1    5200 2100
	-1   0    0    1   
$EndComp
$Comp
L MOSFET_N REL2
U 1 1 524331B0
P 5200 1200
F 0 "REL2" H 5200 1400 60  0000 R CNN
F 1 "MOSFET_N" H 5210 1050 60  0001 R CNN
F 2 "~" H 5200 1200 60  0000 C CNN
F 3 "~" H 5200 1200 60  0000 C CNN
	1    5200 1200
	0    -1   1    0   
$EndComp
$Comp
L CONN_20 OUT_HOR1
U 1 1 524331BF
P 2050 7000
F 0 "OUT_HOR1" V 2000 7000 60  0001 C CNN
F 1 "Horizontalna letvica" V 2100 7000 60  0000 C CNN
F 2 "" H 2050 7000 60  0000 C CNN
F 3 "" H 2050 7000 60  0000 C CNN
F 4 "Zaslon in encoder direct out" V 2050 7000 60  0001 C CNN "Comment"
	1    2050 7000
	0    1    1    0   
$EndComp
$Comp
L R R_B1
U 1 1 5243357A
P 7700 1650
F 0 "R_B1" V 7780 1650 40  0000 C CNN
F 1 "R" V 7707 1651 40  0000 C CNN
F 2 "~" V 7630 1650 30  0000 C CNN
F 3 "~" H 7700 1650 30  0000 C CNN
	1    7700 1650
	0    -1   -1   0   
$EndComp
$Comp
L R R_BE1
U 1 1 52433580
P 7700 1300
F 0 "R_BE1" V 7780 1300 40  0000 C CNN
F 1 "R" V 7707 1301 40  0000 C CNN
F 2 "~" V 7630 1300 30  0000 C CNN
F 3 "~" H 7700 1300 30  0000 C CNN
	1    7700 1300
	0    -1   -1   0   
$EndComp
$Comp
L R R_B2
U 1 1 52433586
P 7700 2000
F 0 "R_B2" V 7780 2000 40  0000 C CNN
F 1 "R" V 7707 2001 40  0000 C CNN
F 2 "~" V 7630 2000 30  0000 C CNN
F 3 "~" H 7700 2000 30  0000 C CNN
	1    7700 2000
	0    -1   -1   0   
$EndComp
Text Notes 7450 1100 0    60   ~ 12
Knofi
Text Notes 8500 5650 0    60   ~ 12
ArrayLEDic
Text Notes 4550 2750 0    60   ~ 12
Uporovni delilniki za termistorje
$Comp
L CONN_30 OUT_VER1
U 1 1 524338C0
P 5350 7000
F 0 "OUT_VER1" V 5301 7000 60  0001 C CNN
F 1 "Vertikalna letvica" V 5400 7000 60  0000 C CNN
F 2 "" H 5350 7000 60  0000 C CNN
F 3 "" H 5350 7000 60  0000 C CNN
	1    5350 7000
	0    1    1    0   
$EndComp
$Comp
L CONN_25X2 DSC_L1
U 1 1 524328AD
P 2050 2400
F 0 "DSC_L1" H 2050 3700 60  0001 C CNN
F 1 "DISCOVERY LEVA" V 2050 2400 50  0000 C CNN
F 2 "" H 2050 2400 60  0000 C CNN
F 3 "" H 2050 2400 60  0000 C CNN
	1    2050 2400
	1    0    0    -1  
$EndComp
$Comp
L DIODESCH D_REL2
U 1 1 52433165
P 5200 1450
F 0 "D_REL2" H 5200 1550 40  0000 C CNN
F 1 "DIODESCH" H 5200 1350 40  0001 C CNN
F 2 "~" H 5200 1450 60  0000 C CNN
F 3 "~" H 5200 1450 60  0000 C CNN
	1    5200 1450
	-1   0    0    1   
$EndComp
Text Notes 7500 2750 0    60   ~ 12
Encoder
$Comp
L R R_RED7
U 1 1 52433CA9
P 9400 6400
F 0 "R_RED7" V 9480 6400 40  0000 C CNN
F 1 "R" V 9407 6401 40  0000 C CNN
F 2 "~" V 9330 6400 30  0000 C CNN
F 3 "~" H 9400 6400 30  0000 C CNN
	1    9400 6400
	0    -1   -1   0   
$EndComp
$Comp
L MOSFET_N REL1
U 1 1 524331A1
P 5200 1850
F 0 "REL1" H 5250 1600 60  0000 R CNN
F 1 "MOSFET_N" V 4950 2050 60  0001 R CNN
F 2 "~" H 5200 1850 60  0000 C CNN
F 3 "~" H 5200 1850 60  0000 C CNN
	1    5200 1850
	0    -1   1    0   
$EndComp
$Comp
L GND #PWR9
U 1 1 52434A5A
P 5400 1550
F 0 "#PWR9" H 5400 1550 30  0001 C CNN
F 1 "GND" H 5400 1480 30  0001 C CNN
F 2 "" H 5400 1550 60  0000 C CNN
F 3 "" H 5400 1550 60  0000 C CNN
	1    5400 1550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR10
U 1 1 52434A69
P 5400 2200
F 0 "#PWR10" H 5400 2200 30  0001 C CNN
F 1 "GND" H 5400 2130 30  0001 C CNN
F 2 "" H 5400 2200 60  0000 C CNN
F 3 "" H 5400 2200 60  0000 C CNN
	1    5400 2200
	1    0    0    -1  
$EndComp
Text Label 1100 6550 1    39   ~ 8
H20
Text Label 1200 6550 1    39   ~ 8
H19
Text Label 1300 6550 1    39   ~ 8
H18
Text Label 1400 6550 1    39   ~ 8
H17
Text Label 1500 6550 1    39   ~ 8
H16
Text Label 1600 6550 1    39   ~ 8
H15
Text Label 1700 6550 1    39   ~ 8
H14
Text Label 1800 6550 1    39   ~ 8
H13
Text Label 1900 6550 1    39   ~ 8
H12
Text Label 2000 6550 1    39   ~ 8
H11
Text Label 2100 6550 1    39   ~ 8
H10
Text Label 2200 6550 1    39   ~ 8
H9
Text Label 3900 6550 1    39   ~ 8
V30
Text Label 4000 6550 1    39   ~ 8
V29
Text Label 4100 6550 1    39   ~ 8
V28
Text Label 4200 6550 1    39   ~ 8
V27
Text Label 4300 6550 1    39   ~ 8
V26
Text Label 4400 6550 1    39   ~ 8
V25
Text Label 4500 6550 1    39   ~ 8
V24
Text Label 4600 6550 1    39   ~ 8
V23
Text Label 4700 6550 1    39   ~ 8
V22
Text Label 4800 6550 1    39   ~ 8
V21
Text Label 4900 6550 1    39   ~ 8
V20
Text Label 5000 6550 1    39   ~ 8
V19
Text Label 5100 6550 1    39   ~ 8
V18
Text Label 5200 6550 1    39   ~ 8
V17
Text Label 5300 6550 1    39   ~ 8
V16
Text Label 5400 6550 1    39   ~ 8
V15
Text Label 5500 6550 1    39   ~ 8
V14
Text Label 5600 6550 1    39   ~ 8
V13
Text Label 5700 6550 1    39   ~ 8
V12
Text Label 5800 6550 1    39   ~ 8
V11
Text Label 5900 6550 1    39   ~ 8
V10
Text Label 6000 6550 1    39   ~ 8
V9
Text Label 6100 6550 1    39   ~ 8
V8
Text Label 6200 6550 1    39   ~ 8
V7
Text Label 6300 6550 1    39   ~ 8
V6
Text Label 6400 6550 1    39   ~ 8
V5
Text Label 6500 6550 1    39   ~ 8
V4
Text Label 6600 6550 1    39   ~ 8
V3
Text Label 6700 6550 1    39   ~ 8
V2
Text Label 6800 6550 1    39   ~ 8
V1
Text Label 2300 6550 1    39   ~ 8
H8
Text Label 2400 6550 1    39   ~ 8
H7
Text Label 2500 6550 1    39   ~ 8
H6
Text Label 2600 6550 1    39   ~ 8
H5
Text Label 2700 6550 1    39   ~ 8
H4
Text Label 2800 6550 1    39   ~ 8
H3
Text Label 2900 6550 1    39   ~ 8
H2
Text Label 3000 6550 1    39   ~ 8
H1
Text Label 4750 1450 0    39   ~ 8
H?
Text Label 4750 1600 0    39   ~ 8
H?
Text Label 5700 1500 0    39   ~ 8
P?
Text Label 5700 1650 0    39   ~ 8
P?
$Comp
L CONN_2 12V1
U 1 1 52435705
P 1300 5150
F 0 "12V1" V 1250 5150 40  0000 C CNN
F 1 "Adapter" V 1350 5150 40  0000 C CNN
F 2 "" H 1300 5150 60  0000 C CNN
F 3 "" H 1300 5150 60  0000 C CNN
	1    1300 5150
	-1   0    0    1   
$EndComp
$Comp
L +12V #PWR1
U 1 1 52435714
P 1650 4950
F 0 "#PWR1" H 1650 4900 20  0001 C CNN
F 1 "+12V" H 1650 5050 30  0000 C CNN
F 2 "" H 1650 4950 60  0000 C CNN
F 3 "" H 1650 4950 60  0000 C CNN
	1    1650 4950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR2
U 1 1 524357F4
P 1750 5400
F 0 "#PWR2" H 1750 5400 30  0001 C CNN
F 1 "GND" H 1750 5330 30  0001 C CNN
F 2 "" H 1750 5400 60  0000 C CNN
F 3 "" H 1750 5400 60  0000 C CNN
	1    1750 5400
	-1   0    0    -1  
$EndComp
Text Label 2800 5050 0    39   ~ 8
5V
Text Label 1750 5050 0    39   ~ 8
12V
Text Label 7900 5900 0    39   ~ 8
P?
Text Label 7900 6150 0    39   ~ 8
P?
Text Label 7900 6400 0    39   ~ 8
P?
Text Label 7900 6650 0    39   ~ 8
P?
Text Label 9000 6650 0    39   ~ 8
P?
Text Label 9000 6400 0    39   ~ 8
P?
Text Label 9000 6150 0    39   ~ 8
P?
Text Label 9000 5900 0    39   ~ 8
P?
Text Label 8650 5900 0    39   ~ 8
V?
Text Label 8650 6150 0    39   ~ 8
V?
Text Label 8650 6400 0    39   ~ 8
V?
Text Label 8650 6650 0    39   ~ 8
V?
Text Label 9750 6650 0    39   ~ 8
V?
Text Label 9750 6400 0    39   ~ 8
V?
Text Label 9750 6150 0    39   ~ 8
V?
Text Label 9750 5900 0    39   ~ 8
V?
$Comp
L R R_GREEN8
U 1 1 52436514
P 9350 5100
F 0 "R_GREEN8" V 9430 5100 40  0000 C CNN
F 1 "R" V 9357 5101 40  0000 C CNN
F 2 "~" V 9280 5100 30  0000 C CNN
F 3 "~" H 9350 5100 30  0000 C CNN
	1    9350 5100
	0    -1   -1   0   
$EndComp
$Comp
L R R_GREEN4
U 1 1 5243651A
P 8250 5100
F 0 "R_GREEN4" V 8330 5100 40  0000 C CNN
F 1 "R" V 8257 5101 40  0000 C CNN
F 2 "~" V 8180 5100 30  0000 C CNN
F 3 "~" H 8250 5100 30  0000 C CNN
	1    8250 5100
	0    -1   -1   0   
$EndComp
$Comp
L R R_GREEN3
U 1 1 52436520
P 8250 4850
F 0 "R_GREEN3" V 8330 4850 40  0000 C CNN
F 1 "R" V 8257 4851 40  0000 C CNN
F 2 "~" V 8180 4850 30  0000 C CNN
F 3 "~" H 8250 4850 30  0000 C CNN
	1    8250 4850
	0    -1   -1   0   
$EndComp
$Comp
L R R_GREEN6
U 1 1 52436526
P 9350 4600
F 0 "R_GREEN6" V 9430 4600 40  0000 C CNN
F 1 "R" V 9357 4601 40  0000 C CNN
F 2 "~" V 9280 4600 30  0000 C CNN
F 3 "~" H 9350 4600 30  0000 C CNN
	1    9350 4600
	0    -1   -1   0   
$EndComp
$Comp
L R R_GREEN5
U 1 1 5243652C
P 9350 4350
F 0 "R_GREEN5" V 9430 4350 40  0000 C CNN
F 1 "R" V 9357 4351 40  0000 C CNN
F 2 "~" V 9280 4350 30  0000 C CNN
F 3 "~" H 9350 4350 30  0000 C CNN
	1    9350 4350
	0    -1   -1   0   
$EndComp
$Comp
L R R_GREEN2
U 1 1 52436532
P 8250 4600
F 0 "R_GREEN2" V 8330 4600 40  0000 C CNN
F 1 "R" V 8257 4601 40  0000 C CNN
F 2 "~" V 8180 4600 30  0000 C CNN
F 3 "~" H 8250 4600 30  0000 C CNN
	1    8250 4600
	0    -1   -1   0   
$EndComp
$Comp
L R R_GREEN1
U 1 1 52436538
P 8250 4350
F 0 "R_GREEN1" V 8330 4350 40  0000 C CNN
F 1 "R" V 8257 4351 40  0000 C CNN
F 2 "~" V 8180 4350 30  0000 C CNN
F 3 "~" H 8250 4350 30  0000 C CNN
	1    8250 4350
	0    -1   -1   0   
$EndComp
Text Notes 8450 4100 0    60   ~ 12
ArrayLEDic
$Comp
L R R_GREEN7
U 1 1 52436540
P 9350 4850
F 0 "R_GREEN7" V 9430 4850 40  0000 C CNN
F 1 "R" V 9357 4851 40  0000 C CNN
F 2 "~" V 9280 4850 30  0000 C CNN
F 3 "~" H 9350 4850 30  0000 C CNN
	1    9350 4850
	0    -1   -1   0   
$EndComp
Text Label 7850 4350 0    39   ~ 8
P?
Text Label 7850 4600 0    39   ~ 8
P?
Text Label 7850 4850 0    39   ~ 8
P?
Text Label 7850 5100 0    39   ~ 8
P?
Text Label 8950 5100 0    39   ~ 8
P?
Text Label 8950 4850 0    39   ~ 8
P?
Text Label 8950 4600 0    39   ~ 8
P?
Text Label 8950 4350 0    39   ~ 8
P?
Text Label 8600 4350 0    39   ~ 8
V?
Text Label 8600 4600 0    39   ~ 8
V?
Text Label 8600 4850 0    39   ~ 8
V?
Text Label 8600 5100 0    39   ~ 8
V?
Text Label 9700 5100 0    39   ~ 8
V?
Text Label 9700 4850 0    39   ~ 8
V?
Text Label 9700 4600 0    39   ~ 8
V?
Text Label 9700 4350 0    39   ~ 8
V?
$Comp
L R R_T2b1
U 1 1 524366BA
P 4850 4200
F 0 "R_T2b1" V 4930 4200 40  0000 C CNN
F 1 "R" V 4857 4201 40  0000 C CNN
F 2 "~" V 4780 4200 30  0000 C CNN
F 3 "~" H 4850 4200 30  0000 C CNN
	1    4850 4200
	0    -1   -1   0   
$EndComp
$Comp
L R R_T2a1
U 1 1 524366C0
P 4600 3950
F 0 "R_T2a1" V 4680 3950 40  0000 C CNN
F 1 "R" V 4607 3951 40  0000 C CNN
F 2 "~" V 4530 3950 30  0000 C CNN
F 3 "~" H 4600 3950 30  0000 C CNN
	1    4600 3950
	1    0    0    -1  
$EndComp
$Comp
L R R_T3b1
U 1 1 524366C6
P 4850 4900
F 0 "R_T3b1" V 4930 4900 40  0000 C CNN
F 1 "R" V 4857 4901 40  0000 C CNN
F 2 "~" V 4780 4900 30  0000 C CNN
F 3 "~" H 4850 4900 30  0000 C CNN
	1    4850 4900
	0    -1   -1   0   
$EndComp
$Comp
L R R_T3a1
U 1 1 524366CC
P 4600 4650
F 0 "R_T3a1" V 4680 4650 40  0000 C CNN
F 1 "R" V 4607 4651 40  0000 C CNN
F 2 "~" V 4530 4650 30  0000 C CNN
F 3 "~" H 4600 4650 30  0000 C CNN
	1    4600 4650
	1    0    0    -1  
$EndComp
$Comp
L R R_T4b1
U 1 1 524366D2
P 4850 5600
F 0 "R_T4b1" V 4930 5600 40  0000 C CNN
F 1 "R" V 4857 5601 40  0000 C CNN
F 2 "~" V 4780 5600 30  0000 C CNN
F 3 "~" H 4850 5600 30  0000 C CNN
	1    4850 5600
	0    -1   -1   0   
$EndComp
$Comp
L R R_T4a1
U 1 1 524366D8
P 4600 5350
F 0 "R_T4a1" V 4680 5350 40  0000 C CNN
F 1 "R" V 4607 5351 40  0000 C CNN
F 2 "~" V 4530 5350 30  0000 C CNN
F 3 "~" H 4600 5350 30  0000 C CNN
	1    4600 5350
	1    0    0    -1  
$EndComp
$Comp
L R R_T5b1
U 1 1 524366DE
P 5800 3500
F 0 "R_T5b1" V 5880 3500 40  0000 C CNN
F 1 "R" V 5807 3501 40  0000 C CNN
F 2 "~" V 5730 3500 30  0000 C CNN
F 3 "~" H 5800 3500 30  0000 C CNN
	1    5800 3500
	0    -1   -1   0   
$EndComp
$Comp
L R R_T5a1
U 1 1 524366E4
P 5550 3250
F 0 "R_T5a1" V 5630 3250 40  0000 C CNN
F 1 "R" V 5557 3251 40  0000 C CNN
F 2 "~" V 5480 3250 30  0000 C CNN
F 3 "~" H 5550 3250 30  0000 C CNN
	1    5550 3250
	1    0    0    -1  
$EndComp
$Comp
L R R_T6b1
U 1 1 524366EA
P 5800 4200
F 0 "R_T6b1" V 5880 4200 40  0000 C CNN
F 1 "R" V 5807 4201 40  0000 C CNN
F 2 "~" V 5730 4200 30  0000 C CNN
F 3 "~" H 5800 4200 30  0000 C CNN
	1    5800 4200
	0    -1   -1   0   
$EndComp
$Comp
L R R_T6a1
U 1 1 524366F0
P 5550 3950
F 0 "R_T6a1" V 5630 3950 40  0000 C CNN
F 1 "R" V 5557 3951 40  0000 C CNN
F 2 "~" V 5480 3950 30  0000 C CNN
F 3 "~" H 5550 3950 30  0000 C CNN
	1    5550 3950
	1    0    0    -1  
$EndComp
$Comp
L R R_T7b1
U 1 1 524366F6
P 5800 4900
F 0 "R_T7b1" V 5880 4900 40  0000 C CNN
F 1 "R" V 5807 4901 40  0000 C CNN
F 2 "~" V 5730 4900 30  0000 C CNN
F 3 "~" H 5800 4900 30  0000 C CNN
	1    5800 4900
	0    -1   -1   0   
$EndComp
$Comp
L R R_T7a1
U 1 1 524366FC
P 5550 4650
F 0 "R_T7a1" V 5630 4650 40  0000 C CNN
F 1 "R" V 5557 4651 40  0000 C CNN
F 2 "~" V 5480 4650 30  0000 C CNN
F 3 "~" H 5550 4650 30  0000 C CNN
	1    5550 4650
	1    0    0    -1  
$EndComp
$Comp
L R R_T8b1
U 1 1 52436702
P 5800 5600
F 0 "R_T8b1" V 5880 5600 40  0000 C CNN
F 1 "R" V 5807 5601 40  0000 C CNN
F 2 "~" V 5730 5600 30  0000 C CNN
F 3 "~" H 5800 5600 30  0000 C CNN
	1    5800 5600
	0    -1   -1   0   
$EndComp
$Comp
L R R_T8a1
U 1 1 52436708
P 5550 5350
F 0 "R_T8a1" V 5630 5350 40  0000 C CNN
F 1 "R" V 5557 5351 40  0000 C CNN
F 2 "~" V 5480 5350 30  0000 C CNN
F 3 "~" H 5550 5350 30  0000 C CNN
	1    5550 5350
	1    0    0    -1  
$EndComp
Text Label 4700 3000 0    39   ~ 8
H?
Text Label 4450 3500 0    39   ~ 8
P?
Text Label 4450 4200 0    39   ~ 8
P?
Text Label 4450 4900 0    39   ~ 8
P?
Text Label 4450 5600 0    39   ~ 8
P?
Text Label 5400 3500 0    39   ~ 8
P?
Text Label 5400 4200 0    39   ~ 8
P?
Text Label 5400 4900 0    39   ~ 8
P?
Text Label 5400 5600 0    39   ~ 8
P?
Text Label 4700 3700 0    39   ~ 8
H?
Text Label 4700 4400 0    39   ~ 8
H?
Text Label 4700 5100 0    39   ~ 8
H?
Text Label 5650 5100 0    39   ~ 8
H?
Text Label 5650 4400 0    39   ~ 8
H?
Text Label 5650 3700 0    39   ~ 8
H?
Text Label 5650 3000 0    39   ~ 8
H?
$Comp
L GND #PWR5
U 1 1 52436BF2
P 5150 3550
F 0 "#PWR5" H 5150 3550 30  0001 C CNN
F 1 "GND" H 5150 3480 30  0001 C CNN
F 2 "" H 5150 3550 60  0000 C CNN
F 3 "" H 5150 3550 60  0000 C CNN
	1    5150 3550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR6
U 1 1 52436C01
P 5150 4250
F 0 "#PWR6" H 5150 4250 30  0001 C CNN
F 1 "GND" H 5150 4180 30  0001 C CNN
F 2 "" H 5150 4250 60  0000 C CNN
F 3 "" H 5150 4250 60  0000 C CNN
	1    5150 4250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR7
U 1 1 52436C09
P 5150 4950
F 0 "#PWR7" H 5150 4950 30  0001 C CNN
F 1 "GND" H 5150 4880 30  0001 C CNN
F 2 "" H 5150 4950 60  0000 C CNN
F 3 "" H 5150 4950 60  0000 C CNN
	1    5150 4950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR8
U 1 1 52436C11
P 5150 5650
F 0 "#PWR8" H 5150 5650 30  0001 C CNN
F 1 "GND" H 5150 5580 30  0001 C CNN
F 2 "" H 5150 5650 60  0000 C CNN
F 3 "" H 5150 5650 60  0000 C CNN
	1    5150 5650
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR11
U 1 1 52436C19
P 6100 3550
F 0 "#PWR11" H 6100 3550 30  0001 C CNN
F 1 "GND" H 6100 3480 30  0001 C CNN
F 2 "" H 6100 3550 60  0000 C CNN
F 3 "" H 6100 3550 60  0000 C CNN
	1    6100 3550
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR12
U 1 1 52436C21
P 6100 4250
F 0 "#PWR12" H 6100 4250 30  0001 C CNN
F 1 "GND" H 6100 4180 30  0001 C CNN
F 2 "" H 6100 4250 60  0000 C CNN
F 3 "" H 6100 4250 60  0000 C CNN
	1    6100 4250
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR13
U 1 1 52436C29
P 6100 4950
F 0 "#PWR13" H 6100 4950 30  0001 C CNN
F 1 "GND" H 6100 4880 30  0001 C CNN
F 2 "" H 6100 4950 60  0000 C CNN
F 3 "" H 6100 4950 60  0000 C CNN
	1    6100 4950
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR14
U 1 1 52436C31
P 6100 5650
F 0 "#PWR14" H 6100 5650 30  0001 C CNN
F 1 "GND" H 6100 5580 30  0001 C CNN
F 2 "" H 6100 5650 60  0000 C CNN
F 3 "" H 6100 5650 60  0000 C CNN
	1    6100 5650
	1    0    0    -1  
$EndComp
Text Label 7250 1300 0    39   ~ 8
V?
Text Label 7250 1650 0    39   ~ 8
V?
Text Label 7250 2000 0    39   ~ 8
V?
Text Label 7250 1450 0    39   ~ 8
P?
Text Label 7250 1800 0    39   ~ 8
P?
Text Label 7250 2150 0    39   ~ 8
P?
$Comp
L GND #PWR15
U 1 1 52437A5F
P 8000 1350
F 0 "#PWR15" H 8000 1350 30  0001 C CNN
F 1 "GND" H 8000 1280 30  0001 C CNN
F 2 "" H 8000 1350 60  0000 C CNN
F 3 "" H 8000 1350 60  0000 C CNN
	1    8000 1350
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR16
U 1 1 52437A6E
P 8000 1700
F 0 "#PWR16" H 8000 1700 30  0001 C CNN
F 1 "GND" H 8000 1630 30  0001 C CNN
F 2 "" H 8000 1700 60  0000 C CNN
F 3 "" H 8000 1700 60  0000 C CNN
	1    8000 1700
	1    0    0    -1  
$EndComp
$Comp
L GND #PWR17
U 1 1 52437A76
P 8000 2050
F 0 "#PWR17" H 8000 2050 30  0001 C CNN
F 1 "GND" H 8000 1980 30  0001 C CNN
F 2 "" H 8000 2050 60  0000 C CNN
F 3 "" H 8000 2050 60  0000 C CNN
	1    8000 2050
	1    0    0    -1  
$EndComp
$Comp
L R R_E1
U 1 1 52437BC1
P 7700 2950
F 0 "R_E1" V 7780 2950 40  0000 C CNN
F 1 "R" V 7707 2951 40  0000 C CNN
F 2 "~" V 7630 2950 30  0000 C CNN
F 3 "~" H 7700 2950 30  0000 C CNN
	1    7700 2950
	0    -1   -1   0   
$EndComp
$Comp
L R R_E2
U 1 1 52437BC7
P 7700 3300
F 0 "R_E2" V 7780 3300 40  0000 C CNN
F 1 "R" V 7707 3301 40  0000 C CNN
F 2 "~" V 7630 3300 30  0000 C CNN
F 3 "~" H 7700 3300 30  0000 C CNN
	1    7700 3300
	0    -1   -1   0   
$EndComp
Text Label 7250 2950 0    39   ~ 8
V?
Text Label 7250 3300 0    39   ~ 8
V?
Text Label 7250 3100 0    39   ~ 8
P?
Text Label 7250 3450 0    39   ~ 8
P?
Text Label 8100 2950 0    39   ~ 8
5V
Text Notes 1750 4750 0    60   ~ 12
Napajanje\n
Text Notes 5050 800  0    60   ~ 12
Relays
Wire Wire Line
	2700 1400 2450 1400
Wire Wire Line
	2700 1500 2450 1500
Wire Wire Line
	2700 1600 2450 1600
Wire Wire Line
	2450 1700 2700 1700
Wire Wire Line
	2700 1800 2450 1800
Wire Wire Line
	2450 1900 2700 1900
Wire Wire Line
	2700 2000 2450 2000
Wire Wire Line
	2700 2100 2450 2100
Wire Wire Line
	2450 2200 2700 2200
Wire Wire Line
	2700 2300 2450 2300
Wire Wire Line
	2450 2400 2700 2400
Wire Wire Line
	2700 2500 2450 2500
Wire Wire Line
	2700 2600 2450 2600
Wire Wire Line
	2450 2700 2700 2700
Wire Wire Line
	2700 2800 2450 2800
Wire Wire Line
	2450 2900 2700 2900
Wire Wire Line
	2700 3000 2450 3000
Wire Wire Line
	2700 3100 2450 3100
Wire Wire Line
	2450 3200 2700 3200
Wire Wire Line
	2700 3300 2450 3300
Wire Wire Line
	2450 3400 2700 3400
Wire Wire Line
	2700 3600 2450 3600
Wire Wire Line
	9400 1300 9150 1300
Wire Wire Line
	9150 1400 9400 1400
Wire Wire Line
	9150 1500 9400 1500
Wire Wire Line
	9150 1600 9400 1600
Wire Wire Line
	9400 1700 9150 1700
Wire Wire Line
	9150 1800 9400 1800
Wire Wire Line
	9400 1900 9150 1900
Wire Wire Line
	9150 2000 9400 2000
Wire Wire Line
	9150 2100 9400 2100
Wire Wire Line
	9150 2300 9400 2300
Wire Wire Line
	9400 2400 9150 2400
Wire Wire Line
	9150 2500 9400 2500
Wire Wire Line
	9150 2600 9400 2600
Wire Wire Line
	9400 2700 9150 2700
Wire Wire Line
	9150 2800 9400 2800
Wire Wire Line
	9400 2900 9150 2900
Wire Wire Line
	9150 3000 9400 3000
Wire Wire Line
	9150 3100 9400 3100
Wire Wire Line
	9400 3200 9150 3200
Wire Wire Line
	9150 3300 9400 3300
Wire Wire Line
	9400 3400 9150 3400
Wire Wire Line
	9400 3500 9150 3500
Wire Wire Line
	9150 3600 9400 3600
Wire Wire Line
	1400 1400 1650 1400
Wire Wire Line
	1400 1500 1650 1500
Wire Wire Line
	1400 1600 1650 1600
Wire Wire Line
	1650 1700 1400 1700
Wire Wire Line
	1400 1800 1650 1800
Wire Wire Line
	1650 1900 1400 1900
Wire Wire Line
	1400 2000 1650 2000
Wire Wire Line
	1400 2100 1650 2100
Wire Wire Line
	1650 2200 1400 2200
Wire Wire Line
	1400 2300 1650 2300
Wire Wire Line
	1650 2400 1400 2400
Wire Wire Line
	1400 2500 1650 2500
Wire Wire Line
	1400 2600 1650 2600
Wire Wire Line
	1650 2700 1400 2700
Wire Wire Line
	1400 2800 1650 2800
Wire Wire Line
	1650 2900 1400 2900
Wire Wire Line
	1400 3000 1650 3000
Wire Wire Line
	1400 3100 1650 3100
Wire Wire Line
	1650 3200 1400 3200
Wire Wire Line
	1400 3300 1650 3300
Wire Wire Line
	1650 3400 1400 3400
Wire Wire Line
	1650 3500 1400 3500
Wire Wire Line
	1400 3600 1650 3600
Wire Wire Line
	1650 1200 1400 1200
Wire Wire Line
	2450 1200 2700 1200
Wire Wire Line
	10450 1500 10200 1500
Wire Wire Line
	10450 1600 10200 1600
Wire Wire Line
	10200 1700 10450 1700
Wire Wire Line
	10450 1800 10200 1800
Wire Wire Line
	10200 1900 10450 1900
Wire Wire Line
	10450 2000 10200 2000
Wire Wire Line
	10450 2100 10200 2100
Wire Wire Line
	10450 2300 10200 2300
Wire Wire Line
	10200 2400 10450 2400
Wire Wire Line
	10450 2500 10200 2500
Wire Wire Line
	10450 2600 10200 2600
Wire Wire Line
	10200 2700 10450 2700
Wire Wire Line
	10450 2800 10200 2800
Wire Wire Line
	10200 2900 10450 2900
Wire Wire Line
	10450 3000 10200 3000
Wire Wire Line
	10450 3100 10200 3100
Wire Wire Line
	10200 3200 10450 3200
Wire Wire Line
	10450 3300 10200 3300
Wire Wire Line
	10200 3400 10450 3400
Wire Wire Line
	10450 3600 10200 3600
Wire Wire Line
	9900 2300 9900 2350
Wire Wire Line
	10200 1300 10450 1300
Wire Wire Line
	10200 3500 10450 3500
Wire Notes Line
	4250 2900 4250 5800
Wire Notes Line
	6250 5800 6250 2850
Wire Notes Line
	4250 2850 4250 2950
Wire Notes Line
	7650 5700 10050 5700
Wire Wire Line
	5000 1450 5000 1300
Wire Wire Line
	5400 1300 5400 1550
Connection ~ 5400 1450
Wire Wire Line
	5400 1950 5400 2200
Connection ~ 5400 2100
Wire Wire Line
	5000 2100 5000 1950
Wire Wire Line
	4700 1450 5000 1450
Wire Wire Line
	5200 1000 5600 1000
Wire Wire Line
	5600 1000 5600 1500
Wire Wire Line
	5600 1500 5800 1500
Wire Wire Line
	5200 1650 5800 1650
Wire Wire Line
	4900 1950 4900 1600
Wire Wire Line
	4900 1600 4700 1600
Wire Wire Line
	5000 1950 4900 1950
Wire Notes Line
	4600 2350 4600 850 
Wire Notes Line
	5900 850  5900 2350
Wire Notes Line
	4600 850  5900 850 
Wire Notes Line
	5900 2350 4600 2350
Wire Wire Line
	1100 6350 1100 6650
Wire Wire Line
	1200 6350 1200 6650
Wire Wire Line
	1300 6350 1300 6650
Wire Wire Line
	1400 6350 1400 6650
Wire Wire Line
	1500 6350 1500 6650
Wire Wire Line
	1600 6350 1600 6650
Wire Wire Line
	1700 6350 1700 6650
Wire Wire Line
	1800 6350 1800 6650
Wire Wire Line
	1900 6350 1900 6650
Wire Wire Line
	2000 6350 2000 6650
Wire Wire Line
	2100 6350 2100 6650
Wire Wire Line
	2200 6350 2200 6650
Wire Wire Line
	3900 6350 3900 6650
Wire Wire Line
	4000 6350 4000 6650
Wire Wire Line
	4100 6350 4100 6650
Wire Wire Line
	4200 6350 4200 6650
Wire Wire Line
	4300 6350 4300 6650
Wire Wire Line
	4400 6350 4400 6650
Wire Wire Line
	4500 6350 4500 6650
Wire Wire Line
	4600 6350 4600 6650
Wire Wire Line
	4700 6350 4700 6650
Wire Wire Line
	4800 6350 4800 6650
Wire Wire Line
	4900 6350 4900 6650
Wire Wire Line
	5000 6350 5000 6650
Wire Wire Line
	5100 6350 5100 6650
Wire Wire Line
	5200 6350 5200 6650
Wire Wire Line
	5300 6350 5300 6650
Wire Wire Line
	5400 6350 5400 6650
Wire Wire Line
	5500 6350 5500 6650
Wire Wire Line
	5600 6350 5600 6650
Wire Wire Line
	5700 6350 5700 6650
Wire Wire Line
	5800 6350 5800 6650
Wire Wire Line
	5900 6350 5900 6650
Wire Wire Line
	6000 6350 6000 6650
Wire Wire Line
	6100 6350 6100 6650
Wire Wire Line
	6200 6350 6200 6650
Wire Wire Line
	6300 6350 6300 6650
Wire Wire Line
	6400 6350 6400 6650
Wire Wire Line
	6500 6350 6500 6650
Wire Wire Line
	6600 6350 6600 6650
Wire Wire Line
	6700 6350 6700 6650
Wire Wire Line
	6800 6350 6800 6650
Wire Wire Line
	2300 6350 2300 6650
Wire Wire Line
	2400 6350 2400 6650
Wire Wire Line
	2500 6350 2500 6650
Wire Wire Line
	2600 6350 2600 6650
Wire Wire Line
	2700 6350 2700 6650
Wire Wire Line
	2800 6350 2800 6650
Wire Wire Line
	2900 6350 2900 6650
Wire Wire Line
	3000 6350 3000 6650
Wire Wire Line
	1650 5250 1750 5250
Wire Wire Line
	1750 5250 1750 5400
Wire Wire Line
	2750 5050 2900 5050
Wire Wire Line
	1650 5050 1950 5050
Wire Notes Line
	1100 4800 3050 4800
Wire Notes Line
	3050 5500 1000 5500
Wire Notes Line
	1000 4800 1150 4800
Wire Notes Line
	7650 5700 7650 6800
Wire Notes Line
	7650 6800 10050 6800
Wire Notes Line
	10050 6800 10050 5700
Wire Wire Line
	7850 5900 8050 5900
Wire Wire Line
	7850 6150 8050 6150
Wire Wire Line
	7850 6400 8050 6400
Wire Wire Line
	7850 6650 8050 6650
Wire Wire Line
	8750 6650 8550 6650
Wire Wire Line
	8750 6400 8550 6400
Wire Wire Line
	8750 6150 8550 6150
Wire Wire Line
	8750 5900 8550 5900
Wire Wire Line
	9850 6650 9650 6650
Wire Wire Line
	9850 6400 9650 6400
Wire Wire Line
	9850 6150 9650 6150
Wire Wire Line
	9850 5900 9650 5900
Wire Wire Line
	8950 5900 9150 5900
Wire Wire Line
	8950 6150 9150 6150
Wire Wire Line
	8950 6400 9150 6400
Wire Wire Line
	8950 6650 9150 6650
Wire Notes Line
	7600 4150 10000 4150
Wire Notes Line
	7600 4150 7600 5250
Wire Notes Line
	7600 5250 10000 5250
Wire Notes Line
	10000 5250 10000 4150
Wire Wire Line
	7800 4350 8000 4350
Wire Wire Line
	7800 4600 8000 4600
Wire Wire Line
	7800 4850 8000 4850
Wire Wire Line
	7800 5100 8000 5100
Wire Wire Line
	8700 5100 8500 5100
Wire Wire Line
	8700 4850 8500 4850
Wire Wire Line
	8700 4600 8500 4600
Wire Wire Line
	8700 4350 8500 4350
Wire Wire Line
	9800 5100 9600 5100
Wire Wire Line
	9800 4850 9600 4850
Wire Wire Line
	9800 4600 9600 4600
Wire Wire Line
	9800 4350 9600 4350
Wire Wire Line
	8900 4350 9100 4350
Wire Wire Line
	8900 4600 9100 4600
Wire Wire Line
	8900 4850 9100 4850
Wire Wire Line
	8900 5100 9100 5100
Wire Wire Line
	4600 3000 4800 3000
Wire Wire Line
	4600 3500 4400 3500
Wire Wire Line
	4600 4200 4400 4200
Wire Wire Line
	4600 4900 4400 4900
Wire Wire Line
	4600 5600 4400 5600
Wire Wire Line
	5550 3500 5350 3500
Wire Wire Line
	5550 4200 5350 4200
Wire Wire Line
	5550 4900 5350 4900
Wire Wire Line
	5550 5600 5350 5600
Wire Wire Line
	4600 3700 4800 3700
Wire Wire Line
	4600 4400 4800 4400
Wire Wire Line
	4600 5100 4800 5100
Wire Wire Line
	5550 5100 5750 5100
Wire Wire Line
	5550 4400 5750 4400
Wire Wire Line
	5550 3700 5750 3700
Wire Wire Line
	5550 3000 5750 3000
Wire Wire Line
	5100 3500 5150 3500
Wire Wire Line
	5150 3500 5150 3550
Wire Wire Line
	5100 4200 5150 4200
Wire Wire Line
	5150 4200 5150 4250
Wire Wire Line
	5100 4900 5150 4900
Wire Wire Line
	5150 4900 5150 4950
Wire Wire Line
	5100 5600 5150 5600
Wire Wire Line
	5150 5600 5150 5650
Wire Wire Line
	6050 3500 6100 3500
Wire Wire Line
	6100 3500 6100 3550
Wire Wire Line
	6050 4200 6100 4200
Wire Wire Line
	6100 4200 6100 4250
Wire Wire Line
	6050 4900 6100 4900
Wire Wire Line
	6100 4900 6100 4950
Wire Wire Line
	6050 5600 6100 5600
Wire Wire Line
	6100 5600 6100 5650
Wire Notes Line
	6250 2850 4250 2850
Wire Notes Line
	4250 5800 6250 5800
Wire Wire Line
	7200 1300 7450 1300
Wire Wire Line
	7200 1650 7450 1650
Wire Wire Line
	7200 2000 7450 2000
Wire Wire Line
	7400 1300 7400 1450
Wire Wire Line
	7400 1450 7200 1450
Connection ~ 7400 1300
Wire Wire Line
	7400 1650 7400 1800
Wire Wire Line
	7400 1800 7200 1800
Connection ~ 7400 1650
Wire Wire Line
	7400 2000 7400 2150
Wire Wire Line
	7400 2150 7200 2150
Connection ~ 7400 2000
Wire Wire Line
	7950 1300 8000 1300
Wire Wire Line
	8000 1300 8000 1350
Wire Wire Line
	7950 1650 8000 1650
Wire Wire Line
	8000 1650 8000 1700
Wire Wire Line
	7950 2000 8000 2000
Wire Wire Line
	8000 2000 8000 2050
Wire Notes Line
	7100 1150 8100 1150
Wire Notes Line
	8100 1150 8100 2300
Wire Notes Line
	8100 2300 7100 2300
Wire Notes Line
	7100 2300 7100 1150
Wire Wire Line
	7200 2950 7450 2950
Wire Wire Line
	7200 3300 7450 3300
Wire Wire Line
	7400 2950 7400 3100
Wire Wire Line
	7400 3100 7200 3100
Connection ~ 7400 2950
Wire Wire Line
	7400 3300 7400 3450
Wire Wire Line
	7400 3450 7200 3450
Connection ~ 7400 3300
Wire Wire Line
	7950 2950 8200 2950
Wire Wire Line
	7950 3300 8050 3300
Wire Wire Line
	8050 3300 8050 2950
Connection ~ 8050 2950
Wire Notes Line
	7100 2800 8250 2800
Wire Notes Line
	8250 2800 8250 3550
Wire Notes Line
	8250 3550 7100 3550
Wire Notes Line
	7100 3550 7100 2800
NoConn ~ 10450 1500
NoConn ~ 10450 1600
NoConn ~ 10450 1700
NoConn ~ 10450 1800
NoConn ~ 10450 1900
NoConn ~ 10450 2000
NoConn ~ 10450 2100
NoConn ~ 10450 2300
NoConn ~ 10450 2400
NoConn ~ 10450 2500
NoConn ~ 10450 2600
NoConn ~ 10450 2700
NoConn ~ 10450 2800
NoConn ~ 10450 2900
NoConn ~ 10450 3000
NoConn ~ 10450 3100
NoConn ~ 10450 3200
NoConn ~ 10450 3300
NoConn ~ 10450 3400
NoConn ~ 10450 3500
NoConn ~ 9150 3500
NoConn ~ 9150 3400
NoConn ~ 9150 3300
NoConn ~ 9150 3200
NoConn ~ 9150 3100
NoConn ~ 9150 3000
NoConn ~ 9150 2900
NoConn ~ 9150 2800
NoConn ~ 9150 2700
NoConn ~ 9150 2600
NoConn ~ 9150 2500
NoConn ~ 9150 2400
NoConn ~ 9150 2300
NoConn ~ 9150 2100
NoConn ~ 9150 2000
NoConn ~ 9150 1900
NoConn ~ 9150 1800
NoConn ~ 9150 1700
NoConn ~ 9150 1600
NoConn ~ 9150 1500
NoConn ~ 1400 1500
NoConn ~ 1400 1600
NoConn ~ 1400 1700
NoConn ~ 1400 1800
NoConn ~ 1400 1900
NoConn ~ 1400 2000
NoConn ~ 1400 2100
NoConn ~ 1400 2200
NoConn ~ 1400 2400
NoConn ~ 1400 2500
NoConn ~ 1400 2600
NoConn ~ 1400 2700
NoConn ~ 1400 2800
NoConn ~ 1400 2900
NoConn ~ 1400 3000
NoConn ~ 1400 3100
NoConn ~ 1400 3200
NoConn ~ 1400 3300
NoConn ~ 1400 3400
NoConn ~ 2700 3400
NoConn ~ 2700 3300
NoConn ~ 2700 3200
NoConn ~ 2700 3100
NoConn ~ 2700 3000
NoConn ~ 2700 2900
NoConn ~ 2700 2800
NoConn ~ 2700 2700
NoConn ~ 2700 2600
NoConn ~ 2700 2500
NoConn ~ 2700 2400
NoConn ~ 2700 2300
NoConn ~ 2700 2200
NoConn ~ 2700 2100
NoConn ~ 2700 2000
NoConn ~ 2700 1900
NoConn ~ 2700 1800
NoConn ~ 2700 1700
NoConn ~ 2700 1600
NoConn ~ 2700 1500
NoConn ~ 1100 6350
NoConn ~ 1200 6350
NoConn ~ 1300 6350
NoConn ~ 1400 6350
NoConn ~ 1500 6350
NoConn ~ 1600 6350
NoConn ~ 1700 6350
NoConn ~ 1800 6350
NoConn ~ 1900 6350
NoConn ~ 2000 6350
NoConn ~ 2100 6350
NoConn ~ 2200 6350
NoConn ~ 2300 6350
NoConn ~ 2400 6350
NoConn ~ 2500 6350
NoConn ~ 2600 6350
NoConn ~ 2700 6350
NoConn ~ 2800 6350
NoConn ~ 2900 6350
NoConn ~ 3000 6350
NoConn ~ 3900 6350
NoConn ~ 4000 6350
NoConn ~ 4100 6350
NoConn ~ 4200 6350
NoConn ~ 4300 6350
NoConn ~ 4400 6350
NoConn ~ 4500 6350
NoConn ~ 4600 6350
NoConn ~ 4700 6350
NoConn ~ 4800 6350
NoConn ~ 4900 6350
NoConn ~ 5000 6350
NoConn ~ 5100 6350
NoConn ~ 5200 6350
NoConn ~ 5300 6350
NoConn ~ 5400 6350
NoConn ~ 5500 6350
NoConn ~ 5600 6350
NoConn ~ 6800 6350
NoConn ~ 6700 6350
NoConn ~ 6600 6350
NoConn ~ 6500 6350
NoConn ~ 6400 6350
NoConn ~ 6300 6350
NoConn ~ 6200 6350
NoConn ~ 6100 6350
NoConn ~ 6000 6350
NoConn ~ 5900 6350
NoConn ~ 5800 6350
NoConn ~ 5700 6350
Wire Wire Line
	10200 1400 10450 1400
Wire Wire Line
	1650 4950 1650 5050
Wire Wire Line
	2350 5350 2350 5400
Wire Wire Line
	9400 1200 9150 1200
Wire Wire Line
	10450 1200 10200 1200
Wire Notes Line
	1000 5500 1000 4800
Wire Notes Line
	3050 4800 3050 5500
$Comp
L MOSFET_N MOS_BL1
U 1 1 5245755A
P 3750 1250
F 0 "MOS_BL1" H 3760 1420 60  0000 R CNN
F 1 "BackLight1" H 3760 1100 60  0001 R CNN
F 2 "~" H 3750 1250 60  0000 C CNN
F 3 "~" H 3750 1250 60  0000 C CNN
	1    3750 1250
	1    0    0    -1  
$EndComp
Wire Notes Line
	4050 1600 4050 900 
Wire Notes Line
	3200 900  3200 1600
Text Notes 3150 850  0    60   ~ 0
Mosfet za LCD lucko
Wire Notes Line
	4050 900  3200 900 
Wire Notes Line
	3200 1600 4050 1600
Wire Wire Line
	3850 1050 4000 1050
Wire Wire Line
	4000 1450 3850 1450
Wire Wire Line
	3300 1250 3550 1250
Text Label 3900 1050 0    60   ~ 0
V?
$Comp
L GND #PWR4
U 1 1 52457DA5
P 4000 1500
F 0 "#PWR4" H 4000 1500 30  0001 C CNN
F 1 "GND" H 4000 1430 30  0001 C CNN
F 2 "" H 4000 1500 60  0000 C CNN
F 3 "" H 4000 1500 60  0000 C CNN
	1    4000 1500
	1    0    0    -1  
$EndComp
Wire Wire Line
	4000 1450 4000 1500
Text Label 3350 1250 0    60   ~ 0
P?
$EndSCHEMATC
