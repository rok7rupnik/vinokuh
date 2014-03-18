#include <stm32f4xx.h>

void ISP_pin_init(void){		
	// Struktura za init gpio pinov
	GPIO_InitTypeDef ledInitStruct;
	// Na GPIOD pripeljemo uro (vodilo AHB)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	// Kater pine izberemo
	ledInitStruct.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	// Ali bojo vhodni ali izhodni
	ledInitStruct.GPIO_Mode = GPIO_Mode_AF;
	// Njihova hitrost
	ledInitStruct.GPIO_Speed = GPIO_Speed_100MHz;
	// PushPull ali OpenDrain
	ledInitStruct.GPIO_OType = GPIO_OType_PP;
	// Naj procesor ne uporablja svojih pull down/up uporov
	ledInitStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource12, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource13, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource14, GPIO_AF_TIM4);
	GPIO_PinAFConfig(GPIOD, GPIO_PinSource15, GPIO_AF_TIM4);
	
	GPIO_Init(GPIOD, &ledInitStruct);
}

int main(){
	
	
	while(1);
	return 0;
}
