//LED Lamp Under Voltage Lockout (UVLO)

#ifndef LED_LAMP_CONTROL_UVLO
#define LED_LAMP_CONTROL_UVLO

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <main.h>


//Macros
#define inputVoltage() (voltage_divider * 5 / 1023 * analogRead(INPUT_VOLTAGE))

//Functions
void uvloSetup();
void uvloTask(void *pvParameters);

//Variables
uint16_t initial_voltage;
uint16_t uvp_threshold;
uint16_t uvlo_threshold;

#endif