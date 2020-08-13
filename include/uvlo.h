//LED Lamp Under Voltage Lockout (UVLO)

#ifndef LED_LAMP_CONTROL_UVLO
#define LED_LAMP_CONTROL_UVLO

#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <main.h>

//Functions Declarations
void uvloSetup();
void uvloTask(void *pvParameters);
void changeADCReference(uint8_t mode);
/*inputVoltage NOTE:
To prevent context swiching from occuring while the ADC is being sampled,
the analogRead is kept within a critical section to ensure that the ADC 
reference is properly switched. Failure to do so can cause inaccurate
analogRead values.
*/
uint16_t inputVoltage();

static uint16_t initial_voltage;
static uint16_t uvp_threshold;
static uint16_t ovp_threshold;

#endif