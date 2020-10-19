#ifndef LED_LAMP_CONTROL_FAN
#define LED_LAMP_CONTROL_FAN

//Libraries
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

//Functions
void startFanControl();
void fanTask(void *pvParameters);

static double Kp = 5;
static double Ki = 1;
static double Kd = 1;

static double set_temp = 42;

#endif