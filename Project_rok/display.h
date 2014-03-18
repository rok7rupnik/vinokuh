#include "stm32f4xx.h"
#include "string.h"

// ************** Pins ******************

#define	D4_Pin	GPIO_Pin_5
#define D4_Port	GPIOD
#define D4_Clk 	RCC_AHB1Periph_GPIOD
#define D5_Pin	GPIO_Pin_3
#define D5_Port	GPIOD
#define D5_Clk 	RCC_AHB1Periph_GPIOD
#define D6_Pin	GPIO_Pin_1
#define D6_Port	GPIOD
#define D6_Clk 	RCC_AHB1Periph_GPIOD
#define D7_Pin	GPIO_Pin_12
#define D7_Port	GPIOC
#define D7_Clk 	RCC_AHB1Periph_GPIOC
#define RS_Pin	GPIO_Pin_10
#define RS_Port	GPIOC
#define RS_Clk 	RCC_AHB1Periph_GPIOC
#define EN_Pin	GPIO_Pin_14
#define EN_Port	GPIOA
#define EN_Clk 	RCC_AHB1Periph_GPIOA

extern void delay_ms(uint32_t time);
extern void delay_us(uint32_t time);

// ************** Init ******************
#define COMMAND_DELAY 1000

void LCDInit(void);
void LCD_PinInit(void);

void LCD_Send(char data);
void IntToStr(char *str, int INT, char dol);
void LCD_Command(char cmd);

// ************** Driver ******************

#define PRINTSTR 1

void lcdDriver(void);

// ************** Printing ******************

#define PUTCH_DELAY 200

void putch(char ch);
void putchRC(char vrsta, char stolpec, char ch);
void putstr(char *str);
void putstrRC(char vrsta, char stolpec, char *str);
void printstr(char *str);
void printstrOS(void);
void clrscr(void);
void LCD_Goto(char vrsta, char stolpec);

// ************** String ******************

void rotateString(void);
void strExport(char* str);
