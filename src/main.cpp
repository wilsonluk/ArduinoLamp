#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include <main.h>
#include <led.h>
#include <potentiometer.h>
#include <fan.h>
#include <uvlo.h>

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  xTaskCreate(
    uvloTask,
    "Under Voltage Lockout",
    128,
    nullptr,
    4,
    nullptr);

  xTaskCreate(
    fanTask,
    "Fan",
    256,
    nullptr,
    3,
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