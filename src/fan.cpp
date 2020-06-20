#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <fan.h>
#include <main.h>

void startFanControl() {
    pinMode(FAN_CONTROL, OUTPUT);

    OCR2B = 255;

    TCCR2A |= (1 << COM2B1);
    TCCR2A |= (1 << WGM21) | (1 << WGM20);
    TCCR2B &= 0b11111000;

    TCCR2B |= (1 << CS20);
}

void changeFanSpeed( uint16_t duty_cycle) {
    OCR2B = duty_cycle;
}

void fanTask(void *pvParameters) {
  (void) pvParameters;
  for (;;) {
    for (int i = 2; i < 75; i += 1) {
      changeFanSpeed(i);
      vTaskDelayMS(100);
    }
  }
}