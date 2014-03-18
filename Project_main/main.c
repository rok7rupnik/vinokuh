#include <stm32f4xx.h>
#include "gpio.h"
#include "adc.h"
#include "switch.h"

// ***************** OS *********************
 
#define RR_LENGTH 10
int RR_COUNTER = 0;
void (*ROUND_ROBIN[RR_LENGTH])(void);

void dummyDriver(void) {return;}

//needs GPIOD timer enabled to work
void osInit(void)
{	
	ROUND_ROBIN[0] = dummyDriver;
	ROUND_ROBIN[1] = dummyDriver;
	ROUND_ROBIN[2] = dummyDriver;
	ROUND_ROBIN[3] = dummyDriver;
	ROUND_ROBIN[4] = dummyDriver;
	ROUND_ROBIN[5] = dummyDriver;
	ROUND_ROBIN[6] = dummyDriver;
	ROUND_ROBIN[7] = dummyDriver;
	ROUND_ROBIN[8] = dummyDriver;
	ROUND_ROBIN[9] = dummyDriver;
	
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
		(*ROUND_ROBIN[RR_COUNTER])();
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
}
