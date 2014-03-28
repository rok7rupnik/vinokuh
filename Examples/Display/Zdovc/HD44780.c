#include "HD44780.h"

void LCD_Send(char data);
void LCD_PinInit(void);

void LCD_PinInit() {
	
	GPIO_InitTypeDef initStruct;
	
	initStruct.GPIO_Mode = GPIO_Mode_OUT;
	initStruct.GPIO_Speed = GPIO_Speed_100MHz;
	initStruct.GPIO_OType = GPIO_OType_PP;
	initStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	RCC_AHB1PeriphClockCmd(D4_Clk, ENABLE);
	initStruct.GPIO_Pin = (D4_Pin);
	GPIO_Init(D4_Port, &initStruct);
	
	RCC_AHB1PeriphClockCmd(D5_Clk, ENABLE);
	initStruct.GPIO_Pin = (D5_Pin);
	GPIO_Init(D5_Port, &initStruct);
	
	RCC_AHB1PeriphClockCmd(D6_Clk, ENABLE);
	initStruct.GPIO_Pin = (D6_Pin);
	GPIO_Init(D6_Port, &initStruct);
	
	RCC_AHB1PeriphClockCmd(D7_Clk, ENABLE);
	initStruct.GPIO_Pin = (D7_Pin);
	GPIO_Init(D7_Port, &initStruct);
	
	RCC_AHB1PeriphClockCmd(RS_Clk, ENABLE);
	initStruct.GPIO_Pin = (RS_Pin);
	GPIO_Init(RS_Port, &initStruct);
	
	RCC_AHB1PeriphClockCmd(EN_Clk, ENABLE);
	initStruct.GPIO_Pin = (EN_Pin);
	GPIO_Init(EN_Port, &initStruct);
}

void LCD_Send(char data)
{
	GPIO_WriteBit(D4_Port, D4_Pin, data % 2);
	data /= 2;
	
	GPIO_WriteBit(D5_Port, D5_Pin, data % 2);
	data /= 2;
	
	GPIO_WriteBit(D6_Port, D6_Pin, data % 2);
	data /= 2;
	
	GPIO_WriteBit(D7_Port, D7_Pin, data % 2);
}

void LCD_Command(char cmd)
{
	GPIO_ResetBits(EN_Port, EN_Pin);
	GPIO_ResetBits(RS_Port, RS_Pin);
	Delay_ms(2);
	LCD_Send(cmd >> 4);
	GPIO_SetBits(EN_Port, EN_Pin);
	Delay_ms(2);
	GPIO_ResetBits(EN_Port, EN_Pin);
	Delay_ms(6);
	LCD_Send(cmd & 0xf);
	GPIO_SetBits(EN_Port, EN_Pin);
	Delay_ms(2);
	GPIO_ResetBits(EN_Port, EN_Pin);
	Delay_ms(5);
}

void LCDInit()
{
	LCD_PinInit();
	Delay_ms(20);
	GPIO_ResetBits(RS_Port, RS_Pin);
	LCD_Send(0x3);
	Delay_ms(5);
	LCD_Send(0x2);
	Delay_ms(5);
	LCD_Send(0x0);
	LCD_Command(0x28);
	LCD_Command(0x08);
	LCD_Command(0x01);
	LCD_Command(0x06);
	LCD_Command(0x0c);
}

void LCD_Goto(char vrsta, char stolpec)
{
	char command;
	if(vrsta == 1) command = 0x80;
	else if(vrsta == 2) command = 0xc0; // Ne dela. Ne vem zakaj
	else return;
	
	command += stolpec;
	LCD_Command(command);
}

void putchCP(char ch)
{
	GPIO_ResetBits(EN_Port, EN_Pin);
	GPIO_SetBits(RS_Port, RS_Pin);
	Delay_ms(2);
	LCD_Send(ch >> 4);
	GPIO_SetBits(EN_Port, EN_Pin);
	Delay_ms(2);
	GPIO_ResetBits(EN_Port, EN_Pin);
	Delay_ms(2);
	LCD_Send(ch & 0xf);
	Delay_ms(2);
	GPIO_SetBits(EN_Port, EN_Pin);
	Delay_ms(2);
	GPIO_ResetBits(EN_Port, EN_Pin);
	Delay_ms(2);
}

void putch(char vrsta, char stolpec, char ch)
{
	LCD_Goto(vrsta, stolpec);
	putchCP(ch);
}

void putstrCP(char *str)
{
	int i;
	
	for(i=0; str[i]; i++) putchCP(str[i]);
}

void putstr(char vrsta, char stolpec, char *str)
{
	LCD_Goto(vrsta, stolpec);
	putstrCP(str);
}
	 

void clrscr()
{
	LCD_Command(0x01);
}

void IntToStr(char *str, int INT, char dol)	
{
	//Vpisi array v katerega se bo string shranil, nato string in nato dolzino izpisa
	//Ce je dolzina izpisa dolocena na nic, se bo nastavila sama
	int i, d;
	if(dol) d = dol;
	else if(INT <10) d = 1;
	else if(INT < 100) d = 2;
	else if(INT < 1000) d = 3;
	else if(INT < 10000) d = 4;
	else d = 5;
	
	str[d] = 0;
	
	for(i=0; i < d; i++)
	{
		str[d-i-1] = (INT % 10) + '0';
		INT /= 10;
	}

}