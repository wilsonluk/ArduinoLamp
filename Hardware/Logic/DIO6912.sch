EESchema Schematic File Version 4
EELAYER 30 0
EELAYER END
$Descr A4 11693 8268
encoding utf-8
Sheet 2 2
Title ""
Date ""
Rev ""
Comp ""
Comment1 ""
Comment2 ""
Comment3 ""
Comment4 ""
$EndDescr
$Comp
L ArduinoLamp:JW5017S U?
U 1 1 5F8C1478
P 5750 3950
AR Path="/5F8C1A5D/5F8C1478" Ref="U?"  Part="1" 
AR Path="/5F8C9FBB/5F8C1478" Ref="IC3"  Part="1" 
AR Path="/5F8DD936/5F8C1478" Ref="IC5"  Part="1" 
AR Path="/5F8C1478" Ref="U?"  Part="1" 
AR Path="/5FB3E111/5F8C1478" Ref="U1"  Part="1" 
F 0 "U1" H 5750 4415 50  0000 C CNN
F 1 "DIO6912" H 5750 4324 50  0000 C CNN
F 2 "Package_TO_SOT_SMD:SOT-23-6_Handsoldering" H 5750 4300 50  0001 C CNN
F 3 "" H 5750 4300 50  0001 C CNN
F 4 "DIO6912" H 5750 3950 50  0001 C CNN "Manufacturer_Part_Number"
	1    5750 3950
	1    0    0    -1  
$EndComp
Text HLabel 4500 3750 0    50   Input ~ 0
VIN
Text HLabel 7750 4150 2    50   Input ~ 0
FB
Wire Wire Line
	4500 3750 4650 3750
Text HLabel 4500 4050 0    50   Input ~ 0
GND
Wire Wire Line
	4500 4050 4900 4050
Wire Wire Line
	5300 4050 5300 3950
Wire Wire Line
	5300 3950 5400 3950
$Comp
L Device:C C?
U 1 1 5F8C353A
P 6350 3800
AR Path="/5F8C1A5D/5F8C353A" Ref="C?"  Part="1" 
AR Path="/5F8C9FBB/5F8C353A" Ref="C21"  Part="1" 
AR Path="/5F8DD936/5F8C353A" Ref="C13"  Part="1" 
AR Path="/5FB3E111/5F8C353A" Ref="C3"  Part="1" 
F 0 "C3" H 6465 3846 50  0000 L CNN
F 1 "100N" H 6465 3755 50  0000 L CNN
F 2 "Capacitor_SMD:C_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 6388 3650 50  0001 C CNN
F 3 "~" H 6350 3800 50  0001 C CNN
F 4 "CL10B104KB8NNNC" H 6350 3800 50  0001 C CNN "Manufacturer_Part_Number"
	1    6350 3800
	1    0    0    -1  
$EndComp
Wire Wire Line
	6350 3650 6100 3650
Wire Wire Line
	6100 3650 6100 3750
Wire Wire Line
	6100 3950 6350 3950
$Comp
L Device:L L?
U 1 1 5F8C3F06
P 7050 3650
AR Path="/5F8C1A5D/5F8C3F06" Ref="L?"  Part="1" 
AR Path="/5F8C9FBB/5F8C3F06" Ref="L6"  Part="1" 
AR Path="/5F8DD936/5F8C3F06" Ref="L2"  Part="1" 
AR Path="/5FB3E111/5F8C3F06" Ref="L1"  Part="1" 
F 0 "L1" V 7240 3650 50  0000 C CNN
F 1 "22U" V 7149 3650 50  0000 C CNN
F 2 "ArduinoLamp:YT0630" H 7050 3650 50  0001 C CNN
F 3 "~" H 7050 3650 50  0001 C CNN
F 4 "YT0630-220M" H 7050 3650 50  0001 C CNN "Manufacturer_Part_Number"
	1    7050 3650
	0    -1   -1   0   
$EndComp
Wire Wire Line
	6350 3950 6900 3950
Wire Wire Line
	6900 3950 6900 3650
Connection ~ 6350 3950
$Comp
L Device:C C?
U 1 1 5F8C4C57
P 4900 3900
AR Path="/5F8C1A5D/5F8C4C57" Ref="C?"  Part="1" 
AR Path="/5F8C9FBB/5F8C4C57" Ref="C20"  Part="1" 
AR Path="/5F8DD936/5F8C4C57" Ref="C12"  Part="1" 
AR Path="/5FB3E111/5F8C4C57" Ref="C2"  Part="1" 
F 0 "C2" H 5015 3946 50  0000 L CNN
F 1 "2U2" H 5015 3855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 4938 3750 50  0001 C CNN
F 3 "~" H 4900 3900 50  0001 C CNN
F 4 "C0805X5R225K500NT" H 4900 3900 50  0001 C CNN "Manufacturer_Part_Number"
	1    4900 3900
	1    0    0    -1  
$EndComp
Connection ~ 4900 3750
Wire Wire Line
	4900 3750 5400 3750
Connection ~ 4900 4050
Wire Wire Line
	4900 4050 5300 4050
$Comp
L Device:C C?
U 1 1 5F8C53D4
P 7200 3900
AR Path="/5F8C1A5D/5F8C53D4" Ref="C?"  Part="1" 
AR Path="/5F8C9FBB/5F8C53D4" Ref="C22"  Part="1" 
AR Path="/5F8DD936/5F8C53D4" Ref="C14"  Part="1" 
AR Path="/5FB3E111/5F8C53D4" Ref="C4"  Part="1" 
F 0 "C4" H 7315 3946 50  0000 L CNN
F 1 "2U2" H 7315 3855 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 7238 3750 50  0001 C CNN
F 3 "~" H 7200 3900 50  0001 C CNN
F 4 "C0805X5R225K500NT" H 7200 3900 50  0001 C CNN "Manufacturer_Part_Number"
	1    7200 3900
	1    0    0    -1  
$EndComp
Wire Wire Line
	6100 4150 7750 4150
Wire Wire Line
	7200 4050 7200 4300
Wire Wire Line
	7200 4300 5300 4300
Wire Wire Line
	5300 4300 5300 4050
Connection ~ 5300 4050
Text HLabel 7750 3650 2    50   Input ~ 0
VOUT
Wire Wire Line
	7200 3650 7200 3750
Wire Wire Line
	7750 3650 7200 3650
Connection ~ 7200 3650
Text Notes 7500 4300 0    50   ~ 0
NOTE: 0.6V Feedback
$Comp
L Device:R R26
U 1 1 5FA47185
P 4650 4050
AR Path="/5F8DD936/5FA47185" Ref="R26"  Part="1" 
AR Path="/5F8C9FBB/5FA47185" Ref="R27"  Part="1" 
AR Path="/5FB3E111/5FA47185" Ref="R7"  Part="1" 
F 0 "R7" H 4720 4096 50  0000 L CNN
F 1 "105K" H 4720 4005 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4580 4050 50  0001 C CNN
F 3 "~" H 4650 4050 50  0001 C CNN
F 4 "RC0603FR-07105KL" H 4650 4050 50  0001 C CNN "Manufacturer_Part_Number"
	1    4650 4050
	1    0    0    -1  
$EndComp
Wire Wire Line
	4650 3900 4650 3750
Connection ~ 4650 3750
Wire Wire Line
	4650 3750 4900 3750
Wire Wire Line
	4650 4200 5400 4200
Wire Wire Line
	5400 4200 5400 4150
$EndSCHEMATC
