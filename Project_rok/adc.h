#include "stm32f4xx.h"

/******************** Pini ************************/

#define TS1_Pin     GPIO_Pin_2
#define TS1_Port    GPIOC
#define TS1_Clk     RCC_AHB1Periph_GPIOC
#define TS2_Pin     GPIO_Pin_0
#define TS2_Port    GPIOA
#define TS2_Clk     RCC_AHB1Periph_GPIOA
#define TS3_Pin     GPIO_Pin_2
#define TS3_Port    GPIOA
#define TS3_Clk     RCC_AHB1Periph_GPIOA
#define TS4_Pin     GPIO_Pin_4
#define TS4_Port    GPIOA
#define TS4_Clk     RCC_AHB1Periph_GPIOA
#define TS5_Pin     GPIO_Pin_6
#define TS5_Port    GPIOA
#define TS5_Clk     RCC_AHB1Periph_GPIOA
#define TS6_Pin     GPIO_Pin_4
#define TS6_Port    GPIOC
#define TS6_Clk     RCC_AHB1Periph_GPIOC
#define TS7_Pin     GPIO_Pin_0
#define TS7_Port    GPIOB
#define TS7_Clk     RCC_AHB1Periph_GPIOB
#define TS8_Pin     GPIO_Pin_1
#define TS8_Port    GPIOB
#define TS8_Clk     RCC_AHB1Periph_GPIOB

/********** Init ************/

/********** Funkcije ************/

void    ADCInit(void);
void    TS_PinInit(void);
void    ADC1_Init(void);
int     ADCRead(u8 channel);
int     ADC1_Read(u8 channel);
void    ADCTest(void);
//int   ADC1Read(void);
int     TS_Read(u8 level);
