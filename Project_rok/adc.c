#include "adc.h"

/*
	Driver za ADC
	
	Zdelo se mi je nesmiselno, da piseva ADC1 pri vseh funkcijah, zato je povsod samo ADC...
*/

void ADCInit() {
	GPIO_InitTypeDef GPIO_InitStruct;
	ADC_CommonInitTypeDef ADC_CommonInitStruct;
	ADC_InitTypeDef ADC1_InitStruct;
	
	// Enable the clock for ADC and the ADC GPIOs
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);	
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOC, ENABLE);
	
	// Configure these ADC pins in analog mode using GPIO_Init();		
	GPIO_StructInit(&GPIO_InitStruct); // Reset gpio init structure
	GPIO_InitStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2 | GPIO_Pin_3;
	GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN; // Obvezno AIN !!!
	GPIO_Init(GPIOC, &GPIO_InitStruct);	
	
  // Common ADC init sets the prescaler
	ADC_CommonStructInit(&ADC_CommonInitStruct);
	ADC_CommonInitStruct.ADC_Prescaler = ADC_Prescaler_Div4;
	ADC_CommonInit(&ADC_CommonInitStruct);

  /* ADC1 Configuration */
	ADC_StructInit(&ADC1_InitStruct);
	ADC1_InitStruct.ADC_Resolution = ADC_Resolution_10b;
	ADC_Init(ADC1, &ADC1_InitStruct);
	ADC_Cmd(ADC1, ENABLE);	

  /* Now do the setup */
  ADC_Init(ADC1, &ADC1_InitStruct);
  /* Enable ADC1 */
  ADC_Cmd(ADC1, ENABLE);
	
	//ADC_RegularChannelConfig(ADC1, 10, 1, ADC_SampleTime_15Cycles);

  /* Enable ADC1 reset calibration register */
  //ADC_ResetCalibration(ADC1);
  /* Check the end of ADC1 reset calibration register */
  //while(ADC_GetResetCalibrationStatus(ADC1));
  /* Start ADC1 calibaration */
  //ADC_StartCalibration(ADC1);
  /* Check the end of ADC1 calibration */
  //while(ADC_GetCalibrationStatus(ADC1));
}

void TS_PinInit(){
    GPIO_InitTypeDef GPIO_InitStruct;
    GPIO_StructInit(&GPIO_InitStruct); // Reset gpio init structure
    GPIO_InitStruct.GPIO_Mode = GPIO_Mode_AIN; // Obvezno AIN !!!

    RCC_AHB1PeriphClockCmd(TS1_Clk, ENABLE);
    GPIO_InitStruct.GPIO_Pin = (TS1_Pin);
    GPIO_Init(TS1_Port, &GPIO_InitStruct);

    RCC_AHB1PeriphClockCmd(TS2_Clk, ENABLE);
    GPIO_InitStruct.GPIO_Pin = (TS2_Pin);
    GPIO_Init(TS2_Port, &GPIO_InitStruct);

    RCC_AHB1PeriphClockCmd(TS3_Clk, ENABLE);
    GPIO_InitStruct.GPIO_Pin = (TS3_Pin);
    GPIO_Init(TS3_Port, &GPIO_InitStruct);
    
    RCC_AHB1PeriphClockCmd(TS4_Clk, ENABLE);
    GPIO_InitStruct.GPIO_Pin = (TS4_Pin);
    GPIO_Init(TS4_Port, &GPIO_InitStruct);
    
    RCC_AHB1PeriphClockCmd(TS5_Clk, ENABLE);
    GPIO_InitStruct.GPIO_Pin = (TS5_Pin);
    GPIO_Init(TS5_Port, &GPIO_InitStruct);
    
    RCC_AHB1PeriphClockCmd(TS6_Clk, ENABLE);
    GPIO_InitStruct.GPIO_Pin = (TS6_Pin);
    GPIO_Init(TS6_Port, &GPIO_InitStruct);
    
    RCC_AHB1PeriphClockCmd(TS7_Clk, ENABLE);
    GPIO_InitStruct.GPIO_Pin = (TS7_Pin);
    GPIO_Init(TS7_Port, &GPIO_InitStruct);
    
    RCC_AHB1PeriphClockCmd(TS8_Clk, ENABLE);
    GPIO_InitStruct.GPIO_Pin = (TS8_Pin);
    GPIO_Init(TS8_Port, &GPIO_InitStruct);
}

void ADC1_Init(){
    ADC_CommonInitTypeDef ADC_CommonInitStruct;
    ADC_InitTypeDef ADC1_InitStruct;

    RCC_APB2PeriphClockCmd(RCC_APB2Periph_ADC1, ENABLE);

    // Common ADC init sets the prescaler
    ADC_CommonStructInit(&ADC_CommonInitStruct);
    ADC_CommonInitStruct.ADC_Prescaler = ADC_Prescaler_Div4;
    ADC_CommonInit(&ADC_CommonInitStruct);

    /* ADC1 Configuration */
    ADC_StructInit(&ADC1_InitStruct);
    ADC1_InitStruct.ADC_Resolution = ADC_Resolution_10b;
    ADC_Init(ADC1, &ADC1_InitStruct);
    ADC_Cmd(ADC1, ENABLE);  

    /* Now do the setup */
    ADC_Init(ADC1, &ADC1_InitStruct);
    /* Enable ADC1 */
    ADC_Cmd(ADC1, ENABLE);
}

int ADCRead(u8 channel) {
    ADC_RegularChannelConfig(ADC1, channel, 1, ADC_SampleTime_15Cycles);
    ADC_SoftwareStartConv(ADC1);
    while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) != SET);
    return ADC_GetConversionValue(ADC1);
}

int ADC1_Read(u8 channel) {
	ADC_RegularChannelConfig(ADC1, channel, 1, ADC_SampleTime_15Cycles);
	ADC_SoftwareStartConv(ADC1);
	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) != SET);
	return ADC_GetConversionValue(ADC1);
}

int TS_Read(u8 level){
    switch (level){
        case 1: return ADC1_Read(12);
        case 2: return ADC1_Read(0);
        case 3: return ADC1_Read(2);
        case 4: return ADC1_Read(4);
        case 5: return ADC1_Read(6);
        case 6: return ADC1_Read(14);
        case 7: return ADC1_Read(8);
        case 8: return ADC1_Read(9);
        default: return 0;
    }
}

/*
// Stara funkcija za branje, potrebno izbrati kanal v initu!
int ADC1Read() {	
	ADC_SoftwareStartConv(ADC1);
	while(ADC_GetFlagStatus(ADC1, ADC_FLAG_EOC) != SET);
	return ADC_GetConversionValue(ADC1);
}
*/
