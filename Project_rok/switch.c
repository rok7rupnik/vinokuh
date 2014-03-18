#include "switch.h"

/*
	Driver za stikalo
	Po potrebi dodaj pine, ce se le, naj bojo na istem sklopu (GPIOx)
*/

/*
	Init stikala
	Trenutno je izbran pin PD2
	Isti sklop kot ledice (GPIOD)
*/
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

/*
	Razmisljal sem o funkciji za on/off
	Splaca se jih narediti (skopirati iz ledic), potem, ko bojo izbrani pini (oz, njihov sklop)
	No, najverjetneje bom to delal jaz - pase k logiki
	
	Do takrat glej funkcije v driverju za ledice
*/
