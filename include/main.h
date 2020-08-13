#ifndef LED_LAMP_CONTROL
#define LED_LAMP_CONTROL

//Libraries
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

//______Digital Pin Assignments______
#define FAN_CONTROL        3   //Timer 2
#define TEMP_SENSOR_INPUT  7
#define COLD_WHITE_CONTROL 9    //Timer 1 Fast PWM
#define WARM_WHITE_CONTROL 10   //Timer 1 Fast PWM

//_______Analog Pin Assignments______
#define BRIGHTNESS_POTENTIOMETER A4
#define COLOR_POTENTIOMETER      A5
#define INPUT_VOLTAGE            A6

//______________Macros_______________
#define vTaskDelayMS(ms) (vTaskDelay(ms / portTICK_PERIOD_MS))
#define TEMP_LIMIT 50

//__________Constant Values__________
static const uint16_t voltage_divider   = 34;
static const uint16_t reference_voltage = 1080;
static const uint16_t uvlo_limit        = 4500;
static const uint8_t  temp_resolution   = 12;

//__________Shared Variables_________

//LED Driver (led)
static volatile uint16_t max_brightness = 450;

//_____________Functions_____________


#endif

