#ifndef LED_LAMP_CONTROL
#define LED_LAMP_CONTROL

//__________Testing Tools___________
	//Ramp Test Mode (used to test LED ramping profiles)
	//#define RAMP_TEST_MODE

	//Print Debug Messages (may reduce performance)
	//#define DEBUG_MSG

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
	//FreeRTOS delay but with milliseconds as the parameter (swtiches to other tasks)
	#define vTaskDelayMS(ms) (vTaskDelay(ms / portTICK_PERIOD_MS))

	//Debug Message Printing
	#ifdef DEBUG_MSG
		#define debug_prnt(...) {\
			Serial.print(F("DBG: "));\
			Serial.printf(__VA_ARGS__);\
		}
	#else
		#define debug_prnt(...) {};
	#endif

	//Error Message Printing
	#define error_prnt(...) {\
		Serial.print(F("ERR: "));\
		Serial.printf(__VA_ARGS__);\
	}

	//General Message Printing
	#define msg_prnt(...) {\
		Serial.print(F("MSG: "));\
		Serial.printf(__VA_ARGS__);\
	}

//Libraries
#include <avr/sleep.h>
#include <avr/power.h>
#include <Arduino.h>
#include <Arduino_FreeRTOS.h>

//Headers Files
#include <post.h>
#include <voltmon.h>
#include <fan.h>
#include <temp.h>
#include <failsafe.h>
#include <led.h>
#include <pot.h>

//____________Task Handles___________
static TaskHandle_t volt_mon;
static TaskHandle_t temp_mon;
static TaskHandle_t led_ctrl;
static TaskHandle_t fan_ctrl;
static TaskHandle_t pot_read;
static TaskHandle_t switch_handler;

static bool sleep_state;



//_________Inline Functions_________

inline void printWelcomeMsg() {
	msg_prnt(F("Arduino Lamp v2.1 - Jan 2021\n"));
	msg_prnt(F("Written By Wilson Luk\n"));
	msg_prnt(F("____________________Library Credits____________________\n"));

	msg_prnt(F("FreeRTOS - Amazon Web Services, Inc., ported by Phillip Stevens\n"
	      "     (https://www.arduino.cc/reference/en/libraries/freertos/)\n"));
	msg_prnt(F("OneWire  - Various Authors, maintained by Paul Stroffregen\n"
	      "     (https://www.arduino.cc/reference/en/libraries/onewire/)\n"));
	msg_prnt(F("DallasTemperature - Miles Burton\n"
	      "     (https://www.arduino.cc/reference/en/libraries/dallastemperature/)\n"));
	msg_prnt(F("PID - Brett Beauregard\n"
	      "     (https://www.arduino.cc/reference/en/libraries/pid/)\n"));

	msg_prnt(F("_______________________________________________________\n"))
	msg_prnt(F("Beginning Bootup\n\
         ___             __      _                __\n\
        /   |  _________/ /_  __(_)___  ____     / /   ____ _____ ___  ____\n\
       / /| | / ___/ __  / / / / / __ \\/ __ \\   / /   / __ `/ __ `__ \\/ __ \\\n\
      / ___ |/ /  / /_/ / /_/ / / / / / /_/ /  / /___/ /_/ / / / / / / /_/ /\n\
     /_/  |_/_/   \\__,_/\\__,_/_/_/ /_/\\____/  /_____/\\__,_/_/ /_/ /_/ .___/\n\
                                                                   /_/\n"));
}

void TaskNotification(void *pvParameters);
void digitalPinInterruptHandler();

#endif