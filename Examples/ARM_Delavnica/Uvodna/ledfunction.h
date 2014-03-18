#include "stm32f4xx.h"

#define LED1 GPIO_Pin_12
#define LED2 GPIO_Pin_13
#define LED3 GPIO_Pin_14
#define LED4 GPIO_Pin_15
#define KEY GPIO_Pin_0

void LEDInit(void);
void setLED(uint16_t i);
void clrLED(uint16_t i);

void delay(int i);

void keyInit(void);
