#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

#include <main.h>
#include <led.h>
#include <potentiometer.h>
#include <fan.h>
#include <uvlo.h>

static uint8_t standby = 0;

void suspend() {
  noInterrupts();
  Serial.println("Entered Interrupt!");
  Serial.print("Current State: ");
  Serial.println(standby);
  if (standby == 0) {
    vTaskSuspendAll();
    for (uint16_t i = 0; i < OCR1A + OCR1B; i++) {
      if (OCR1A != 0) OCR1A --;
      if (OCR1B != 0) OCR1B --;
      delay(1000);
    }
    OCR1A = 0;
    OCR1B = 0;
    standby = 1;
    delay(1000);
    interrupts();
  } else {
    standby = 0;
    delay(1000);
    interrupts();
    xTaskResumeAll();
  }
  Serial.println("Exited Interrupt!");
}

void setup() {
  // put your setup code here, to run once:
  Serial.begin(115200);

  pinMode(2, INPUT);
  attachInterrupt(digitalPinToInterrupt(2), suspend, RISING);

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