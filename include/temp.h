#ifndef LED_LAMP_CONTROL_TEMP
#define LED_LAMP_CONTROL_TEMP

//Libraries
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <DallasTemperature.h>

//Marcos
#define waitForTemp()    (vTaskDelayMS(TEMP_SENSOR_TIME))
#define TEMP_SENSOR_TIME ((750 / (1 << (12 - temp_resolution))) + 1)

//Functions
uint8_t startTempSensor();
float checkTemperature();
void temperatureTask(void *pvParameters);

static OneWire one_wire;
static DallasTemperature temp_sensor;
static DeviceAddress temp_sensor_addr;

#endif