#include <stm32f4xx.h>

typedef struct leds{
	int led1;
	int led2;
	int led3;
	int led4;
} leds;

void led_init(void){	
	// Struktura za init gpio pinov
	GPIO_InitTypeDef predalnik;
	// Kater pine izberemo
	predalnik.GPIO_Pin = GPIO_Pin_12 | GPIO_Pin_13 | GPIO_Pin_14 | GPIO_Pin_15;
	// Ali bojo vhodni ali izhodni
	predalnik.GPIO_Mode = GPIO_Mode_OUT;
	// Njihova hitrost
	predalnik.GPIO_Speed = GPIO_Speed_100MHz;
	// PushPull ali OpenDrain
	predalnik.GPIO_OType = GPIO_OType_PP;
	// Naj procesor ne uporablja svojih pull down/up uporov
	predalnik.GPIO_PuPd = GPIO_PuPd_NOPULL;
	
	// Na GPIOD pripeljemo uro (vodilo AHB)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOD, ENABLE);
	
	GPIO_Init(GPIOD, &predalnik);
}

void toggle_led(int maska){
	GPIO_ToggleBits(GPIOD, maska);
}

int timeCounter;
void clockInit(void){
	// Init na milisekunde
	SysTick_Config(SystemCoreClock/100);
}
void SysTick_Handler(){
	timeCounter++;
}
int clock(){
	return timeCounter;
}

int getRandom(){
	// Zajema podatke iz termicnega suma
	while(RNG_GetFlagStatus(RNG_FLAG_DRDY) == 0); 
	// Iz tega vrne random
	return RNG_GetRandomNumber();
}

void utripanje(leds ledice){
	int oldTime;	
	int startTime = clock();	
	
	while(clock() - startTime < 10000){ // Cakamo 10 s
		oldTime = clock();
		while(clock() - oldTime < 5); // Cakamo 1 ms
		
		ledice.led1--;
		ledice.led2--;
		ledice.led3--;
		ledice.led4--;
		
		if (ledice.led1 <= 0){
			toggle_led(GPIO_Pin_12);
			ledice.led1 = getRandom() % 400;
		}
		if (ledice.led2 <= 0){
			toggle_led(GPIO_Pin_13);
			ledice.led2 = getRandom() % 800;
		}
		if (ledice.led3 <= 0){
			toggle_led(GPIO_Pin_14);
			ledice.led3 = getRandom() % 200;
		}
		if (ledice.led4 <= 0){
			toggle_led(GPIO_Pin_15);
			ledice.led4 = getRandom() % 600;
		}	
	}
}

int main(void){
	// Init
	leds lightShow;
	led_init();
	clockInit();
	RCC_AHB2PeriphClockCmd(RCC_AHB2Periph_RNG, ENABLE);
	RNG_Cmd(ENABLE);
	
	
	lightShow.led1 = 100;
	lightShow.led2 = 1000;
	lightShow.led3 = 500;
	lightShow.led4 = 200;
	utripanje(lightShow);
	
}
