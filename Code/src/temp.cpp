//_______Arduino LED Lamp Temperature Mointor________

#include <temp.h>

//Main Temp Monitoring Task
void tempTask(void *pvParameters) {
	//Serial.println("Temperature Monitoring Task Alive!");

	taskENTER_CRITICAL();
	temp_sensor.requestTemperatures();
	taskEXIT_CRITICAL();
	
	waitForTemp();

	for (;;) {
		
		taskENTER_CRITICAL();
		//Request temperature
		led_temperature = temp_sensor.getTempC(sensor_addr);
		if (led_temperature == -127.0) {failSafe(ALL);}
		
		Serial.println(led_temperature);

		//Call Alarm Handler if OTP exceeded
		temp_sensor.processAlarms();

		//Send command to read temperature
		temp_sensor.requestTemperatures();

		taskEXIT_CRITICAL();
		
		//Wait for temperature sample (FreeRTOS vTaskDelay)
		waitForTemp();
	}
}

//Get last temperature reading
double getTemp() {
	//return led_temperature;
	temp_sensor.requestTemperatures();
	waitForTemp();
	temp_sensor.processAlarms();
	return temp_sensor.getTempC(sensor_addr);
}

//Check if a temperature sensor is present and setup sensor for use
bool startTempSensor() {

	//Probe the OneWire Bus for Tmperature Sensors
	temp_sensor.begin();

	temp_sensor.setWaitForConversion(false);

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
			Serial.print("Alarm: ");
			if (temp_sensor.getTempC(temp_addr) < 0) {
				failSafe(ALL);
			} else {
				Serial.println(temp_sensor.getTempC(sensor_addr));
				failSafe(OTP);
			}
		}
	);

	return true;
}