#include <stm32f4xx.h>
#include "ledfunction.h"

int readKey(){
	return GPIO_ReadInputDataBit(GPIOA, KEY);
}

int main(void){
	int temp;
	
	LEDInit();
	keyInit();	
	
	while(1){
		temp = readKey();
		
		if(temp == 1){
			setLED(LED1 | LED2 | LED3 | LED4);
		}	else {
			clrLED(LED1 | LED2 | LED3 | LED4);
		}
		
	}
	
	
	
	
}
