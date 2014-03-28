#include "encoder.h"

// **************** INIT ******************

void encoderInit() {
    
    GPIO_InitTypeDef initStruct;
    
    initStruct.GPIO_Mode = GPIO_Mode_IN;
    initStruct.GPIO_Speed = GPIO_Speed_100MHz;
    initStruct.GPIO_OType = GPIO_OType_PP;
    initStruct.GPIO_PuPd = GPIO_PuPd_NOPULL;
    
    RCC_AHB1PeriphClockCmd(E1_Clk, ENABLE);
    initStruct.GPIO_Pin = (E1_Pin);
    GPIO_Init(E1_Port, &initStruct);
    
    RCC_AHB1PeriphClockCmd(E2_Clk, ENABLE);
    initStruct.GPIO_Pin = (E2_Pin);
    GPIO_Init(E2_Port, &initStruct);
}

/************* Driver *****************/
int A_VALUE = 0, B_VALUE = 0;
int T_VALUE = 0;

void encoderDriver(){
	char tmp1, tmp2;
	
	if((tmp1 = encoderReadB()) == 0)
		B_VALUE++;
	if((tmp2 = encoderReadA()) == 0)
		A_VALUE++;
	
	if(!tmp1 && !tmp2)
		T_VALUE++;
}


/************* General ****************/
int encoderReadA(){
    return GPIO_ReadInputDataBit(E1_Port, E1_Pin);
}
int encoderReadB(){
    return GPIO_ReadInputDataBit(E2_Port, E2_Pin);
}
