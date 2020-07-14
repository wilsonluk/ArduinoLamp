#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <OneWire.h>
#include <DallasTemperature.h>

#include <led.h>
#include <potentiometer.h>
#include <fan.h>
#include <uvlo.h>
#include <temp.h>
#include <main.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  if (startTempSensor()) {
    for(;;) {}
  }

  startFanControl();

  xTaskCreate(
    temperatureTask,
    "Temperature",
    128,
    nullptr,
    2,
    nullptr);

  xTaskCreate(
    uvloTask,
    "Under Voltage Lockout",
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
    64,
    nullptr,
    2,
    nullptr);

  xTaskCreate(
    potentiometerTask,
    "User Input",
    128,
    nullptr,
    2,
    nullptr);

  xTaskCreate(
    ledTask,
    "LED Driver",
    128,
    nullptr,
    2,
    nullptr);
}

void loop() {
  // put your main code here, to run repeatedly:
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