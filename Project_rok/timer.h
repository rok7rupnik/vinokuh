#include "stm32f4xx.h"

#define S_COUNT 84000000 - 1
#define MS_COUNT 84000 - 1
#define US_COUNT 84 - 1

void timerInit(void);
void timer2Init(void);
void SysTick_Handler(void);
int clock(void);
void delay_ms(uint32_t time);
void delay_us(uint32_t time);
