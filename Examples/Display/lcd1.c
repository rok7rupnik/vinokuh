//*******************************************************************
#include "stm32f4xx.h"

#define     LCM_OUT               GPIOB->ODR 

// connect RW leg to GND, and power supply rails to +5V and gnd 
// Define symbolic LCM - MCU pin mappings
// We've set DATA PIN TO 4,5,6,7 for easy translation
//
#define     LCM_PIN_RS            GPIO_Pin_0          // P1.0
#define     LCM_PIN_EN            GPIO_Pin_1          // P1.1
#define     LCM_PIN_D7            GPIO_Pin_7          // P1.7
#define     LCM_PIN_D6            GPIO_Pin_6          // P1.6
#define     LCM_PIN_D5            GPIO_Pin_5          // P1.5
#define     LCM_PIN_D4            GPIO_Pin_4          // P1.4

GPIO_InitTypeDef  GPIO_InitStructure; 
#define     LCM_PIN_MASK  ((LCM_PIN_RS | LCM_PIN_EN | LCM_PIN_D7 | LCM_PIN_D6 | LCM_PIN_D5 | LCM_PIN_D4))

#define     FALSE                 0 
#define     TRUE                  1

void __delay_cycles(int a) 
{
    int i = 0;
    int f = 0;
    while(f<a)
    {
            while(i<60)
                {i++;}
        f++;
    }
}

void PulseLcm() 
{
    LCM_OUT &= ~LCM_PIN_EN;
    __delay_cycles(220);
    LCM_OUT |= LCM_PIN_EN;
    __delay_cycles(220);
    LCM_OUT &= (~LCM_PIN_EN);
    __delay_cycles(220);
}

void SendByte(char ByteToSend, int IsData) 
{
    LCM_OUT &= (~LCM_PIN_MASK);
    LCM_OUT |= (ByteToSend & 0xF0);

    if (IsData == TRUE)
    {
        LCM_OUT |= LCM_PIN_RS;
    }
    else
    {
        LCM_OUT &= ~LCM_PIN_RS;
    }
    PulseLcm();
    LCM_OUT &= (~LCM_PIN_MASK);
    LCM_OUT |= ((ByteToSend & 0x0F) << 4);

    if (IsData == TRUE)
    {
        LCM_OUT |= LCM_PIN_RS;
    }
    else
    {
        LCM_OUT &= ~LCM_PIN_RS;
    }

    PulseLcm();
}

void Cursor(char Row, char Col) 
{
    char address;
    if (Row == 0)
    {
        address = 0;
    }
    else
    {
        address = 0x40;
    }

    address |= Col;
    SendByte(0x80 | address, FALSE);
}


void ClearLcmScreen() 
{
    SendByte(0x01, FALSE);
    SendByte(0x02, FALSE);
}

void InitializeLcm(void) 
{
    RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOB, ENABLE);
    GPIO_InitStructure.GPIO_Pin =GPIO_Pin_0 | GPIO_Pin_1| GPIO_Pin_4 | GPIO_Pin_5| GPIO_Pin_6| GPIO_Pin_7;
    GPIO_InitStructure.GPIO_Mode = GPIO_Mode_OUT;
    GPIO_InitStructure.GPIO_OType = GPIO_OType_PP;
    GPIO_InitStructure.GPIO_Speed = GPIO_Speed_100MHz;
    GPIO_InitStructure.GPIO_PuPd = GPIO_PuPd_NOPULL;
    GPIO_Init(GPIOB, &GPIO_InitStructure);

    LCM_OUT &= ~(LCM_PIN_MASK);

    __delay_cycles(32000);
    __delay_cycles(32000);
    __delay_cycles(32000);

    LCM_OUT &= ~LCM_PIN_RS;
    LCM_OUT &= ~LCM_PIN_EN;
    LCM_OUT = 0x20;
    PulseLcm();
    SendByte(0x28, FALSE);
    SendByte(0x0E, FALSE);
    SendByte(0x06, FALSE);
}


void PrintStr(char *Text) 
{
    char *c;

    c = Text;

    while ((c != 0) && (*c != 0))
    {
        SendByte(*c, TRUE);
        c++;
    }
}