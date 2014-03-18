#include "stm32f4xx.h"
#include "lcd.h"

int main(void) 
{
    int a = 0;
            while(a<100)
            {
                __delay_cycles(32000);
                a++;
            }

    InitializeLcm();
    __delay_cycles(32000);
    ClearLcmScreen();
    __delay_cycles(32000);
    Cursor(0,0);
    PrintStr("  STM32F407VGT  ");
    Cursor(1,0);
    __delay_cycles(32000);
    PrintStr("Hello  World  !!");

      while(1);
}
