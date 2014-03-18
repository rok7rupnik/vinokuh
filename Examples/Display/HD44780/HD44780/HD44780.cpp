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

#include "HD44780.h"
#include "stm32f10x.h"

HD44780::HD44780(GPIO_TypeDef* portRS, uint16_t pinRS,
                 GPIO_TypeDef* portRW, uint16_t pinRW,
                 GPIO_TypeDef* portE, uint16_t pinE, 
                 GPIO_TypeDef* portDB4, uint16_t pinDB4, 
                 GPIO_TypeDef* portDB5, uint16_t pinDB5, 
                 GPIO_TypeDef* portDB6, uint16_t pinDB6, 
                 GPIO_TypeDef* portDB7, uint16_t pinDB7, 
                 uint8_t width, uint8_t firstLineAddr,
                 uint8_t secondLineAddr, uint8_t thirdLineAddr,
                 uint8_t fourthLineAddr)
{
  /* Initialization bus configutation internal structure */
  initData.portRS = portRS;
  initData.portRW = portRW;
  initData.portE = portE;
  initData.portDB4 = portDB4;
  initData.portDB5 = portDB5;
  initData.portDB6 = portDB6;
  initData.portDB7 = portDB7;
  initData.pinRS = pinRS;
  initData.pinRW = pinRW;
  initData.pinE = pinE;
  initData.pinDB4 = pinDB4;
  initData.pinDB5 = pinDB5;
  initData.pinDB6 = pinDB6;
  initData.pinDB7 = pinDB7;
  initData.width = width;
  initData.addr[0] = firstLineAddr;
  initData.addr[1] = secondLineAddr;
  initData.addr[2] = thirdLineAddr;
  initData.addr[3] = fourthLineAddr;
  /* Initialization task buffer pointers */
  pushTaskPtr = fifo;
  popTaskPtr = pushTaskPtr;
  /* Initialization current task data structure*/
  task.operation = WAIT;
  task.data = 0;
  currSubTask = RSRW;
  BF_AC = 0x80;
  entryModeSetCache = 0;
  displayControlCache = 0;
  /* Initialization MCU units and LCD */
  RCC_Config();
  /* Configuration all lines to output and initialization*/
  outConfig(initData.portRS, initData.pinRS);
  outConfig(initData.portRW, initData.pinRW);
  outConfig(initData.portE, initData.pinE);
  outConfig(initData.portDB4, initData.pinDB4);
  outConfig(initData.portDB5, initData.pinDB5);
  outConfig(initData.portDB6, initData.pinDB6);
  outConfig(initData.portDB7, initData.pinDB7);
  /* LCD init sequance */
  lcdInitSeq();
  NVIC_Config();
  TIM_Config();
}

HD44780::~HD44780()
{
}

/* Hign level printing: Universal printing method */
void HD44780::print(char* str, uint8_t strNum, uint8_t chrNum)
{
  for( ; initData.addr[strNum]!=0xFF && strNum<4; strNum++, chrNum = 0) {
    setPos(strNum, chrNum);
    for( ; chrNum < initData.width; chrNum++, str++) {
      if(*str=='\n' && chrNum != 0) {
        str++;
        break;
      }
      else if(*str==0x00) {
        strNum = 4;
        break;
      }
      else {
        printChr(str);
      }
    }
  }
}

/* Hign level printing: Clear display */
void HD44780::clear()
{
  push(0x01, CMD_WR);
}

/*  Low level printing: Print one character into current cursor position */
void HD44780::printChr(char* chr)
{
  switch(*chr) {
  case ' ':
    push(0x20, DATA_WR); break;
  case '!':
    push(0x21, DATA_WR); break;
  case '"':
    push(0x22, DATA_WR); break;
  case '#':
    push(0x23, DATA_WR); break;
  case '$':
    push(0x24, DATA_WR); break;
  case '%':
    push(0x25, DATA_WR); break;
  case '&':
    push(0x26, DATA_WR); break;
  case '\'':
    push(0x27, DATA_WR); break;
  case '(':
    push(0x28, DATA_WR); break;
  case ')':
    push(0x29, DATA_WR); break;
  case '*':
    push(0x2A, DATA_WR); break;
  case '+':
    push(0x2B, DATA_WR); break;
  case ',':
    push(0x2C, DATA_WR); break;
  case '-':
    push(0x2D, DATA_WR); break;
  case '.':
    push(0x2E, DATA_WR); break;
  case '/':
    push(0x2F, DATA_WR); break;
  case '0':
    push(0x30, DATA_WR); break;
  case '1':
    push(0x31, DATA_WR); break;
  case '2':
    push(0x32, DATA_WR); break;
  case '3':
    push(0x33, DATA_WR); break;
  case '4':
    push(0x34, DATA_WR); break;
  case '5':
    push(0x35, DATA_WR); break;
  case '6':
    push(0x36, DATA_WR); break;
  case '7':
    push(0x37, DATA_WR); break;
  case '8':
    push(0x38, DATA_WR); break;
  case '9':
    push(0x39, DATA_WR); break;
  case ':':
    push(0x3A, DATA_WR); break;
  case ';':
    push(0x3B, DATA_WR); break;
  case '<':
    push(0x3C, DATA_WR); break;
  case '=':
    push(0x3D, DATA_WR); break;
  case '>':
    push(0x3E, DATA_WR); break;
  case '?':
    push(0x3F, DATA_WR); break;
  case 'A':
    push(0x41, DATA_WR); break;
  case 'À': // cyrillic
    push(0x41, DATA_WR); break;
  case 'B':
    push(0x42, DATA_WR); break;
  case 'Â': // cyrillic
    push(0x42, DATA_WR); break;
  case 'C':
    push(0x43, DATA_WR); break;
  case 'Ñ': // cyrillic
    push(0x43, DATA_WR); break;
  case 'D':
    push(0x44, DATA_WR); break;
  case 'E':
    push(0x45, DATA_WR); break;
  case 'Å': // cyrillic
    push(0x45, DATA_WR); break;
  case 'F':
    push(0x46, DATA_WR); break;
  case 'G':
    push(0x47, DATA_WR); break;
  case 'H':
    push(0x48, DATA_WR); break;
  case 'Í': // cyrillic
    push(0x48, DATA_WR); break;
  case 'I':
    push(0x49, DATA_WR); break;
  case 'J':
    push(0x4A, DATA_WR); break;
  case 'K':
    push(0x4B, DATA_WR); break;
  case 'Ê': // cyrillic
    push(0x4B, DATA_WR); break;
  case 'L':
    push(0x4C, DATA_WR); break;
  case 'M':
    push(0x4D, DATA_WR); break;
  case 'Ì': // cyrillic
    push(0x4D, DATA_WR); break;
  case 'N':
    push(0x4E, DATA_WR); break;
  case 'O':
    push(0x4F, DATA_WR); break;
  case 'Î': // cyrillic
    push(0x4F, DATA_WR); break;
  case 'P':
    push(0x50, DATA_WR); break;
  case 'Ð': // cyrillic
    push(0x50, DATA_WR); break;
  case 'Q':
    push(0x51, DATA_WR); break;
  case 'R':
    push(0x52, DATA_WR); break;
  case 'S':
    push(0x53, DATA_WR); break;
  case 'T':
    push(0x54, DATA_WR); break;
  case 'U':
    push(0x55, DATA_WR); break;
  case 'V':
    push(0x56, DATA_WR); break;
  case 'W':
    push(0x57, DATA_WR); break;
  case 'X':
    push(0x58, DATA_WR); break;
  case 'Õ': // cyrillic
    push(0x58, DATA_WR); break;
  case 'Y':
    push(0x59, DATA_WR); break;
  case 'Z':
    push(0x5A, DATA_WR); break;
  case '[':
    push(0x5B, DATA_WR); break;
  case ']':
    push(0x5D, DATA_WR); break;
  case '^':
    push(0x5E, DATA_WR); break;
  case '_':
    push(0x5F, DATA_WR); break;
  case '`':
    push(0x60, DATA_WR); break;
  case 'a':
    push(0x61, DATA_WR); break;
  case 'à': // cyrillic
    push(0x61, DATA_WR); break;
  case 'b':
    push(0x62, DATA_WR); break;
  case 'c':
    push(0x63, DATA_WR); break;
  case 'ñ': // cyrillic
    push(0x63, DATA_WR); break;
  case 'd':
    push(0x64, DATA_WR); break;
  case 'e':
    push(0x65, DATA_WR); break;
  case 'å': // cyrillic
    push(0x65, DATA_WR); break;
  case 'f':
    push(0x66, DATA_WR); break;
  case 'g':
    push(0x67, DATA_WR); break;
  case 'h':
    push(0x68, DATA_WR); break;
  case 'i':
    push(0x69, DATA_WR); break;
  case 'j':
    push(0x6A, DATA_WR); break;
  case 'k':
    push(0x6B, DATA_WR); break;
  case 'l':
    push(0x6C, DATA_WR); break;
  case 'm':
    push(0x6D, DATA_WR); break;
  case 'n':
    push(0x6E, DATA_WR); break;
  case 'o':
    push(0x6F, DATA_WR); break;
  case 'î': // cyrillic
    push(0x6F, DATA_WR); break;
  case 'p':
    push(0x70, DATA_WR); break;
  case 'ð': // cyrillic
    push(0x70, DATA_WR); break;
  case 'q':
    push(0x71, DATA_WR); break;
  case 'r':
    push(0x72, DATA_WR); break;
  case 's':
    push(0x73, DATA_WR); break;
  case 't':
    push(0x74, DATA_WR); break;
  case 'u':
    push(0x75, DATA_WR); break;
  case 'v':
    push(0x76, DATA_WR); break;
  case 'w':
    push(0x77, DATA_WR); break;
  case 'x':
    push(0x78, DATA_WR); break;
  case 'õ': // cyrillic
    push(0x78, DATA_WR); break;
  case 'y':
    push(0x79, DATA_WR); break;
  case 'ó': // cyrillic
    push(0x79, DATA_WR); break;
  case 'z':
    push(0x7A, DATA_WR); break;
  case 'Á':
    push(0xA0, DATA_WR); break;
  case 'Ã':
    push(0xA1, DATA_WR); break;
  case '¨':
    push(0xA2, DATA_WR); break;
  case 'Æ':
    push(0xA3, DATA_WR); break;
  case 'Ç':
    push(0xA4, DATA_WR); break;
  case 'È':
    push(0xA5, DATA_WR); break;
  case 'É':
    push(0xA6, DATA_WR); break;
  case 'Ë':
    push(0xA7, DATA_WR); break;
  case 'Ï':
    push(0xA8, DATA_WR); break;
  case 'Ó':
    push(0xA9, DATA_WR); break;
  case 'Ô':
    push(0xAA, DATA_WR); break;
  case '×':
    push(0xAB, DATA_WR); break;
  case 'Ø':
    push(0xAC, DATA_WR); break;
  case 'Ú':
    push(0xAD, DATA_WR); break;
  case 'Û':
    push(0xAE, DATA_WR); break;
  case 'Ý':
    push(0xAF, DATA_WR); break;
  case 'Þ':
    push(0xB0, DATA_WR); break;
  case 'ß':
    push(0xB1, DATA_WR); break;
  case 'á':
    push(0xB2, DATA_WR); break;
  case 'â':
    push(0xB3, DATA_WR); break;
  case 'ã':
    push(0xB4, DATA_WR); break;
  case '¸':
    push(0xB5, DATA_WR); break;
  case 'æ':
    push(0xB6, DATA_WR); break;
  case 'ç':
    push(0xB7, DATA_WR); break;
  case 'è':
    push(0xB8, DATA_WR); break;
  case 'é':
    push(0xB9, DATA_WR); break;
  case 'ê':
    push(0xBA, DATA_WR); break;
  case 'ë':
    push(0xBB, DATA_WR); break;
  case 'ì':
    push(0xBC, DATA_WR); break;
  case 'í':
    push(0xBD, DATA_WR); break;
  case 'ï':
    push(0xBE, DATA_WR); break;
  case 'ò':
    push(0xBF, DATA_WR); break;
  case '÷':
    push(0xC0, DATA_WR); break;
  case 'ø':
    push(0xC1, DATA_WR); break;
  case 'ú':
    push(0xC2, DATA_WR); break;
  case 'û':
    push(0xC3, DATA_WR); break;
  case 'ü':
    push(0xC4, DATA_WR); break;
  case 'ý':
    push(0xC5, DATA_WR); break;
  case 'þ':
    push(0xC6, DATA_WR); break;
  case 'ÿ':
    push(0xC7, DATA_WR); break;
  case '«':
    push(0xC8, DATA_WR); break;
  case '»':
    push(0xC9, DATA_WR); break;
  case '“':
    push(0xCA, DATA_WR); break;
  case '”':
    push(0xCB, DATA_WR); break;
  case 'Ä':
    push(0xE0, DATA_WR); break;
  case 'Ö':
    push(0xE1, DATA_WR); break;
  case 'Ù':
    push(0xE2, DATA_WR); break;
  case 'ä':
    push(0xE3, DATA_WR); break;
  case 'ô':
    push(0xE4, DATA_WR); break;
  case 'ö':
    push(0xE5, DATA_WR); break;
  case 'ù':
    push(0xE6, DATA_WR); break;
  case '§':
    push(0xFD, DATA_WR); break;
  case '¶':
    push(0xFE, DATA_WR); break;
  }
}

/*  Low level printing: Set cursor position */
void HD44780::setPos(uint8_t strNum, uint8_t chrNum)
{
  if(strNum > 3 || chrNum > initData.width-1)
    return;
  if(strNum==0 &&  chrNum==0) {
    push(0x02, CMD_WR);
    return;
  }
  push(0x80 | initData.addr[strNum] + chrNum, CMD_WR);
}

/* Settings: Sets cursor move direction and specifies display shift */
void HD44780::entryModeSet(displayShift display, cursorShift cursor)
{
  entryModeSetCache = 0x04 | display | cursor;
  push(entryModeSetCache, CMD_WR);
}

/* Settings: Sets entire display on/off, cursor on/off and blinking of cursor position character */
void HD44780::displayControl(displayMode display, cursorMode cursor)
{
  displayControlCache = 0x08 | display | cursor;
  push(displayControlCache, CMD_WR);
}

/* Shifts: Shifts display without changing DDRAM contents */
void HD44780::cmdShift(cmdShiftObj object, cmdShiftDir direction)
{
  push(0x10 | object | direction, CMD_WR);
}

/* Task management: Addition task to buffer */
void HD44780::push(uint8_t data, tOperation operation, tBusMode busMode)
{
  pushTaskPtr->data = data;
  pushTaskPtr->operation = operation;
  pushTaskPtr->busMode = busMode;
  pushTaskPtr++;
  if(pushTaskPtr==&fifo[FIFO_SIZE])
    pushTaskPtr = fifo;
}

/* Task management: Receiving task from buffer */
HD44780::tIOTask* HD44780::pop()
{
  tIOTask* tempTaskPtr;
  if(popTaskPtr!=pushTaskPtr) {
    tempTaskPtr = popTaskPtr;
    popTaskPtr++;
    if(popTaskPtr==&fifo[FIFO_SIZE])
      popTaskPtr = fifo;
    return tempTaskPtr;
  }
  return (tIOTask*) 0;
}

/* Task management: Basic process management function */
void HD44780::processTask()
{
  static tIOTask* nextTask;
  /* Process if previous operation was CMD_RD */
  if(task.operation==CMD_RD)
    BF_AC = task.data;
  /* Process if previous operation was CMD_WR */
  else if(task.operation==CMD_WR) {

  }
  /* Process if previous operation was DATA_WR */
  else if(task.operation==DATA_WR) {

  }
  /* Process if previous operation was DATA_RD */
  else if(task.operation==DATA_RD) {
    
  }
  /* Deleting after operation and pop new taks */
  if(nextTask!=0 && nextTask->operation==task.operation && nextTask->operation!=WAIT) {
    delete nextTask;
    nextTask = pop();
  }
  /* Pop new without deleting */
  else if(nextTask==0)
    nextTask = pop();
  /* Checking for no task */
  if(nextTask==0) {
    task.operation = WAIT;
    return;
  }
  /* Managing WAIT operation. Decrement counter or terminate in the case of zero */
  if(nextTask->operation==WAIT) {
    if(nextTask->data!=0) {
      task.operation = WAIT;
      nextTask->data = nextTask->data - 1;
      return;
    }
    else {
      delete nextTask;
      nextTask = 0;
      return;
    }
  }
  /* Check for Busy Flag if needed */
  if(nextTask->busMode==BFC_4BIT || nextTask->busMode==BFC_8BIT) {
    if(BF_AC & 0x80) {
      task.operation = CMD_RD;
      task.busMode = nextTask->busMode;
      return;
 
    }
    else {
      BF_AC = 0x80;
      /* Updating task structure */
      task = *nextTask;
      return;
    }
  }
  /* Updating task structure */
  task = *nextTask;
}

/* Low level IO management: IO bit-bang method */
void HD44780::processIO()
{
  if(currSubTask==RSRW) {
    processTask();
    /* Checking for WAIT or return by WAIT operation */
    if(task.operation==WAIT)
      return;
    /* IR write as an internal operation (display clear, etc.) */
    else if(task.operation==CMD_WR) {
      GPIO_WriteBit(initData.portRS, initData.pinRS, Bit_RESET);
      GPIO_WriteBit(initData.portRW, initData.pinRW, Bit_RESET);
      currSubTask = HTET_DATA_WR;
    }    
    /* Read busy flag (DB7) and address counter (DB0 to DB6) */
    else if(task.operation==CMD_RD) {
      GPIO_WriteBit(initData.portRS, initData.pinRS, Bit_RESET);
      GPIO_WriteBit(initData.portRW, initData.pinRW, Bit_SET);
      task.data = 0;
      currSubTask = HTET_EUP;
    }
    /* DR write as an internal operation (DR to DDRAM or CGRAM) */    
    else if(task.operation==DATA_WR) {
      GPIO_WriteBit(initData.portRS, initData.pinRS, Bit_SET);
      GPIO_WriteBit(initData.portRW, initData.pinRW, Bit_RESET);
      currSubTask = HTET_DATA_WR;
    }
    /* DR read as an internal operation (DDRAM or CGRAM to DR) */    
    else if(task.operation==DATA_RD) {
      GPIO_WriteBit(initData.portRS, initData.pinRS, Bit_SET);
      GPIO_WriteBit(initData.portRW, initData.pinRW, Bit_SET);
      task.data = 0;
      currSubTask = HTET_EUP;
    }
    return;
  }
  else if(currSubTask==HTET_DATA_WR) {
    /* Set high tetrad for Write */    
    if(task.data & 0x10)
      GPIO_WriteBit(initData.portDB4, initData.pinDB4, Bit_SET);
    else
      GPIO_WriteBit(initData.portDB4, initData.pinDB4, Bit_RESET);
    if(task.data & 0x20)
      GPIO_WriteBit(initData.portDB5, initData.pinDB5, Bit_SET);
    else
      GPIO_WriteBit(initData.portDB5, initData.pinDB5, Bit_RESET);
    if(task.data & 0x40)
      GPIO_WriteBit(initData.portDB6, initData.pinDB6, Bit_SET);
    else
      GPIO_WriteBit(initData.portDB6, initData.pinDB6, Bit_RESET);
    if(task.data & 0x80)
      GPIO_WriteBit(initData.portDB7, initData.pinDB7, Bit_SET);
    else
      GPIO_WriteBit(initData.portDB7, initData.pinDB7, Bit_RESET);
    /* Check for 8bit bus mode */
    if(task.busMode==BFC_8BIT || task.busMode==BFI_8BIT) {
      currSubTask = LTET_EUP;
      return;
    }
    currSubTask = HTET_EUP;
    return;
  }
  else if(currSubTask==HTET_EUP) {
    GPIO_WriteBit(initData.portE, initData.pinE, Bit_SET);
    if(task.operation==CMD_WR || task.operation==DATA_WR)
      currSubTask = HTET_EDOWN;
    else
      currSubTask = HTET_DATA_RD;
    return;
  }
  else if(currSubTask==HTET_DATA_RD) {
    /* Config bus for reading */
    inConfig(initData.portDB4, initData.pinDB4);  
    inConfig(initData.portDB5, initData.pinDB5);
    inConfig(initData.portDB6, initData.pinDB6);
    inConfig(initData.portDB7, initData.pinDB7);
    /* Readin high tetrad */
    if(GPIO_ReadInputDataBit(initData.portDB4, initData.pinDB4))
      task.data |= 0x10;
    if(GPIO_ReadInputDataBit(initData.portDB5, initData.pinDB5))
      task.data |= 0x20;
    if(GPIO_ReadInputDataBit(initData.portDB6, initData.pinDB6))
      task.data |= 0x40;
    if(GPIO_ReadInputDataBit(initData.portDB7, initData.pinDB7))
      task.data |= 0x80;
    if(task.busMode==BFC_8BIT || task.busMode==BFI_8BIT) {
      /* Config bus back for write */
      outConfig(initData.portDB4, initData.pinDB4);
      outConfig(initData.portDB5, initData.pinDB5);
      outConfig(initData.portDB6, initData.pinDB6);
      outConfig(initData.portDB7, initData.pinDB7);
      currSubTask = LTET_EDOWN;
      return;
    }
    currSubTask = HTET_EDOWN;
    return;
  }
  else if(currSubTask==HTET_EDOWN) {
    GPIO_WriteBit(initData.portE, initData.pinE, Bit_RESET);
    if(task.operation==CMD_WR || task.operation==DATA_WR)
      currSubTask = LTET_DATA_WR;
    else
      currSubTask = LTET_EUP;
    return;
  }
  else if(currSubTask==LTET_DATA_WR) {
    /* Set high tetrad for Write */
    if(task.data & 0x01)
      GPIO_WriteBit(initData.portDB4, initData.pinDB4, Bit_SET);
    else
      GPIO_WriteBit(initData.portDB4, initData.pinDB4, Bit_RESET);
    if(task.data & 0x02)
      GPIO_WriteBit(initData.portDB5, initData.pinDB5, Bit_SET);
    else
      GPIO_WriteBit(initData.portDB5, initData.pinDB5, Bit_RESET);
    if(task.data & 0x04)
      GPIO_WriteBit(initData.portDB6, initData.pinDB6, Bit_SET);
    else
      GPIO_WriteBit(initData.portDB6, initData.pinDB6, Bit_RESET);
    if(task.data & 0x08)
      GPIO_WriteBit(initData.portDB7, initData.pinDB7, Bit_SET);
    else
      GPIO_WriteBit(initData.portDB7, initData.pinDB7, Bit_RESET);
    currSubTask = LTET_EUP;
    return;

  }
  else if(currSubTask==LTET_EUP) {
    GPIO_WriteBit(initData.portE, initData.pinE, Bit_SET);
    if(task.operation==CMD_WR || task.operation==DATA_WR)
      currSubTask = LTET_EDOWN;
    else
      currSubTask = LTET_DATA_RD;
    return;
  }
  else if(currSubTask==LTET_DATA_RD) {
    /* Readin low tetrad */
    if(GPIO_ReadInputDataBit(initData.portDB4, initData.pinDB4))
      task.data |= 0x01;
    if(GPIO_ReadInputDataBit(initData.portDB5, initData.pinDB5))
      task.data |= 0x02;
    if(GPIO_ReadInputDataBit(initData.portDB6, initData.pinDB6))
      task.data |= 0x04;
    if(GPIO_ReadInputDataBit(initData.portDB7, initData.pinDB7))
      task.data |= 0x08;
    /* Config bus back for write */
    outConfig(initData.portDB4, initData.pinDB4);
    outConfig(initData.portDB5, initData.pinDB5);
    outConfig(initData.portDB6, initData.pinDB6);
    outConfig(initData.portDB7, initData.pinDB7);
    currSubTask = LTET_EDOWN;
    return;
  }
  else if(currSubTask==LTET_EDOWN) {
    GPIO_WriteBit(initData.portE, initData.pinE, Bit_RESET);
    currSubTask = RSRW;
    return;
  }
}

/* Init: Config RCC */
void HD44780::RCC_Config()
{
  /* PCLK1 = HCLK */  
  RCC_PCLK1Config(RCC_HCLK_Div1);
  /* PCLK2 = HCLK */  
  RCC_PCLK2Config(RCC_HCLK_Div1);
  /* TIM2 clock enable */
  RCC_APB1PeriphClockCmd(RCC_APB1Periph_TIM2, ENABLE);
  /* GPIO clock enable */
  RCC_APB2PeriphClockCmd(RCC_APB2Periph_GPIOE, ENABLE);
}

/* Init: Config NVIC */
void HD44780::NVIC_Config()
{
  NVIC_InitTypeDef NVIC_InitStructure;
  /* Set vector table */
#ifdef FLASH_BOOT
  NVIC_SetVectorTable(NVIC_VectTab_FLASH, 0x00);
#else
  NVIC_SetVectorTable(NVIC_VectTab_RAM, 0x00);
#endif
  NVIC_PriorityGroupConfig(NVIC_PriorityGroup_4);
  /* Enable TIM2 global Interrupt */
  NVIC_InitStructure.NVIC_IRQChannel = TIM2_IRQn;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 0;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}

/* Init: Config TIM */
void HD44780::TIM_Config()
{
  TIM_TimeBaseInitTypeDef TIM_InitStructure;
  /* TIM configuration */
  TIM_InitStructure.TIM_Period = SystemCoreClock/LCD_PROCESS_IO_FREQ;
  TIM_InitStructure.TIM_Prescaler = 0;
  TIM_InitStructure.TIM_ClockDivision = 0;
  TIM_InitStructure.TIM_CounterMode = TIM_CounterMode_Up;
  TIM_TimeBaseInit(TIM2, &TIM_InitStructure);
  TIM_ITConfig(TIM2, TIM_IT_Update, ENABLE);
  TIM_Cmd(TIM2, ENABLE);
}

/* Init: Config pin for output */
void HD44780::outConfig(GPIO_TypeDef* port, uint16_t pin)
{
  GPIO_InitStruct.GPIO_Pin = pin;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_Out_OD;
  GPIO_InitStruct.GPIO_Speed = GPIO_Speed_50MHz;
  GPIO_Init(port, &GPIO_InitStruct);
  GPIO_WriteBit(port, pin, Bit_RESET);
}

/* Init: Config pin for input */
void HD44780::inConfig(GPIO_TypeDef* port, uint16_t pin)
{
  GPIO_InitStruct.GPIO_Pin = pin;
  GPIO_InitStruct.GPIO_Mode = GPIO_Mode_IN_FLOATING;
  GPIO_Init(port, &GPIO_InitStruct);
}

/* Init: LCD inittialization sequance */
void HD44780::lcdInitSeq()
{
  push(LCD_PROCESS_IO_FREQ*15/1000, WAIT); // Wait 15ms
  push(0x30, CMD_WR, BFI_8BIT);
  push(LCD_PROCESS_IO_FREQ*5/1000, WAIT); // Wait 5ms
  push(0x30, CMD_WR, BFI_8BIT);
  push(LCD_PROCESS_IO_FREQ*1/1000, WAIT); // Wait 1ms
  push(0x30, CMD_WR, BFI_8BIT);
  push(0x20, CMD_WR, BFI_8BIT);
  push(0x28, CMD_WR, BFI_4BIT);
  displayControl(DISPLAY_OFF); // Display off
  clear(); // Clear display
}