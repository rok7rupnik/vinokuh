#include "gpio.h"

int clockCounter;


void LEDInit() {
	GPIO_InitTypeDef gpiod;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); //vklop ure na periferiji
	
	gpiod.GPIO_Pin = (LED1 | LED2 | LED3 |LED0 | GPIO_Pin_0);
	gpiod.GPIO_Mode = GPIO_Mode_OUT;
	gpiod.GPIO_Speed = GPIO_Speed_100MHz;
	gpiod.GPIO_OType = GPIO_OType_PP;
	gpiod.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &gpiod); // Uveljavitev nastavitev
}

void setLED(unsigned int state) {
	GPIO_SetBits(GPIOD, state); // Spremeni stanje na LED
}

void clrLED(unsigned int state) {
	GPIO_ResetBits(GPIOD, state); // Spremeni stanje na LED
}
void toggleLED(unsigned int state) {
	GPIO_ToggleBits(GPIOD, state); // Spremeni stanje na LED
}
void keyInit() {
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	GPIO_InitStruct.GPIO_Pin = (GPIO_Pin_0);
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_PP;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA, &GPIO_InitStruct);
}
void switchInit() {
	GPIO_InitTypeDef GPIO_InitStruct;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	GPIO_InitStruct.GPIO_Pin = (GPIO_Pin_2);
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_OUT;
	GPIO_InitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	GPIO_InitStruct.GPIO_OType = GPIO_OType_OD;
	GPIO_InitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOD, &GPIO_InitStruct);
}
int getch() {
	while (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0));
	return 1;
}
int readKey(){
	return GPIO_ReadInputDataBit(GPIOA, KEY);
}
void timerInit() {
	SysTick_Config(SystemCoreClock/1000); // zacnemo SysTick, ki ga prozimo vsako ms
	clockCounter = 0;
}
void SysTick_Handler(){
	clockCounter++;
}
int clock() {
	return clockCounter;
}
