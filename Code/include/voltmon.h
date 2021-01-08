#ifndef ARDUINO_LAMP_VOLTMON
#define ARDUINO_LAMP_VOLTMON

#include <main.h>

/*_______Arduino LED Lamp Voltage Monitor_______
When running, voltages are monitor tp ensure they
do not change from their initial values at bootup,
and that they do not violate the minimum or maximium
voltage.
*/

//_________________Functions____________________
//Fan RTOS Task
void voltMonTask(void *pvParameters);

//Sample Voltage Sense Line
unsigned int checkSenseLine(byte analogPin);

//Set the UVP/OVP Limits
void setMonitorLimits(unsigned int input_volt, unsigned int output_volt);

//Check Input Voltage
bool checkInput(unsigned int val);
//Check Output Voltage
bool checkOutput(unsigned int val);
//Check Fan Voltage
bool checkFan(unsigned int val);

//_________________Constants____________________

/*  ACCPETABLE VOLTAGE TOLERANCE (MARGIN)
Proportion of error acceptable for meausred voltages 
before going into failsafe mode*/
static const PROGMEM double margin = 0.15;

/*  VOLTAGE DIVIDER
Since the Arduino cannot read values greater than the
voltage of the internal reference, all measurements are
read through a potential divider. The ratio should be
expressed as the resistor ratios multipled by 1000, as
all voltage meausrements are converted to fixed point
values in mV.*/
static const PROGMEM unsigned int voltage_divider = 23275;

/*  REFERNCE VOLTAGE
Since measuring external voltages with the VCC input as
the voltage reference can lead to unstable voltage
measurements, the ATMega328P's internal voltage reference
is used. If AREF is slightly different or an external
voltage refernce is used, adjust this constant. Also in
fixed point mV.*/
static const PROGMEM unsigned int reference_voltage = 1058;

/*  UNDERVOLTAGE PROTECTION (UVP)
If the input voltage is too low, the main power converter
may not run correctly, and the control board's buck converter
may not supply the correct voltage to the microcontroller.
Below this voltage, the lamp will revert to a failsafe mode,
shutting down the LED Driver and fan signals, and disabling the
main power supply. Also in fixed point mV.*/
static unsigned int uvp_input = 8500;

/*  OVERVOLTAGE PROTECTION (OVP)
If the input voltage exceeds this value, the main converter 
will shutdown.  Also in fixed point mV.*/
static unsigned int ovp_input = 25000;

/*  NOMINAL OUTPUT VOLTAGE
If the meausred value of the
converter deviates from this value by a margin (see below),
lamp will revert to failsafe mode. Also in fixed point mV.*/
static const PROGMEM unsigned int nominal_output = 22000;

static unsigned int uvp_output = nominal_output * (1 - margin);
static unsigned int ovp_output = nominal_output * (1 + margin);

/*Nominal Max Fan Voltage (mV)
Max fan voltage in fixed point mV.*/
static const PROGMEM unsigned int ovp_fan = 13000;

#endif