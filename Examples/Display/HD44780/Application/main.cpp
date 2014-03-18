//******************************************************************************
// PRODUCT: HD44780 LCD Driver
// VERSION: 1.0
// PROCESSOR: STM32 ARM Cortex-M3
// DEPENCIES: STM32 Standard Peripherals Library v3.3.0
// DEVELOPER: Lakotel™, PE Kancypa E.V.
// WEB: www.Lakotel.com
// PHONE: +380443832574, +380633283172
// EMAIL: info@lakotel.com
// CREATED: 24.06.2010
// COPYRIGHT: 2009-2010, PE Kancypa E.V.
// LICENSE: GNU Lesser General Public License v3
// See http://www.gnu.org/licenses/lgpl-3.0-standalone.html for license details
//******************************************************************************
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, 
// EXPRESS  OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF 
// MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. 
// IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY 
// CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, 
// TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH 
// THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.
//******************************************************************************
// See http://www.Lakotel.com/open-projects/hd44780-lcd-driver
// for documentation, latest information, license and contact details
//******************************************************************************

#include "stm32f10x.h"
#include "main.h"
#include <stdio.h>

void main()
{
  extern HD44780 lcd;
  
  /* Float to Char transfer buffer */
  char buff[7];
  /* Integer var example */
  int number = 32;
  /* Set shifts */
  lcd.entryModeSet(HD44780::DISPLAY_SHIFT_OFF, HD44780::CURSOR_SHIFT_RIGHT);
  /* Display on, set cursor & blink */
  lcd.displayControl(HD44780::DISPLAY_ON);
  /* Printing string, position (0,0) by default */
  lcd.print(" HD44780 LCD Driver\n     for STM\nby Lakotel, Ukraine\n  www.lakotel.com");
  /* Converting int to char */
  sprintf(buff, "%i", number);
  /* Printing integer, specific position */
  lcd.print(buff, 1, 12);
  
  while(1) {
    
  }
}

