#include "gpio.h"

int clockCounter;


void LEDInit() {
	GPIO_InitTypeDef predalnik;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE); //vklop ure na periferiji
	
	predalnik.GPIO_Pin = (LED1 | LED2 | LED3 |LED4);
	predalnik.GPIO_Mode = GPIO_Mode_OUT;
	predalnik.GPIO_Speed = GPIO_Speed_100MHz;
	predalnik.GPIO_OType = GPIO_OType_PP;
	predalnik.GPIO_PuPd = GPIO_PuPd_NOPULL;
	GPIO_Init(GPIOD, &predalnik); // Uveljavitev nastavitev
}

void setLED(unsigned int state) {
	if (state > 15) return; // napacni podatki
	GPIO_SetBits(GPIOD, state << 12); // Spremeni stanje na LED
}

void clrLED(unsigned int state) {
	if (state > 15) return; // napacni podatki
	GPIO_ResetBits(GPIOD, state << 12); // Spremeni stanje na LED
}
void toggleLED(unsigned int state) {
	if (state > 15) return; // napacni podatki
	GPIO_ToggleBits(GPIOD, state << 12); // Spremeni stanje na LED
}
void keyInit() {
	GPIO_InitTypeDef PORTA;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	PORTA.GPIO_Pin = (GPIO_Pin_0);
	PORTA.GPIO_Mode = GPIO_Mode_IN;
	PORTA.GPIO_Speed = GPIO_Speed_100MHz;
	PORTA.GPIO_OType = GPIO_OType_PP;
	PORTA.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_Init(GPIOA, &PORTA);
}
int getch() {
	while (!GPIO_ReadInputDataBit(GPIOA, GPIO_Pin_0));
	return 1;
}
void TimerInit() {
	SysTick_Config(SystemCoreClock/1000); // zacnemo SysTick, ki ga prozimo vsako ms
	clockCounter = 0;
}
void SysTick_Handler(){
	clockCounter++;
}
int clock() {
	return clockCounter;
}
