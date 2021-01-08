#ifndef ARDUINO_LAMP_FAILSAFE
#define ARDUINO_LAMP_FIALSAFE

#include <main.h>

/*________________Arduino LED Lamp Failsafe Shutdown_______________
Cuts power to various systems on the board. Calledin case of anomaly.
*/

//____________________________Functions____________________________

//Shutdown functions of the lamp depending on the input
void failSafe(byte err_type);

//Blink Codes to show error state
void blinkCode(byte err_type);

//____________________________Constants____________________________

#define OTP 1
#define ALL 0

//________________________Blink Code Macros________________________

#define LONG_DELAY  for (int i = 0; i < 375; i++) { \
                        delayMicroseconds(50000U);  \
                    } 

#define SHORT_DELAY for (int i = 0; i < 75; i++) {  \
                        delayMicroseconds(50000U);  \
                    }

#define END_DELAY   for (int i = 0; i < 1000; i++) {\
                        delayMicroseconds(50000U);  \
                    }

#define ON(time)      digitalWrite(LED_BUILTIN, HIGH); time;
#define OFF(time)     digitalWrite(LED_BUILTIN, LOW);  time;


#endif