#include <stm32f4xx.h>
#include "gpio.h"
#include "adc.h"
#define CH 10
#define DELAY 1000

int main(void){
	// int tTemp;
	int t;
	int time;
	//int i = 0;
	
	ADC1Init();
	LEDInit();
	clrLED(LED0 | LED1 | LED2 | LED3 );
	timerInit();
	switchInit();
	
	t = ADC1Read();
	time = clock();
	
	
	while(1){
		
		if (clock() - time > DELAY){
			time = clock();
			//tTemp = ADC1Read();
			t = ADC1Read() / 204;
			//clrLED(LED0 | LED1 | LED2 | LED3 );
			toggleLED(GPIO_Pin_2);
			toggleLED(LED3);			
			
			/*
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
			*/
			
			switch(t){
				case 1: setLED(LED0);break;
				case 2: setLED(LED0 | LED1);break;
				case 3: setLED(LED0 | LED1 | LED2);break;
				case 4: setLED(LED0 | LED1 | LED2 | LED3);break;
				case 0: ;
			}
			
		}
	}
	
	
}
