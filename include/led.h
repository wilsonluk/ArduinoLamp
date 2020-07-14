#ifndef LED_LAMP_CONTROL_LIGHT
#define LED_LAMP_CONTROL_LIGHT

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <main.h>

void ledDriverSetup();
void updateBrightness();
void ledTask(void *pvParameters);

#endif