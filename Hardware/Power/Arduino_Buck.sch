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
Text HLabel 4450 4400 0    50   Input ~ 0
GND
Text HLabel 7200 4000 2    50   Input ~ 0
FB
$Comp
L Device:R R19
U 1 1 5F8ED5C2
P 6950 4200
F 0 "R19" H 7020 4246 50  0000 L CNN
F 1 "1K15" H 7020 4155 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6880 4200 50  0001 C CNN
F 3 "~" H 6950 4200 50  0001 C CNN
F 4 "RS-03K1151FT" H 6950 4200 50  0001 C CNN "Manufacturer_Part_Number"
	1    6950 4200
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 4050 6950 4000
Wire Wire Line
	6950 4000 7200 4000
Wire Wire Line
	5650 4400 5650 4300
Wire Wire Line
	6950 4350 6950 4400
Connection ~ 5650 4400
Connection ~ 6100 4400
Wire Wire Line
	5650 4400 6100 4400
$Comp
L Transistor_FET:2N7000 Q3
U 1 1 5F8F3832
P 5550 4100
F 0 "Q3" H 5754 4146 50  0000 L CNN
F 1 "2N7000" H 5754 4055 50  0000 L CNN
F 2 "Package_TO_SOT_THT:TO-92_Inline" H 5750 4025 50  0001 L CIN
F 3 "https://www.fairchildsemi.com/datasheets/2N/2N7000.pdf" H 5550 4100 50  0001 L CNN
F 4 "2N7000" H 5550 4100 50  0001 C CNN "Manufacturer_Part_Number"
	1    5550 4100
	1    0    0    -1  
$EndComp
Wire Wire Line
	4450 4050 5200 4050
Text HLabel 4450 4050 0    50   Input ~ 0
PWM
Connection ~ 5200 4050
Wire Wire Line
	5200 4050 5200 4100
Wire Wire Line
	5200 4050 5350 4050
Wire Wire Line
	5350 4050 5350 4100
Wire Wire Line
	4450 4400 5200 4400
$Comp
L Device:D_Zener D7
U 1 1 5FB97005
P 5200 4250
F 0 "D7" V 5154 4330 50  0000 L CNN
F 1 "D_Zener" V 5245 4330 50  0000 L CNN
F 2 "Diode_SMD:D_SOD-323_HandSoldering" H 5200 4250 50  0001 C CNN
F 3 "~" H 5200 4250 50  0001 C CNN
	1    5200 4250
	0    1    1    0   
$EndComp
Connection ~ 5200 4400
Wire Wire Line
	5200 4400 5650 4400
Wire Wire Line
	4450 3370 4780 3370
$Comp
L Transistor_FET:TSM2301ACX Q4
U 1 1 5F8E71B4
P 5650 3470
F 0 "Q4" H 5854 3516 50  0000 L CNN
F 1 "PJM2301PSA-S" H 5854 3425 50  0000 L CNN
F 2 "Package_TO_SOT_SMD:SOT-23" H 5850 3395 50  0001 L CIN
F 3 "https://www.taiwansemi.com/products/datasheet/TSM2301A_C15.pdf" H 5650 3470 50  0001 L CNN
F 4 "PJM2301PSA-S" H 5650 3470 50  0001 C CNN "Manufacturer_Part_Number"
	1    5650 3470
	0    -1   -1   0   
$EndComp
Wire Wire Line
	5200 3370 5450 3370
Connection ~ 5200 3370
Wire Wire Line
	5850 3370 6100 3370
$Comp
L Device:R R27
U 1 1 5FAF10C0
P 5200 3520
F 0 "R27" H 5270 3566 50  0000 L CNN
F 1 "105K" H 5270 3475 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 5130 3520 50  0001 C CNN
F 3 "~" H 5200 3520 50  0001 C CNN
F 4 "RC0603FR-07105KL" H 5200 3520 50  0001 C CNN "Manufacturer_Part_Number"
	1    5200 3520
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 3370 7200 3370
Connection ~ 6950 3370
Wire Wire Line
	6950 3370 6950 3470
$Comp
L Device:R R18
U 1 1 5F8ECD7F
P 6950 3620
F 0 "R18" H 7020 3666 50  0000 L CNN
F 1 "25K5" H 7020 3575 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 6880 3620 50  0001 C CNN
F 3 "~" H 6950 3620 50  0001 C CNN
F 4 "RS-05K2552FT" H 6950 3620 50  0001 C CNN "Manufacturer_Part_Number"
	1    6950 3620
	1    0    0    -1  
$EndComp
$Comp
L Device:C C17
U 1 1 5F8EC349
P 6550 3820
F 0 "C17" H 6665 3866 50  0000 L CNN
F 1 "2U2" H 6665 3775 50  0000 L CNN
F 2 "Capacitor_SMD:C_0805_2012Metric_Pad1.15x1.40mm_HandSolder" H 6588 3670 50  0001 C CNN
F 3 "~" H 6550 3820 50  0001 C CNN
F 4 "C0805X5R225K500NT" H 6550 3820 50  0001 C CNN "Manufacturer_Part_Number"
	1    6550 3820
	1    0    0    -1  
$EndComp
$Comp
L Device:D_Schottky D3
U 1 1 5F8E9922
P 6100 3820
F 0 "D3" V 6054 3900 50  0000 L CNN
F 1 "SS24" V 6145 3900 50  0000 L CNN
F 2 "ArduinoLamp:D_SMA_Handsoldering_Shortened" H 6100 3820 50  0001 C CNN
F 3 "~" H 6100 3820 50  0001 C CNN
F 4 "" H 6100 3820 50  0001 C CNN "Mouser Part Number"
F 5 "C181203" H 6100 3820 50  0001 C CNN "Arrow Part Number"
	1    6100 3820
	0    1    1    0   
$EndComp
$Comp
L Device:L L4
U 1 1 5F8E9295
P 6250 3370
F 0 "L4" V 6440 3370 50  0000 C CNN
F 1 "330U" V 6349 3370 50  0000 C CNN
F 2 "ArduinoLamp:SLD10" H 6250 3370 50  0001 C CNN
F 3 "~" H 6250 3370 50  0001 C CNN
F 4 "SLD10D40S331MTT" H 6250 3370 50  0001 C CNN "Manufacturer_Part_Number"
	1    6250 3370
	0    -1   -1   0   
$EndComp
Text HLabel 7200 3370 2    50   Input ~ 0
FAN
Text HLabel 4450 3370 0    50   Input ~ 0
VIN
$Comp
L Device:R_Small R17
U 1 1 5FCEBA9D
P 5650 3790
F 0 "R17" H 5709 3836 50  0000 L CNN
F 1 "2K2" H 5709 3745 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" H 5650 3790 50  0001 C CNN
F 3 "~" H 5650 3790 50  0001 C CNN
	1    5650 3790
	1    0    0    -1  
$EndComp
Wire Wire Line
	6950 3770 6950 4000
Connection ~ 6950 4000
Wire Wire Line
	5200 3670 5200 4050
Wire Wire Line
	5650 3890 5650 3900
Wire Wire Line
	5650 3690 5650 3680
$Comp
L Device:R R16
U 1 1 5FCF08E2
P 4780 3520
F 0 "R16" H 4850 3566 50  0000 L CNN
F 1 "1K15" H 4850 3475 50  0000 L CNN
F 2 "Resistor_SMD:R_0603_1608Metric_Pad1.05x0.95mm_HandSolder" V 4710 3520 50  0001 C CNN
F 3 "~" H 4780 3520 50  0001 C CNN
	1    4780 3520
	1    0    0    -1  
$EndComp
Connection ~ 4780 3370
Wire Wire Line
	4780 3370 5200 3370
Wire Wire Line
	4780 3670 4780 3680
Wire Wire Line
	4780 3680 5650 3680
Connection ~ 5650 3680
Wire Wire Line
	5650 3680 5650 3670
Wire Wire Line
	6400 3370 6550 3370
Wire Wire Line
	6100 4400 6950 4400
Wire Wire Line
	6100 3970 6100 4400
Wire Wire Line
	6100 3670 6100 3370
Connection ~ 6100 3370
Wire Wire Line
	6550 3670 6550 3370
Connection ~ 6550 3370
Wire Wire Line
	6550 3370 6950 3370
$EndSCHEMATC
