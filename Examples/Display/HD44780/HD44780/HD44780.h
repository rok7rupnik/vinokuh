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

/* Basic LCD Driver settings */
#define LCD_PROCESS_IO_FREQ 10000
#define FIFO_SIZE 100
/* Define for boot from Flash */
#define FLASH_BOOT

/* CLASS: HD44780 */
/* HD44780 HAL Driver */
class HD44780
{
public:
  HD44780(GPIO_TypeDef* portRS, uint16_t pinRS,
          GPIO_TypeDef* portRW, uint16_t pinRW,
          GPIO_TypeDef* portE, uint16_t pinE, 
          GPIO_TypeDef* portDB4, uint16_t pinDB4, 
          GPIO_TypeDef* portDB5, uint16_t pinDB5, 
          GPIO_TypeDef* portDB6, uint16_t pinDB6, 
          GPIO_TypeDef* portDB7, uint16_t pinDB7, 
          uint8_t width, uint8_t firstLineAddr,
          uint8_t secondLineAddr = 0xFF, uint8_t thirdLineAddr = 0xFF,
          uint8_t fourthLineAddr = 0xFF);
  ~HD44780();
  
  /* Hign level printing */
  void print(char* str, uint8_t strNum = 0, uint8_t chrNum = 0); // Universal printing method
  void clear(); // Clear display
  
  /*  Low level printing */
  void printChr(char* chr); // Print one character into current cursor position
  void setPos(uint8_t strNum = 0, uint8_t chrNum = 0); // Set cursor position
  
  /* CONSTANTS: Sets cursor move direction and specifies display shift */
  enum displayShift {DISPLAY_SHIFT_OFF = 0x00, DISPLAY_SHIFT_ON = 0x01};
  enum cursorShift {CURSOR_SHIFT_LEFT = 0x00, CURSOR_SHIFT_RIGHT = 0x02};
  
  /* CONSTANTS: Sets entire display on/off, cursor on/off and blinking of cursor position character */
  enum displayMode {DISPLAY_OFF = 0x00, DISPLAY_ON = 0x04};
  enum cursorMode {CURSOR_OFF = 0x00, CURSOR_ON = 0x02, CURSOR_CHAR = 0x01, CURSOR_ON_CHAR = 0x03};
  
  /* CONSTANTS: Specify moves cursor and shifts display direction without changing DDRAM contents */
  enum cmdShiftObj {SHIFT_CURSOR = 0x00, SHIFT_DISPLAY = 0x08};
  enum cmdShiftDir {SHIFT_LEFT = 0x00, SHIFT_RIGHT = 0x04};
  
  /* Settings */
  void entryModeSet(displayShift display, cursorShift cursor); // Sets cursor move direction and specifies display shift
  void displayControl(displayMode display, cursorMode cursor = CURSOR_OFF); // Sets entire display on/off, cursor on/off and blinking of cursor position character
  
  /* Shifts */
  void cmdShift(cmdShiftObj object, cmdShiftDir direction); // Shifts display without changing DDRAM contents
  
  /* Low level IO management */
  void processIO(); // IO bit-bang method
  
private:
  uint8_t entryModeSetCache; // Sets cursor move direction and specifies display shift
  uint8_t displayControlCache; // Sets entire display on/off, cursor on/off and blinking of cursor position character
  struct tInitData // IO bus configuration structure
  {
    GPIO_TypeDef *portRS, *portRW, *portE, *portDB4, *portDB5, *portDB6, *portDB7;
    uint16_t pinRS, pinRW, pinE, pinDB4, pinDB5, pinDB6, pinDB7;
    uint8_t width, addr[4];
  } initData;
  
  /* Task management */
  enum tOperation {CMD_RD, CMD_WR, DATA_RD, DATA_WR, WAIT};
  enum tBusMode {BFC_4BIT, BFI_4BIT, BFC_8BIT, BFI_8BIT};
  struct tIOTask
  {
    uint8_t data;
    tOperation operation;
    tBusMode busMode;
  } task, fifo[FIFO_SIZE], *pushTaskPtr, *popTaskPtr;
  void processTask(); // Basic process management function
  enum tCurrentSubTask {RSRW, HTET_DATA_WR, HTET_EUP, HTET_DATA_RD, HTET_EDOWN, LTET_DATA_WR, LTET_EUP, LTET_DATA_RD, LTET_EDOWN} currSubTask;
  void push(uint8_t data, tOperation operation, tBusMode busMode = BFC_4BIT); // Addition task to buffer
  tIOTask* pop(); // Receiving task from buffer
  
  /* Low level IO management vars */
  uint8_t BF_AC;
  
  /* Init */
  void RCC_Config(); // Config RCC
  void NVIC_Config(); // Config NVIC
  void TIM_Config(); // Config TIM
  void outConfig(GPIO_TypeDef* port, uint16_t pin); // Config pin for output
  void inConfig(GPIO_TypeDef* port, uint16_t pin); // Config pin for input
  void lcdInitSeq(); // LCD inittialization sequance 
  GPIO_InitTypeDef GPIO_InitStruct;
};