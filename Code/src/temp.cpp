//_______Arduino LED Lamp Temperature Mointor________

#include <temp.h>

//Main Temp Monitoring Task
void tempTask(void *pvParameters) {
	Serial.println("Temperature Monitoring Task Alive!");
	
	for (;;) {
		//Send command to read temperature
		temp_sensor.requestTemperatures();
		
		//Wait for temperature sample (FreeRTOS vTaskDelay)
		waitForTemp();
		
		//Request temperature
		led_temperature = temp_sensor.getTempC(sensor_addr);
		
		//Call Alarm Handler if OTP exceeded
		temp_sensor.processAlarms();
	}
}

//Get last temperature reading
double getTemp() {
	return led_temperature;
}

//Check if a temperature sensor is present and setup sensor for use
bool startTempSensor() {

	//Probe the OneWire Bus for Tmperature Sensors
	temp_sensor.begin();

	//Check that there is a temperature sensor present
	if (temp_sensor.getDeviceCount() == 0) return false;

	//Set paramters for temperature sensor
	temp_sensor.getAddress(sensor_addr, 0);
	temp_sensor.setResolution(sensor_addr, temp_resolution);
	temp_sensor.setHighAlarmTemp(sensor_addr, OTP_LIMIT);
	temp_sensor.setLowAlarmTemp(sensor_addr, UTP_LIMIT);

	//Set Over Temperature Protection (OTP) Handler
	temp_sensor.setAlarmHandler([] \
		(const byte *temp_addr) {
			if (temp_sensor.getTempC(temp_addr) < 0) {
				Serial.println("UTP Triggered!");
				failSafe(ALL);
			} else {
				Serial.println("OTP Triggered!");
				failSafe(OTP);
			}
		}
	);

	temp_sensor.requestTemperatures();

	return true;
}