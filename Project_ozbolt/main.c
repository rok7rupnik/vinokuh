#include <stm32f4xx.h>
#include "gpio.h"
#include "adc.h"
#include "switch.h"

// *************** Example Driver ******************

//driverji bojo po ostalih datotekah, sam za pokazat delovanje je tu en testn:

int SET_REG = 0;
int CONF_REG = 0; //confirm

void testDriver(void)
{
	switch(SET_REG)
	{
		case 0:
			toggleLED(LED0); break;
		case 1:
			toggleLED(LED1); break;
		case 2:
			toggleLED(LED2); break;
		case 3:
			toggleLED(LED3); break;
	}		
	CONF_REG = 1;
}


// ***************** OS *********************
 
#define RR_LENGTH 10
int RR_COUNTER = 0;
void (*ROUND_ROBBIN[RR_LENGTH])(void);

void dummyDriver(void) {return;}

//needs GPIOD timer enabled to work
void osInit(void)
{	
	ROUND_ROBBIN[0] = testDriver;
	ROUND_ROBBIN[1] = dummyDriver;
	ROUND_ROBBIN[2] = dummyDriver;
	ROUND_ROBBIN[3] = dummyDriver;
	ROUND_ROBBIN[4] = dummyDriver;
	ROUND_ROBBIN[5] = dummyDriver;
	ROUND_ROBBIN[6] = dummyDriver;
	ROUND_ROBBIN[7] = dummyDriver;
	ROUND_ROBBIN[8] = dummyDriver;
	ROUND_ROBBIN[9] = dummyDriver;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
	NVIC->ISER[0] |= 1<< (TIM2_IRQn); // enable the TIM2 IRQ
	 
	TIM2->PSC = 0x0; // no prescaler, timer counts up in sync with the peripheral clock
	TIM2->DIER |= TIM_DIER_UIE; // enable update interrupt
	TIM2->ARR = 5000000; // count to 1 (autoreload value 1)
	TIM2->CR1 |= TIM_CR1_ARPE | TIM_CR1_CEN; // autoreload on, counter enabled
	TIM2->EGR = 1; // trigger update event to reload timer registers
	
	//tim2->arr lahk damo se v spremenljivko -> tist doloca hitrost prozenja interruptov
	//pa zracunat bo tut treba, kolk hitr se prozi.
}

void TIM2_IRQHandler(unsigned int par) {
  if (TIM2->SR & TIM_SR_UIF) 
	{
		(*ROUND_ROBBIN[RR_COUNTER])();
		RR_COUNTER = (RR_COUNTER+1)%RR_LENGTH;
	}
  TIM2->SR = 0x0; // reset the status register - ne brisi
}

// ************** MAIN *****************

 
int main(void)
{	
	gpioTimerInit();
	LEDInit();
	osInit();
	
	while (1)
	{
		if(CONF_REG)
		{
			SET_REG = (SET_REG+1)%4;
			CONF_REG = 0;
		}
	}
}
