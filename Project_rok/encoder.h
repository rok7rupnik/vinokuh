#include "stm32f4xx.h"
#include "string.h"

/************** Pins ******************/

#define E1_Pin  GPIO_Pin_8
#define E1_Port GPIOB
#define E1_Clk  RCC_AHB1Periph_GPIOB
#define E2_Pin  GPIO_Pin_6
#define E2_Port GPIOE
#define E2_Clk  RCC_AHB1Periph_GPIOB

extern void delay_ms(uint32_t time);
extern void delay_us(uint32_t time);

/************** Init ******************/

void encoderInit(void);

/************** Driver ******************/
void encoderDriver(void);

/************** General ******************/
int encoderReadA(void);
int encoderReadB(void);
