#include <stm32f4xx.h>
#include <stdio.h>
#include <string.h>
#include "gpio.h"
#include "adc.h"
#include "encoder.h"
#include "display.h"
#include "timer.h"
#include "switch.h"
#define CH 10
#define DELAY 500

/***************** Driver registers ********************/
extern int LCD_CTRL_REG;
extern int A_VALUE;
extern int B_VALUE;

/*************** Example Driver ******************/

int SET_REG = 0;
int CONF_REG = 0; //confirm
//uint32_t counter = 0;
uint32_t time, tmp;

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
	
	/*
	setLED(LED0 |LED1 |LED2 |LED3);
	
	delay_ms(5000);
	
	clrLED(LED0 |LED1 |LED2 |LED3);
	*/
	
	//if(counter++ > 4) putchRC(1, 0, 'O');
	
	return;
}


/***************** OS *********************/

// 84000000 - 1 -> do toliko presteje timer v eni sekundi
 
#define RR_LENGTH 10
int RR_COUNTER = 0;
void (*ROUND_ROBIN[RR_LENGTH])(void);

void dummyDriver(void) {return;}

//needs GPIOD timer enabled to work
void osInit(void)
{	
	ROUND_ROBIN[0] = testDriver;
	ROUND_ROBIN[1] = lcdDriver;
	ROUND_ROBIN[2] = dummyDriver;
	ROUND_ROBIN[3] = dummyDriver;
	ROUND_ROBIN[4] = dummyDriver;
	ROUND_ROBIN[5] = dummyDriver;
	ROUND_ROBIN[6] = dummyDriver;
	ROUND_ROBIN[7] = dummyDriver;
	ROUND_ROBIN[8] = dummyDriver;
	ROUND_ROBIN[9] = dummyDriver;
	
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

void TIM2_IRQHandler(unsigned int par) {
  if (TIM2->SR & TIM_SR_UIF) 
	{
		(*ROUND_ROBIN[RR_COUNTER])();
		RR_COUNTER = (RR_COUNTER+1)%RR_LENGTH;
	}
  TIM2->SR = 0x0; // reset the status register - ne brisi
}


void ADC1Test(){
	int tTemp;
	int t;
	int time;
	t = ADCRead(11);
	time = clock();

	while(1){		
		if (clock() - time > DELAY){
			time = clock();
			tTemp = ADCRead(11);
			//t = ADC1Read(10) / 204;
			clrLED(LED0 | LED1 | LED2 | LED3 );
			//toggleLED(GPIO_Pin_2);
			//toggleLED(LED3);			
			
			
			if (tTemp > t){
				setLED(LED2);
			}
			else if (tTemp < t){
				setLED(LED3);
			}
			else{
				setLED(LED0);
			}
			t = tTemp;
		}
	}
}
void toggleSwitch(void){
	int time;

	while(1){
		
		if (clock() - time > DELAY){
			time = clock();
			//clrLED(LED0 | LED1 | LED2 | LED3 );
			//toggleLED(GPIO_Pin_2);
			toggleLED(LED0 | LED1 | LED2 | LED3);
			
		}
	}
}

int main(void){
	//int tTemp;
	//int t;
	//int time;
	//int i = 0;
	
	//char str[] = {0, 0, 0, 0};
	char str[] = "Oujea misko!";
	strExport(str);
	
	// **************** INIT ******************
	ADCInit();
	gpioTimerInit();
	LEDInit();
	encoderInit();
	//switchInit();
	//timerInit();
	//timer2Init();	
	
	osInit();
	LCDInit();
	
	// **************** true stuff ******************
	clrLED(LED0 | LED1 | LED2 | LED3 );
	clrscr();
	
	LCD_CTRL_REG = PRINTSTR;
	
	//ADC1Test();

	//printstr(str);
	//LCD_Goto(1,6);
	//putch('0');

	while (1)
	{
		/*str[0] = A_VALUE;
		str[2] = B_VALUE;
		
		strExport(str);
		LCD_CTRL_REG = PRINTSTR;*/
		
		/*if(CONF_REG)
		{
			SET_REG = (SET_REG+1)%4;
			CONF_REG = 0;
		}*/
	}
		
	/*
		
	switch(t){
		case 1: setLED(LED0);break;
		case 2: setLED(LED0 | LED1);break;
		case 3: setLED(LED0 | LED1 | LED2);break;
		case 4: setLED(LED0 | LED1 | LED2 | LED3);break;
		case 0: ;

	*/
}
