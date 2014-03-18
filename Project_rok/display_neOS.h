#include "stm32f4xx.h"

// ************** Pins ******************

#define	D4_Pin	GPIO_Pin_0
#define D4_Port	GPIOE
#define D4_Clk 	RCC_AHB1Periph_GPIOE
#define D5_Pin	GPIO_Pin_1
#define D5_Port	GPIOE
#define D5_Clk 	RCC_AHB1Periph_GPIOE
#define D6_Pin	GPIO_Pin_2
#define D6_Port	GPIOE
#define D6_Clk 	RCC_AHB1Periph_GPIOE
#define D7_Pin	GPIO_Pin_3
#define D7_Port	GPIOE
#define D7_Clk 	RCC_AHB1Periph_GPIOE
#define RS_Pin	GPIO_Pin_4
#define RS_Port	GPIOE
#define RS_Clk 	RCC_AHB1Periph_GPIOE
#define EN_Pin	GPIO_Pin_5
#define EN_Port	GPIOE
#define EN_Clk 	RCC_AHB1Periph_GPIOE

extern void delay_ms(uint32_t time);

// ************** Init ******************

void LCDInit(void);
void LCD_PinInit(void);
void LCD_Send(char data);
void IntToStr(char *str, int INT, char dol);
void LCD_Command(char cmd);

// ************** Driver ******************

void lcdDriver(void);

// ************** Printing ******************

void putch(char ch);
void putchRC(char vrsta, char stolpec, char ch);
void putstr(char *str);
void putstrRC(char vrsta, char stolpec, char *str);
void printstr(char *str);
void clrscr(void);
void LCD_Goto(char vrsta, char stolpec);
