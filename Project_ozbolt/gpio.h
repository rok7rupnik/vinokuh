#include "stm32f4xx.h"

// ********** Miscellaneous ************

void gpioTimerInit(void);
void gpioInit(uint16_t GPIO_Pins,						\
							GPIOMode_TypeDef GPIO_Mode,  	\
							GPIOOType_TypeDef GPIO_OType, \
							GPIOPuPd_TypeDef GPIO_PuPd,		\
							GPIO_TypeDef* GPIO_abcd);

// ************* Encoder ***************

#define DECODER_PIN_A 
#define DECODER_PIN_B

void encoderInit(void);

// ************** LED ******************

#define LED0 GPIO_Pin_12
#define LED1 GPIO_Pin_13
#define LED2 GPIO_Pin_14
#define LED3 GPIO_Pin_15

#define allLED (LED0|LED1|LED2|LED3)

void LEDInit(void);
void setLED(unsigned int);
void clrLED(unsigned int);
void toggleLED(unsigned int);

// ************** keys ******************

#define KEY_0 GPIO_Pin_0
#define KEY_1 GPIO_Pin_1
#define KEY_2 GPIO_Pin_2

void keyInit(void);
int getch(unsigned int);
int readKey(unsigned int);
