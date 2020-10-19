#ifndef LED_LAMP_CONTROL_LIGHT
#define LED_LAMP_CONTROL_LIGHT

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

void ledDriverSetup();
void updateBrightness();

void changeTargetBrightness(uint16_t blue, uint16_t yellow);

void ledTask(void *pvParameters);

static volatile uint16_t target_blue;
static volatile uint16_t target_yellow;

#endif