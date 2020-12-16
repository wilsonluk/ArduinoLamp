#ifndef LED_LAMP_CONTROL_FAN
#define LED_LAMP_CONTROL_FAN

#include <main.h>

/*_______Arduino LED Lamp Fan Controller________
PWM Fan Controller designed to actively cool the
LED array. PID Control with a set temperature
target is used to control the fan speed.
*/

//_________________Functions____________________

//Setup Arduino Timer 2B to output fast PWM
void prepareFanPWM();

//Change duty cycle of PWM fan output
void changeFanSpeed(byte speed);

//PID Fan Controller
void fanControlTask(void *pvParameters);

//_________________Constants____________________

//PID Tuning Parameters
static double Kp = 5;
static double Ki = 4;
static double Kd = 1;

//Min PWM value to start fan
static const byte min_fan = 10;

//Max PWM value (prevent exceed operating voltage)
static byte max_fan = 150;

//Target Temperature to maintain in Celcius
static const double target_temp = 15;

#endif