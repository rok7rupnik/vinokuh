#include "timer.h"

/*
	Driver za privzeti casovnik na ploscici
	
	Dodal bom se init in funkcije za kak proper timer, da ne bomo delal zank za delay
*/

int clockCounter;

void timer2Init(){
	// Premaknil init Timerja 2, ker ga potrebujem za LCD
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	NVIC->ISER[0] |= 1<< (TIM2_IRQn); // enable the TIM2 IRQ	
	
	TIM2->PSC = 0x0; // no prescaler, timer counts up in sync with the peripheral clock
	TIM2->DIER |= TIM_DIER_UIE; // enable update interrupt
	TIM2->ARR = 50 * MS_COUNT; // count to 1 (autoreload value 1) - x10, da dobimo interval enega driverja
	TIM2->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // autoreload on, counter enabled
	TIM2->EGR = 1; // trigger update event to reload timer registers
	
	//tim2->arr lahk damo se v spremenljivko
	// Podano vrednost mnozim
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
void delay_ms(uint32_t time){
	/* Stara verzija
	int start = clock();
	while((clock() - start) < time);
	*/
	// Verzija za OS - gledamo register nasega timerja TIM2
	int start = TIM2->CNT;
	while((TIM2->CNT - start) < time * MS_COUNT);
	return;
}
void delay_us(uint32_t time){
	// Verzija za OS - gledamo register nasega timerja TIM2
	int start = TIM2->CNT;
	while((TIM2->CNT - start) < time * US_COUNT);
	return;
}
