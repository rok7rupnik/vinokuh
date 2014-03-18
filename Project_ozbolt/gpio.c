#include "gpio.h"

// ********** GPIOInit ***************

void gpioTimerInit() {
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
}

void gpioInit(uint16_t GPIO_Pins,						\
							GPIOMode_TypeDef GPIO_Mode,  	\
							GPIOOType_TypeDef GPIO_OType, \
							GPIOPuPd_TypeDef GPIO_PuPd,		\
							GPIO_TypeDef* GPIO_abcd) 
{
	GPIO_InitTypeDef gpioT;

	gpioT.GPIO_Pin = GPIO_Pins;
	gpioT.GPIO_Speed = GPIO_Speed_100MHz;
	gpioT.GPIO_Mode = GPIO_Mode;
	gpioT.GPIO_OType = GPIO_OType;
	gpioT.GPIO_PuPd = GPIO_PuPd;
	GPIO_Init(GPIO_abcd, &gpioT); 
}


// ************** Encoder *****************

void encoderInit(void){
	
}

// ************** LED *********************

void LEDInit() {
	uint16_t GPIO_Pins = (LED0 | LED1 | LED2 | LED3);
	gpioInit(GPIO_Pins, GPIO_Mode_OUT, GPIO_OType_PP, GPIO_PuPd_NOPULL, GPIOD);
}

void setLED(unsigned int led) {
	GPIO_SetBits(GPIOD, led); // Spremeni stanje na LED
}
void clrLED(unsigned int led) {
	GPIO_ResetBits(GPIOD, led); // Spremeni stanje na LED
}
void toggleLED(unsigned int led) {
	GPIO_ToggleBits(GPIOD, led); // Spremeni stanje na LED
}

// *************** keys *******************

void keyInit() {
	uint16_t GPIO_Pins = (KEY_0 | KEY_1 | KEY_2);
	gpioInit(GPIO_Pins, GPIO_Mode_IN, GPIO_OType_PP, GPIO_PuPd_DOWN, GPIOA);
}
int getch(unsigned int KEY) {
	while (!GPIO_ReadInputDataBit(GPIOA, KEY));
	return 1;
}
int readKey(unsigned int KEY){
	return GPIO_ReadInputDataBit(GPIOA, KEY);
}
