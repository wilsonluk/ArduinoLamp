#ifndef LED_LAMP_CONTROL_FAN
#define LED_LAMP_CONTROL_FAN

//Libraries
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

//______________Macros_______________
#define PRESCALE_DISABLE 0
#define PRESCALE_1       1
#define PRESCALE_8       2
#define PRESCALE_32      3
#define PRESCALE_64      4
#define PRESCALE_128     5
#define PRESCALE_256     6
#define PRESCALE_1024    7

//Functions
void startFanControl();
void changeFanSpeed( uint16_t duty_cycle );

void fanTask(void *pvParameters);

#endif