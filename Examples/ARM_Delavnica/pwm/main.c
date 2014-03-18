#include <stm32f4xx.h>
#define PERIODA 100
#define PRIZIGAJ 1
#define UGASAJ 0

unsigned int milisCounter = 0;

void PWM_pin_init(void){		
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

void TIM4_init(){
	TIM_TimeBaseInitTypeDef timerInitStruct;
	
	RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM4, ENABLE);
	
	timerInitStruct.TIM_CounterMode = TIM_CounterMode_Up;
	timerInitStruct.TIM_ClockDivision = TIM_CKD_DIV1;
	timerInitStruct.TIM_Prescaler = 8400 - 1; // Prescaler presteje do podane vrednosti, ko pride cez, odda en cikel
	timerInitStruct.TIM_Period = PERIODA;
	timerInitStruct.TIM_RepetitionCounter = 0;
	TIM_TimeBaseInit(TIM4, &timerInitStruct);
	
	TIM_Cmd(TIM4, ENABLE);
}

void SysTick_Handler(void){
	milisCounter++;
}

unsigned int milis (void){
	return milisCounter;
}

void toggle_led(int maska){
	GPIO_ToggleBits(GPIOD, maska);
}

void set_led(int maska){
	GPIO_SetBits(GPIOD, maska);
}

void reset_led(int maska){
	GPIO_ResetBits(GPIOD, maska);
}

int main(){
	TIM_OCInitTypeDef OCInitStruct;
	double svetilnost = 1;
	int smer = UGASAJ;
	int stariCas;
	
	// Init
	PWM_pin_init();
	TIM4_init();
	SysTick_Config(SystemCoreClock / 1000);
	
	// Output Compare Init
	TIM_OCStructInit(&OCInitStruct); // Nafilamo default vrednosti v OCInitStruct
	OCInitStruct.TIM_OCMode = TIM_OCMode_PWM1;
	OCInitStruct.TIM_Pulse = 0;
	OCInitStruct.TIM_OutputState = TIM_OutputState_Enable;
	
	TIM_OC1Init(TIM4, &OCInitStruct);
	TIM_OC2Init(TIM4, &OCInitStruct);
	TIM_OC3Init(TIM4, &OCInitStruct);
	TIM_OC4Init(TIM4, &OCInitStruct);
	
	while(1){
		
		// Logika za priziganje in ugasanje
		if (smer == PRIZIGAJ && svetilnost < PERIODA) svetilnost *= 1.001;
		else if (smer == UGASAJ && svetilnost > 1) svetilnost /= 1.001;
		else smer = !smer;
		
		// Delay
		stariCas = milis();
		while(milis() - stariCas < 1);
		
		// Nastavimo Compare
		TIM_SetCompare1(TIM4, svetilnost);
		TIM_SetCompare2(TIM4, svetilnost);
		TIM_SetCompare3(TIM4, svetilnost);
		TIM_SetCompare4(TIM4, svetilnost);
		
	}	
}
