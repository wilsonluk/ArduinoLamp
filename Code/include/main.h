#ifndef LED_LAMP_CONTROL
#define LED_LAMP_CONTROL

//Color Messages
#define COLOR_MESSAGES

//Print Debug Messages (may reduce performance)
#define DEBUG_MSG

//Libraries
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

//Headers
#include <post.h>
#include <voltmon.h>
#include <fan.h>
#include <temp.h>
#include <failsafe.h>

//______Digital Pin Assignments______
#define POWER_SW            2   //Interrupt Line
#define FAN_CONTROL         3   //Timer 2
#define TEMP_SENSOR_INPUT   7   //OneWire Bus
#define COLD_WHITE_CONTROL  9   //Timer 1 Fast PWM
#define WARM_WHITE_CONTROL  10  //Timer 1 Fast PWM
#define PWR_EN              12  //Main Power Enable Line

//_______Analog Pin Assignments______
#define BRIGHTNESS_POTENTIOMETER    A1  //Full Range 5V Input
#define COLOR_POTENTIOMETER         A2  //Full Range 5V Input
#define FAN_VOLTAGE                 A5  //AREF Input 1.1V Max Readble, 5V Tolerant
#define INPUT_VOLTAGE               A6  //AREF Input 1.1V Max Readble, 5V Tolerant
#define MAIN_PWR_VOLTAGE            A7  //AREF Input 1.1V Max Readble, 5V Tolerant

//______________Macros_______________

//FreeRTOS delay but with milliseconds as the parameter
#define vTaskDelayMS(ms) (vTaskDelay(ms / portTICK_PERIOD_MS))

//__________Shared Variables_________
static TaskHandle_t volt_mon  = NULL;
static TaskHandle_t temp_mon  = NULL;
static TaskHandle_t led_drive = NULL;
static TaskHandle_t pot_read  = NULL;

#endif

