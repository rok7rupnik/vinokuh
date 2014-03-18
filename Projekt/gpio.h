#include "stm32f4xx.h"

//*** Define
#define LED0 GPIO_Pin_12
#define LED1 GPIO_Pin_13
#define LED2 GPIO_Pin_14
#define LED3 GPIO_Pin_15

#define KEY GPIO_Pin_0

void LEDInit(void);
void setLED(unsigned int);
void clrLED(unsigned int);
void toggleLED(unsigned int);
void keyInit(void);
void switchInit(void);
int getch(void);
int readKey(void);
int clock(void);
void timerInit(void);
void SysTick_Handler(void);
