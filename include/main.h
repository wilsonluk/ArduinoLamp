#ifndef LED_LAMP_CONTROL
#define LED_LAMP_CONTROL

//Libraries
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>
#include <OneWire.h>
#include <DallasTemperature.h>

//______Digital Pin Assignments______
#define TEMP_SENSOR_INPUT  2
#define FAN_CONTROL        3    //Timer 2
#define COLD_WHITE_CONTROL 9    //Timer 1 Fast PWM
#define WARM_WHITE_CONTROL 10   //Timer 1 Fast PWM

//_______Analog Pin Assignments______
#define BRIGHTNESS_POTENTIOMETER A4
#define COLOR_POTENTIOMETER      A5
#define INPUT_VOLTAGE            A6

//______________Macros_______________
#define vTaskDelayMS(ms) (vTaskDelay(ms / portTICK_PERIOD_MS))

#define TEMP_LIMIT 85

//__________Constant Values__________
static const uint16_t voltage_divider  = 5700;
static const uint16_t uvlo_limit = 4800;
static const uint8_t  temp_resolution = 10;

//__________Shared Variables_________

//Voltage Monitor (uvlo)
static volatile uint8_t uvlo_status = 0;

//LED Driver (led)
static volatile uint16_t max_brightness = 450;
volatile uint16_t target_blue;
volatile uint16_t target_yellow;

//Temperature Sensor (temp)
static volatile uint8_t otp_status = 0;

//_____________Functions_____________

void TaskBlink(void *pvParameters);

#endif

