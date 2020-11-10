EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 4 7
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
Text HLabel 4850 4150 0    50   Input ~ 0
VIN
Text HLabel 4850 4450 0    50   Input ~ 0
DIM
Text HLabel 4850 4850 0    50   Input ~ 0
GND
$Comp
L Device:C C15
U 1 1 5F8E3C51
P 5400 4700
AR Path="/5F8DDC00/5F8E3C51" Ref="C15"  Part="1" 
AR Path="/5F8D89C6/5F8E3C51" Ref="C18"  Part="1" 
F 0 "C18" H 5515 4746 50  0000 L CNN
F 1 "2U2" H 5515 4655 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 5438 4550 50  0001 C CNN
F 3 "~" H 5400 4700 50  0001 C CNN
F 4 "C0805X5R225K500NT" H 5400 4700 50  0001 C CNN "Manufacturer_Part_Number"
	1    5400 4700
	1    0    0    -1  
$EndComp
$Comp
L ArduinoLamp:BP1360 IC2
U 1 1 5F8E47BD
P 6250 4400
AR Path="/5F8DDC00/5F8E47BD" Ref="IC2"  Part="1" 
AR Path="/5F8D89C6/5F8E47BD" Ref="IC4"  Part="1" 
F 0 "IC4" H 6528 4346 50  0000 L CNN
F 1 "BP1360" H 6528 4255 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23-5_HandSoldering" H 5800 4750 50  0001 C CNN
F 3 "" H 5800 4750 50  0001 C CNN
F 4 "BP1360" H 6250 4400 50  0001 C CNN "Manufacturer_Part_Number"
	1    6250 4400
	1    0    0    -1  
$EndComp
$Comp
L Device:R R15
U 1 1 5F8E5B58
P 6250 3450
AR Path="/5F8DDC00/5F8E5B58" Ref="R15"  Part="1" 
AR Path="/5F8D89C6/5F8E5B58" Ref="R21"  Part="1" 
F 0 "R21" V 6043 3450 50  0000 C CNN
F 1 "0R2" V 6134 3450 50  0000 C CNN
F 2 "Resistor_SMD:R_1206_3216Metric_Pad1.42x1.75mm_HandSolder" V 6180 3450 50  0001 C CNN
F 3 "~" H 6250 3450 50  0001 C CNN
F 4 "1206W3J020LT5E" H 6250 3450 50  0001 C CNN "Manufacturer_Part_Number"
	1    6250 3450
	0    1    1    0   
$EndComp
Wire Wire Line
	5400 4150 4850 4150
Wire Wire Line
	4850 4450 5000 4450
Wire Wire Line
	5750 4450 5750 4500
Wire Wire Line
	5750 4500 5900 4500
Wire Wire Line
	5400 4550 5400 4150
Wire Wire Line
	5400 4850 5000 4850
Text HLabel 6950 3450 2    50   Input ~ 0
LED+
Text HLabel 6950 3750 2    50   Input ~ 0
LED-
Wire Wire Line
	6250 4850 5400 4850
Connection ~ 5400 4850
$Comp
L Device:D_Schottky D2
U 1 1 5F8E74F3
P 6250 3900
AR Path="/5F8DDC00/5F8E74F3" Ref="D2"  Part="1" 
AR Path="/5F8D89C6/5F8E74F3" Ref="D4"  Part="1" 
F 0 "D4" H 6250 4117 50  0000 C CNN
F 1 "SS34" H 6250 4026 50  0000 C CNN
F 2 "ArduinoLamp:D_SMC_Handsoldering_Shortened" H 6250 3900 50  0001 C CNN
F 3 "~" H 6250 3900 50  0001 C CNN
F 4 "C13763" H 6250 3900 50  0001 C CNN "Mouser Part Number"
	1    6250 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:L L3
U 1 1 5F8E819A
P 6750 3900
AR Path="/5F8DDC00/5F8E819A" Ref="L3"  Part="1" 
AR Path="/5F8D89C6/5F8E819A" Ref="L5"  Part="1" 
F 0 "L5" H 6802 3946 50  0000 L CNN
F 1 "47U" H 6802 3855 50  0000 L CNN
F 2 "ArduinoLamp:SLD10" H 6750 3900 50  0001 C CNN
F 3 "~" H 6750 3900 50  0001 C CNN
F 4 "SLD10D50S470MTT" H 6750 3900 50  0001 C CNN "Manufacturer_Part_Number"
	1    6750 3900
	1    0    0    -1  
$EndComp
$Comp
L Device:C C16
U 1 1 5F8E8A71
P 6750 3600
AR Path="/5F8DDC00/5F8E8A71" Ref="C16"  Part="1" 
AR Path="/5F8D89C6/5F8E8A71" Ref="C19"  Part="1" 
F 0 "C19" H 6865 3646 50  0000 L CNN
F 1 "1U" H 6865 3555 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6788 3450 50  0001 C CNN
F 3 "~" H 6750 3600 50  0001 C CNN
F 4 "TCC0805X7R105K500DTS" H 6750 3600 50  0001 C CNN "Manufacturer_Part_Number"
	1    6750 3600
	1    0    0    -1  
$EndComp
Wire Wire Line
	5400 4150 5400 3450
Wire Wire Line
	5400 3450 6100 3450
Connection ~ 5400 4150
Wire Wire Line
	6100 3450 6100 3900
Connection ~ 6100 3450
Wire Wire Line
	6750 3750 6950 3750
Connection ~ 6750 3750
Wire Wire Line
	6400 3450 6750 3450
Wire Wire Line
	6750 3450 6950 3450
Connection ~ 6750 3450
Wire Wire Line
	6100 4150 6100 3900
Connection ~ 6100 3900
Wire Wire Line
	6250 4150 6250 4050
$Comp
L Device:R R14
U 1 1 5F8EB4DA
P 5000 4650
AR Path="/5F8DDC00/5F8EB4DA" Ref="R14"  Part="1" 
AR Path="/5F8D89C6/5F8EB4DA" Ref="R20"  Part="1" 
F 0 "R20" H 5070 4696 50  0000 L CNN
F 1 "1K15" H 5070 4605 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4930 4650 50  0001 C CNN
F 3 "~" H 5000 4650 50  0001 C CNN
F 4 "RS-03K1151FT" H 5000 4650 50  0001 C CNN "Manufacturer_Part_Number"
	1    5000 4650
	1    0    0    -1  
$EndComp
Wire Wire Line
	5000 4500 5000 4450
Connection ~ 5000 4450
Wire Wire Line
	5000 4450 5750 4450
Wire Wire Line
	5000 4800 5000 4850
Connection ~ 5000 4850
Wire Wire Line
	5000 4850 4850 4850
Wire Wire Line
	6400 3900 6400 4150
Wire Wire Line
	6750 4050 6750 4150
Wire Wire Line
	6750 4150 6400 4150
Connection ~ 6400 4150
Wire Wire Line
	6400 3450 6400 3700
Wire Wire Line
	6400 3700 6550 3700
Wire Wire Line
	6550 3700 6550 4050
Wire Wire Line
	6550 4050 6250 4050
Connection ~ 6400 3450
$EndSCHEMATC
