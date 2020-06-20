#include <main.h>
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#include <fan.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //Serial.println(TEMP_SENSOR_TIME);

  if (startTempSensor()) {
    for(;;) {}
  }

  startFanControl();
  changeFanSpeed(2);

  xTaskCreate(
    temperatureTask,
    "Temperature",
    128,
    nullptr,
    2,
    nullptr);

  xTaskCreate(
    fanTask,
    "Fan",
    96,
    nullptr,
    2,
    nullptr);
  
  xTaskCreate(
    TaskBlink,
    "Blink",
    123,
    nullptr,
    2,
    nullptr);
}

void loop() {
  // put your main code here, to run repeatedly:
}

uint8_t startTempSensor() {
  one_wire = OneWire(TEMP_SENSOR_INPUT);
  temp_sensor = DallasTemperature(&one_wire);
  temp_sensor.begin();

  if (temp_sensor.getDeviceCount() != 1) return 1;

  temp_sensor.getAddress(temp_sensor_addr, 0);
  temp_sensor.setResolution(temp_sensor_addr, temp_resolution);
  temp_sensor.setWaitForConversion(false);
  temp_sensor.setHighAlarmTemp(temp_sensor_addr, TEMP_ALARM);
  
  return 0;
}

void temperatureTask(void *pvParameters) {
  (void) pvParameters;

  for (;;) {
    Serial.print("Temperature: ");
    Serial.print(checkTemperature(), 2);
    Serial.println("C");
    vTaskDelayMS(5000);
  }
}

float checkTemperature() {
  temp_sensor.requestTemperatures();
  waitForTemp();
  return temp_sensor.getTempCByIndex(0);  
}

void TaskBlink(void *pvParameters)  // This is a task.
{
  (void) pvParameters;

  // initialize digital pin 13 as an output.
  pinMode(13, OUTPUT);

  for (;;) // A Task shall never return or exit.
  {
    digitalWrite(13, HIGH);   // turn the LED on (HIGH is the voltage level)
    vTaskDelayMS(100);
    digitalWrite(13, LOW);    // turn the LED off by making the voltage LOW
    vTaskDelayMS(1900);
  }
}