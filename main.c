#include "stm32f0xx.h"
#include "stm32f0xx_gpio.h"
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_hd44780.h"


int main(void)
{
	LCD_InitTypeDef LCD_Initial;
	LCD_Initial.DataLength = 4;
	LCD_Initial.LineNumber = 2;
	LCD_Initial.CharacterFont = 0;

	LCD_Init(&LCD_Initial);

	while(1)
    {
		LCD_Goto(1, 1);
		LCD_Puts("Aytac Dilek");
		DelayMs(2000);
		LCD_Goto(2, 4);
		LCD_Puts("Deneme");
		DelayMs(2000);

		LCD_Clear();
		LCD_SendByte(0, 0x0E);
		LCD_Goto(1, 6);
		LCD_Putc('S');
		LCD_Putc('T');
		LCD_Putc('M');
		LCD_Putc('3');
		LCD_Putc('2');
		DelayMs(2000);

		LCD_Clear();
    }
}
