#include "ledfunction.h"
#include "stm32f4xx_conf.h"

/**
  ******************************************************************************
  * @file    ledfunction.c																										 *
  * @author  Jernej Podlipnik																									 *
  * @version V0.0.1																														 *
  * @date    March 2013																												 *
  * @brief   This file provides function to initalize and manage the following:*          
  *           - Initalization of LEDs																					 *
  *           - Turinng on and off LEDs																				 *
  *           - a simple delay function																				 *
	*						-	function to intalize the user push button										   *
  ******************************************************************************
**/

/******************************************************************
* 																																*
* LEDInit() is a function to initialize the LED ports as outputs. *
*																																	*
******************************************************************/
void LEDInit(void) {
	// A struct, needed for initialization
	GPIO_InitTypeDef drawer;
	// Turns on the clock of GPIOD Peripheral
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	// Specifies ports that will be configured
	drawer.GPIO_Pin = LED1 | LED2 | LED3 | LED4;
	// Sets the ports as outputs
	drawer.GPIO_Mode = GPIO_Mode_OUT;
	// Sets port speeds to maximum
	drawer.GPIO_Speed = GPIO_Speed_100MHz;
	// Type of output, which will force its
	// state as High or Low
	drawer.GPIO_OType = GPIO_OType_PP;
	// We turrn off all PullUp and PullDown
	// resistors
	drawer.GPIO_PuPd = GPIO_PuPd_NOPULL;
	// Initalizes the LED ports with all specifications
	// written above
	GPIO_Init(GPIOD, &drawer);
};



/******************************************************************
* 																																*
* setLED() is a function to set LED ports in High state - to turn	*
* the LEDs on																											*
* Pay attention: LEDx is type uint16_t!														*
******************************************************************/

void setLED(uint16_t i){
	
	GPIO_SetBits(GPIOD, i);
};

/******************************************************************
* 																																*
* clrLED() is a function to set LED ports in Low state - to turn	*
* the LEDs off 																										*
* Pay attention: LEDx is type uint16_t!														*
******************************************************************/

void clrLED(uint16_t i) {

	//strcmp(&leds,LED1);
	GPIO_ResetBits(GPIOD, i);
};

/******************************************************************
* 																																*
* keyInit() is a function to set up the user push button					*
* 																																*
******************************************************************/

void keyInit(void){
	// A struct, needed for initialization
	GPIO_InitTypeDef drawer;
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	drawer.GPIO_Pin = KEY;
	drawer.GPIO_Mode = GPIO_Mode_IN;
	drawer.GPIO_Speed = GPIO_Speed_2MHz;
	drawer.GPIO_OType = GPIO_OType_PP;
	drawer.GPIO_PuPd = GPIO_PuPd_NOPULL; // When key is pressed, the output is at high state!
	GPIO_Init(GPIOA, &drawer);
};
/******************************************************************
* 																																*
* delay() is a function which roughly makes a delay in ms					*
* 																																*
******************************************************************/

void delay(int i) {
	uint32_t t;
	t = (uint32_t)i * 46000;
	while(t--); //one cycle takes ~60 ns
};

