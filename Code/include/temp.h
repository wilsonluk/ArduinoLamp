#include <main.h>

#ifndef ARDUINO_LAMP_TEMP
#define ARDUINO_LAMP_TEMP

#include <DallasTemperature.h>

/*_______Arduino LED Lamp Temperature Senor and Fan Control______
Checks for a DS18B20 temperature sensor and monitors the temperature
to ensure the LED array does not overheat. The PID controller adjusts
the fan speed to keep the temperature at the desired value. If the
tmeperature increases beyond the Over Temperature Protection (OTP)
limit, the lamp will enter a failsafe mode where the led power is
shutdown but the fan will run at full speed.
*/

//___________________________Functions___________________________

//Main Temp Monitoring Task
void tempTask(void *pvParameters);

//Check if a temperature sensor is present
bool startTempSensor();

//Get last temperature reading
double getTemp();


//___________________________Constants___________________________

/* OVER TEMPERATURE PROTECTION (OTP)
If the PID fan controller cannot cool the LED sufficiently (high
ambient temperature, fan / driver failure), the LED will be shutoff, 
but the main power supply will stay on and the fan will ramp up to
max power to cool down the LED. Value in degress Celcius. */
#define OTP_LIMIT 50

/* UNDER TEMPERATURE PROTECTION (UTP)
If the temperature falls below the minimum operating temperature of
the components, the lamp will shutdown.*/
#define UTP_LIMIT -10

/*DS18B20 Measurement Resolution 
Incerasing the resolution of the temperature measurement causes the
sampling time of the sensor to increase.
(see https://datasheets.maximintegrated.com/en/ds/DS18B20.pdf)
*/
static const byte temp_resolution = 12;

//____________________________Macros_____________________________

//Determine the time to wait for sampling given the reading resolution
#define TEMP_SENSOR_TIME ((750 / (1 << (12 - temp_resolution))) + 1)

//Context switch to other processes while the temperature is sampling
#define waitForTemp()  (vTaskDelayMS(TEMP_SENSOR_TIME))

//___________________________Variables___________________________

//Local Variables
static OneWire one_wire(TEMP_SENSOR_INPUT);
static DallasTemperature temp_sensor(&one_wire);
static DeviceAddress sensor_addr;

//Temperature
static double led_temperature;

#endif