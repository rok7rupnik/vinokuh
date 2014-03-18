#include "display.h"

// **************** INIT ******************

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
	GPIO_WriteBit(D4_Port, (uint16_t) D4_Pin, (BitAction) ((int) data % 2));
	data /= 2;
	
	GPIO_WriteBit(D5_Port, (uint16_t) D5_Pin, (BitAction) ((int) data % 2));
	data /= 2;
	
	GPIO_WriteBit(D6_Port, (uint16_t) D6_Pin, (BitAction) ((int) data % 2));
	data /= 2;
	
	GPIO_WriteBit(D7_Port, (uint16_t) D7_Pin, (BitAction) ((int) data % 2));
}

void LCD_Command(char cmd)
{
	GPIO_ResetBits(EN_Port, EN_Pin);
	GPIO_ResetBits(RS_Port, RS_Pin);

	// Spreminjam na us za hitrejse osvezevanje
	// LCD ima "settling time" 37 us
	// V 4-bitnem nacinu potrebno posiljati dvakrat, zato cakam 80 us
	
	delay_us(COMMAND_DELAY);
	LCD_Send(cmd >> 4);
	GPIO_SetBits(EN_Port, EN_Pin);
	delay_us(COMMAND_DELAY);
	GPIO_ResetBits(EN_Port, EN_Pin);
	delay_us(COMMAND_DELAY);
	LCD_Send(cmd & 0xf);
	GPIO_SetBits(EN_Port, EN_Pin);
	delay_us(COMMAND_DELAY);
	GPIO_ResetBits(EN_Port, EN_Pin);
	delay_us(COMMAND_DELAY);
	
	/*
	delay_ms(2);
	LCD_Send(cmd >> 4);
	GPIO_SetBits(EN_Port, EN_Pin);
	delay_ms(2);
	GPIO_ResetBits(EN_Port, EN_Pin);
	delay_ms(6);
	LCD_Send(cmd & 0xf);
	GPIO_SetBits(EN_Port, EN_Pin);
	delay_ms(2);
	GPIO_ResetBits(EN_Port, EN_Pin);
	delay_ms(5);
	*/
}

void LCDInit()
{
	LCD_PinInit();
	delay_ms(20);
	GPIO_ResetBits(RS_Port, RS_Pin);
	LCD_Send(0x3);
	delay_ms(5);
	LCD_Send(0x2);
	delay_ms(5);
	LCD_Send(0x0);
	LCD_Command(0x28);
	LCD_Command(0x08);
	LCD_Command(0x01);
	LCD_Command(0x06);
	LCD_Command(0x0c);
	//LCD_Goto(1,2);
}

// **************** DRIVER ******************

int LCD_CTRL_REG = 0;
int LCD_STAT_REG = 0;
char LCD_STR[] = 	{0, 0, 0, 0, 0, 0, 0, 0,
					 0, 0, 0, 0, 0, 0, 0, 0,
					 0, 0, 0, 0, 0, 0, 0, 0, 
					 0, 0, 0, 0, 0, 0, 0, 0,
					 0, 0, 0, 0, 0, 0, 0, 0,
					 0, 0, 0, 0, 0, 0, 0, 0,
					 0, 0, 0, 0, 0, 0, 0, 0,
					 0, 0, 0, 0, 0, 0, 0, 0, 0};
//LCD_STR = "Oujea, misko! Vinokuh je zakon.";
char waitFlag = 1;
int i = 0;

void lcdDriver(){
	// Najprej pocakamo 1 cikel, da se izvede LCDInit()
	if(waitFlag){
		waitFlag = 0;
		return;
	}
	
	

	switch(LCD_CTRL_REG){
		case PRINTSTR:{
			clrscr();
			//LCD_Goto(1,0);
			printstrOS();
			LCD_CTRL_REG = 0;

			// Ce je niz daljsi od 32, ga zarotiramo in pustimo, da se vrti
			if(strlen(LCD_STR) > 32){
				rotateString();
				LCD_CTRL_REG = PRINTSTR;
			}
		}
	}

	return;
}


// **************** IZPIS ******************

void LCD_Goto(char vrsta, char stolpec)
{
	char command;
	if(vrsta == 1) command = 0x80;
	else if(vrsta == 2) command = 0xc0;
	else return;
	
	command += stolpec;
	LCD_Command(command);
}

void putch(char ch)
{	
	GPIO_ResetBits(EN_Port, EN_Pin);
	GPIO_SetBits(RS_Port, RS_Pin);
	delay_us(PUTCH_DELAY);
	LCD_Send(ch >> 4);
	GPIO_SetBits(EN_Port, EN_Pin);
	delay_us(PUTCH_DELAY);
	GPIO_ResetBits(EN_Port, EN_Pin);
	delay_us(PUTCH_DELAY);
	LCD_Send(ch & 0xf);
	delay_us(PUTCH_DELAY);
	GPIO_SetBits(EN_Port, EN_Pin);
	delay_us(PUTCH_DELAY);
	GPIO_ResetBits(EN_Port, EN_Pin);
	delay_us(PUTCH_DELAY);

	/*
	GPIO_ResetBits(EN_Port, EN_Pin);
	GPIO_SetBits(RS_Port, RS_Pin);
	delay_ms(2);
	LCD_Send(ch >> 4);
	GPIO_SetBits(EN_Port, EN_Pin);
	delay_ms(2);
	GPIO_ResetBits(EN_Port, EN_Pin);
	delay_ms(2);
	LCD_Send(ch & 0xf);
	delay_ms(2);
	GPIO_SetBits(EN_Port, EN_Pin);
	delay_ms(2);
	GPIO_ResetBits(EN_Port, EN_Pin);
	delay_ms(2);
	*/
}

// put character Row Column select
void putchRC(char vrsta, char stolpec, char ch)
{
	LCD_Goto(vrsta, stolpec);
	putch(ch);
}

void putstr(char *str)
{
	int i;
	
	for(i=0; str[i]; i++) putch(str[i]);
}

void putstrRC(char vrsta, char stolpec, char *str)
{
	LCD_Goto(vrsta, stolpec);
	putstr(str);
}

void printstr(char *str){
	int i;
	// Prikazuje znake, dokler ne pride do konca vrstic (ce smo zaceli na zacetku), ali je prej konec stringa
	for(i=0; i < 16 && str[i]; i++) putch(str[i]);
	// Nova vrstica, prikazujemo naprej
	LCD_Goto(2,0);
	for(; i < 32 && str[i]; i++) putch(str[i]);
}
void printstrOS(){
	int i;
	// Prikazuje znake na naslovu LCD_STR in na nobenem drugem!!!
	// najprej prva vrstica
	for(i=0; i < 16 && LCD_STR[i]; i++) putch(LCD_STR[i]);
	// Nova vrstica, prikazujemo naprej
	LCD_Goto(2,0);
	for(; i < 32 && LCD_STR[i]; i++) putch(LCD_STR[i]);
}

void clrscr()
{
	LCD_Command(0x01);
	LCD_Goto(1,0);
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

// ***************** STRING ********************

void rotateString(){
	// Shranimo prvi znak
	char first = LCD_STR[0];
	// Zanka - zacnemo pri drugem in pisemo enega nazaj
	int i = 1;
	while(LCD_STR[i]){
		LCD_STR[i-1] = LCD_STR[i];
		i++;
	}
	// Na zadnjega vpisemo prvega
	LCD_STR[i-1] = first;

	return;
}

void strExport(char* str){
	int i;
	for(i = 0; i < strlen(str); i++){
		LCD_STR[i] = str[i];
	}
}
