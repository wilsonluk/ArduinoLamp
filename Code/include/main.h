#ifndef LED_LAMP_CONTROL
#define LED_LAMP_CONTROL

//Color Messages
#define COLOR_MESSAGES

//Libraries
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

//______Digital Pin Assignments______
#define POWER_SW            2   //Interrupt Line
#define FAN_CONTROL         3   //Timer 2
#define TEMP_SENSOR_INPUT   7   //OneWire Bus
#define COLD_WHITE_CONTROL  9   //Timer 1 Fast PWM
#define WARM_WHITE_CONTROL  10  //Timer 1 Fast PWM
#define PWR_EN              12  //Main Power Enable Line

//_______Analog Pin Assignments______
#define BRIGHTNESS_POTENTIOMETER    A1
#define COLOR_POTENTIOMETER         A2
#define FAN_VOLTAGE                 A5
#define INPUT_VOLTAGE               A6
#define MAIN_PWR_VOLTAGE            A7

//_____________Constants_____________
#define TEMP_LIMIT 50           //Temperature at which OTP will cut power (LEGACY, SEE otp_limit below)

//______________Macros_______________

//FreeRTOS delay but with milliseconds as the parameter
#define vTaskDelayMS(ms) (vTaskDelay(ms / portTICK_PERIOD_MS))

//message printing macros
#ifdef COLOR_MESSAGES

#define printError(msg) (Serial.println("\u001b[31mERR :\u001b[0m " + (String) msg))
#define printWarn(msg)  (Serial.println("\u001b[33mWRN :\u001b[0m " + (String) msg))
#define printDebug(msg) (Serial.println("\u001b[32mDBG :\u001b[0m " + (String) msg))

#endif

#ifndef COLOR_MESSAGES

#define printError(msg) (Serial.println("ERR : " + (String) msg))
#define printWarn(msg)  (Serial.println("WRN : " + (String) msg))
#define printDebug(msg) (Serial.println("DBG : " + (String) msg))

#endif

//__________Constant Values__________

/*  NOTES ON VOLTAGE MEASUREMENTS
Since the Arduino cannot read values greater than the
voltage of the internal reference, all measurements are
read through a potential divider. The ratio should be
expressed as the resistor ratios multipled by 1000, as
all voltage meausrements are converted to fixed point
values in mV.*/
static const uint16_t voltage_divider = 23173;

/*  NOTES ON REFERNCE VOLTAGE
Since measuring external voltages with the VCC input as
the voltage reference can lead to unstable voltage
measurements, the ATMega328P's internal voltage reference
is used. If AREF is slightly different or an external
voltage refernce is used, adjust this constant. Also in
fixed point mV*/
static const uint16_t reference_voltage = 1068;

/*  NOTES ON UNDER VOLTAGE LOCKOUT (UVLO)
If the input voltage is too low, the main power converter
may not run correctly, and the control board's buck converter
may not supply the correct voltage to the microcontroller.
Below this voltage, the lamp will revert to a failsafe mode,
shutting down the LED Driver and fan signals, and disabling the
main power supply.*/
static const uint16_t uvlo_limit = 7000;

//If the voltage exceeds this value, the main converter will shutdown
static const uint16_t ovp_limit = 25000;

//Nominal main power voltage
static const uint16_t nominal_output = 22000;

//Proportion of error acceptable before going into failsafe mode
static const float margin = 0.1;

/* NOTES ON OVER TMPERATURE PROTECTION (OTP)
If the PID fan controller cannot cool the LED sufficiently (high
ambient temperature, fan / driver failure), the LED will be shutoff, 
but the main power supply will stay on and the fan will ramp up to
max power to cool down the LED. Value in degress Celcius. */
static const uint8_t otp_threshold = 50;    


//DS18B20 measurement resolution (see https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf)
static const uint8_t  temp_resolution   = 12;


//__________Shared Variables_________

//LED Driver (led)
static volatile uint16_t max_brightness = 450;

//_____________Functions_____________
bool mainPowerOn();

void bootUpSequence();
uint16_t safeAnalogReadSingle(uint8_t pin, uint8_t adc_mode);
void safeAnalogRead(uint8_t *pin_list, uint16_t *readings, uint8_t adc_mode);

#endif

