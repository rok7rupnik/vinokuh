#include "timer.h"

/*
	Driver za privzeti casovnik na ploscici
	
	Dodal bom se init in funkcije za kak proper timer, da ne bomo delal zank za delay
*/

int clockCounter;

void timer2Init(){
	
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
