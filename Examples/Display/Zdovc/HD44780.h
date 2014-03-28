#define	D4_Pin	GPIO_Pin_0
#define D4_Port	GPIOE
#define D4_Clk 	RCC_AHB1Periph_GPIOE
#define D5_Pin	GPIO_Pin_1
#define D5_Port	GPIOE
#define D5_Clk 	RCC_AHB1Periph_GPIOE
#define D6_Pin	GPIO_Pin_2
#define D6_Port	GPIOE
#define D6_Clk 	RCC_AHB1Periph_GPIOE
#define D7_Pin	GPIO_Pin_3
#define D7_Port	GPIOE
#define D7_Clk 	RCC_AHB1Periph_GPIOE
#define RS_Pin	GPIO_Pin_4
#define RS_Port	GPIOE
#define RS_Clk 	RCC_AHB1Periph_GPIOE
#define EN_Pin	GPIO_Pin_5
#define EN_Port	GPIOE
#define EN_Clk 	RCC_AHB1Periph_GPIOE

extern void Delay_ms(uint32_t time);


void LCDInit(void);
void IntToStr(char *str, int INT, char dol);
void LCD_Command(char cmd);
void putchCP(char ch);
void putch(char vrsta, char stolpec, char ch);
void putstrCP(char *str);
void putstr(char vrsta, char stolpec, char *str);
void clrscr(void);
void LCD_Goto(char vrsta, char stolpec);
