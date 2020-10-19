//LED Lamp - Temperature Monitor (DS18B20)

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <DallasTemperature.h>

#include <main.h>
#include <temp.h>
#include <safe.h>

uint8_t startTempSensor() {
    one_wire = OneWire(TEMP_SENSOR_INPUT);
    temp_sensor = DallasTemperature(&one_wire);
    temp_sensor.begin();

    if (temp_sensor.getDeviceCount() != 1) return 1;

    temp_sensor.getAddress(temp_sensor_addr, 0);
    temp_sensor.setResolution(temp_sensor_addr, temp_resolution);
    temp_sensor.setWaitForConversion(false);
    temp_sensor.setHighAlarmTemp(temp_sensor_addr, TEMP_LIMIT);

    temp_sensor.setAlarmHandler([](const uint8_t *temp_addr) {failSafe();});

    return 0;
}

float checkTemperature() {
    temp_sensor.requestTemperatures();
    waitForTemp();
    return temp_sensor.getTempCByIndex(0);  
}