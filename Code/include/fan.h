#ifndef LED_LAMP_CONTROL_FAN
#define LED_LAMP_CONTROL_FAN

//______Libraries______
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

//______Functions______
void startFanControl();
void fanTask(void *pvParameters);

bool checkForFan();
uint16_t checkFanVoltage();

//______Constants______

//PID Tuning Parameters
static double Kp = 5;
static double Ki = 1;
static double Kd = 1;

//Fan Control target temperature
static const double set_temp = 42;

//Nominal Max Fan Voltage (mV)
static const uint16_t fan_nominal = 12500;

//Min PWM value to start fan
static const uint8_t min_fan = 10;

//Max PWM value (prevent exceed operating voltage)
static const uint8_t max_fan = 150;

#endif