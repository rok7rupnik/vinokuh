#include "nokia.h"

void gotoXY(int x, int y) {
  LCDWrite(0, 0x80 | x);  // Column.
  LCDWrite(0, 0x40 | y);  // Row.  ?
}

//This takes a large array of bits and sends them to the LCD
void LCDBitmap(char my_array[]){
  for (int index = 0 ; index < (LCD_X * LCD_Y / 8) ; index++)
    LCDWrite(LCD_DATA, my_array[index]);
}

//This function takes in a character, looks it up in the font table/array
//And writes it to the screen
//Each character is 8 bits tall and 5 bits wide. We pad one blank column of
//pixels on each side of the character for readability.
void LCDCharacter(char character) {
  LCDWrite(LCD_DATA, 0x00); //Blank vertical line padding

  for (int index = 0 ; index < 5 ; index++)
    LCDWrite(LCD_DATA, ASCII[character - 0x20][index]);
    //0x20 is the ASCII character for Space (' '). The font table starts with this character

  LCDWrite(LCD_DATA, 0x00); //Blank vertical line padding
}

//Given a string of characters, one by one is passed to the LCD
void LCDString(char *characters) {
  while (*characters)
    LCDCharacter(*characters++);
}

//Clears the LCD by writing zeros to the entire screen
void LCDClear(void) {
  for (int index = 0 ; index < (LCD_X * LCD_Y / 8) ; index++)
    LCDWrite(LCD_DATA, 0x00);
    
  gotoXY(0, 0); //After we clear the display, return to the home position
}


void GPIO_init(){
	// Struktura za init gpio pinov, najprej za MISO, MOSI/DIN in CLK, ki so AF mode
	GPIO_InitTypeDef initStruct;
	// Na GPIOD pripeljemo uro (vodilo AHB)
	RCC_AHB1PeriphClockCmd(RCC_AHB1Periph_GPIOA, ENABLE);
	
	GPIO_StructInit(&initStruct);
	// Kater pine izberemo
	initStruct.GPIO_Pin = GPIO_Pin_5 | GPIO_Pin_6 | GPIO_Pin_7;
	// Ali bojo vhodni ali izhodni
	initStruct.GPIO_Mode = GPIO_Mode_AF;	
	initStruct.GPIO_Speed = GPIO_Speed_100MHz;
	
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource5, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource6, GPIO_AF_SPI1);
	GPIO_PinAFConfig(GPIOA, GPIO_PinSource7, GPIO_AF_SPI1);
	
	GPIO_Init(GPIOD, &initStruct);
	
	// Nato se dodamo CE, RST in D/C, ki so OUT
	
	GPIO_StructInit(&initStruct);
	// Kater pine izberemo
	initStruct.GPIO_Pin = GPIO_Pin_0 | GPIO_Pin_1 | GPIO_Pin_2;
	// Ali bojo vhodni ali izhodni
	initStruct.GPIO_Mode = GPIO_Mode_OUT;
	initStruct.GPIO_Speed = GPIO_Speed_100MHz;	
	
	GPIO_Init(GPIOD, &initStruct);
}

void SPI_init(){
	SPI_InitTypeDef initStruct;
	
	RCC_APB2PeriphClockCmd(RCC_APB2Periph_SPI1, ENABLE);
	
	SPI_StructInit(&initStruct);
	
	initStruct.SPI_BaudRatePrescaler = SPI_BaudRatePrescaler_32;
	// Not Slave Select realiziramo software-ovsko
	initStruct.SPI_NSS = SPI_NSS_Soft;
	initStruct.SPI_Mode = SPI_Mode_Master;
	//initStruct.SPI_CRCPolynomial = 0;
	
	SPI_Init(SPI1, &initStruct);	
}

//This sends the magical commands to the PCD8544
void LCDInit(void) {	
	

  //Configure control pins
  GPIO_init();
	
	//Configure SPI
	SPI_init();
	
	// Resetiramo LCD
	GPIO_ResetBits(GPIOA, PIN_RST);
	GPIO_SetBits(GPIOA, PIN_RST);

  //Reset the LCD to a known state
  digitalWrite(PIN_RST, LOW);
  digitalWrite(PIN_RST, HIGH);

  LCDWrite(LCD_COMMAND, 0x21); //Tell LCD that extended commands follow
  LCDWrite(LCD_COMMAND, 0xB0); //Set LCD Vop (Contrast): Try 0xB1(good @ 3.3V) or 0xBF if your display is too dark
  LCDWrite(LCD_COMMAND, 0x04); //Set Temp coefficent
  LCDWrite(LCD_COMMAND, 0x14); //LCD bias mode 1:48: Try 0x13 or 0x14

  LCDWrite(LCD_COMMAND, 0x20); //We must send 0x20 before modifying the display control mode
  LCDWrite(LCD_COMMAND, 0x0C); //Set display control, normal mode. 0x0D for inverse
}

//There are two memory banks in the LCD, data/RAM and commands. This 
//function sets the DC pin high or low depending, and then sends
//the data byte
unsigned char SPI_ReadWrite(unsigned char data){
	// Pisemo na vodilo
	SPI_I2S_SendData(SPI1, data);
	
	while(SPI_I2S_GetFlagStatus(SPI1, SPI_I2S_FLAG_TXE)){
		
		// TUKAJ SMO OSTAL
		
	}
}

void LCDWrite(unsigned char data_or_command, unsigned char data) {
  GPIO_WriteBit(GPIOA, PIN_DC, data_or_command); //Tell the LCD that we are writing either to data or a command

  //Send the data
  //digitalWrite(PIN_CE, LOW);
	GPIO_ResetBits(GPIOA, PIN_CE);
  //shiftOut(PIN_DIN, PIN_CLK, MSBFIRST, data);
	SPI_ReadWrite(data);
  digitalWrite(PIN_CE, HIGH);
}