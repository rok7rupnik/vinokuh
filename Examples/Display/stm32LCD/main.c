#include "xhw_types.h"
#include "xhw_memmap.h"
#include "xhw_ints.h"
#include "xdebug.h"
#include "xsysctl.h"
#include "xgpio.h"
#include "hw_hd44780.h"
#include "hd44780.h"
int main(void)
{

	     int i , j;

	     HD44780Init();

	     //
	     // Location Set & Display string, number Test
	     //
	     HD44780LocationSet(0, 0);
	     HD44780DisplayString("Hello HD44780!");
	     HD44780LocationSet(0, 1);
	     HD44780DisplayString("Number:");
	     HD44780DisplayN(10086);
	     xSysCtlDelay(xSysCtlClockGet() / 4);
	     HD44780LocationSet(0,1);
	     HD44780DisplayString("Display off/on");
	     xSysCtlDelay(xSysCtlClockGet() / 4);
	     HD44780DisplayOff();
	     xSysCtlDelay(xSysCtlClockGet() / 4 );
	     HD44780DisplayOn();
	     xSysCtlDelay(xSysCtlClockGet() / 4);
	     //
	     // Cursor style
	     //
	     HD44780DisplayClear();
	     HD44780DisplayString("Cursor Test");
	     HD44780CursorOn(xfalse);
	     xSysCtlDelay(xSysCtlClockGet() / 4);
	     HD44780CursorOff();
	     xSysCtlDelay(xSysCtlClockGet() / 4);

	     //
	     // Cursor will blink at the end of line
	     //
	     HD44780CursorOn(xtrue);
	     HD44780CursorRightMove(1);
	     xSysCtlDelay(xSysCtlClockGet() / 4);
	     HD44780CursorRightMove(5);
	     xSysCtlDelay(xSysCtlClockGet() / 4);
	     HD44780CursorLeftMove(4);
	     xSysCtlDelay(xSysCtlClockGet() / 4);

	     for(i = 0; i < 10; i++)
	     {
	         HD44780CursorRightMove(1);
	         xSysCtlDelay(xSysCtlClockGet() / 10);
	     }

	     for(i = 0; i < 10; i++)
	     {
	         HD44780CursorLeftMove(1);
	         xSysCtlDelay(xSysCtlClockGet() / 10);
	     }

	     HD44780LocationSet(0, 1);
	     HD44780DisplayString("Cursor Home");
	     xSysCtlDelay(xSysCtlClockGet() / 4);

	     HD44780Home();

	     //
	     // Display Right shift
	     //
	     HD44780DisplayClear();
	     HD44780DisplayString("Right scrolling string");
	     HD44780LocationSet(0, 1);
	     HD44780DisplayString("        Line 2         ");
	     for(i = 0; i < 20; i++)
	     {
	         HD44780DisplayRightShift(1);
	         xSysCtlDelay(xSysCtlClockGet() / 10);
	     }

	     //
	     // Display Left shift
	     //
	     HD44780DisplayClear();
	     HD44780DisplayString("Left scrolling string");
	     HD44780LocationSet(0, 1);
	     HD44780DisplayString("        Line 2         ");
	     for(i = 0; i < 20; i++)
	     {
	         HD44780DisplayLeftShift(1);
	         xSysCtlDelay(xSysCtlClockGet() / 10);
	     }

	     //
	     // Display Right Left shift
	     //
	     HD44780DisplayClear();
	     HD44780DisplayString("Left Right scrolling string");
	     HD44780LocationSet(0, 1);
	     HD44780DisplayString("        Line 2         ");
	     for(j = 0; j < 2; j++)
	     {
	         for(i = 0; i < 10; i++)
	         {
	             HD44780DisplayRightShift(1);
	             xSysCtlDelay(xSysCtlClockGet() / 10);
	         }
	         for(i = 0; i < 10; i++)
	         {
	             HD44780DisplayLeftShift(1);
	             xSysCtlDelay(xSysCtlClockGet() / 10);
	         }
	     }
	     HD44780Home();
	     xSysCtlDelay(xSysCtlClockGet() / 4);

	     //
	     // Cursor Move Direction
	     //
	     HD44780DisplayClear();
	     HD44780LocationSet(10, 1);
	     xSysCtlDelay(xSysCtlClockGet() / 4);
	     HD44780EntryModeSet(HD44780_MOVE_DIRECTION_DEC, xfalse);
	     HD44780DisplayString("DEC");

	     HD44780LocationSet(10, 2);
	     xSysCtlDelay(xSysCtlClockGet() / 4);
	     HD44780EntryModeSet(HD44780_MOVE_DIRECTION_DEC, xtrue);
	     HD44780DisplayString("DEC shift");

	     HD44780DisplayClear();
	     HD44780LocationSet(10, 1);
	     xSysCtlDelay(xSysCtlClockGet() / 4);
	     HD44780EntryModeSet(HD44780_MOVE_DIRECTION_INC, xfalse);
	     HD44780DisplayString("INC");

	     HD44780LocationSet(10, 2);
	     xSysCtlDelay(xSysCtlClockGet() / 4);
	     HD44780EntryModeSet(HD44780_MOVE_DIRECTION_INC, xtrue);
	     HD44780DisplayString("INC shift");
	     xSysCtlDelay(xSysCtlClockGet() / 4);

	     HD44780DisplayClear();
	     HD44780EntryModeSet(HD44780_MOVE_DIRECTION_INC, xfalse);
	     HD44780DisplayString("Complete");



    while(1)
    {
    }
}
