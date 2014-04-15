#ifndef __LCD_H
#define __LCD_H

#include "stm32f0xx.h"
#include "stm32f0xx_rcc.h"
#include "stm32f0xx_gpio.h"

/*	Pin initialization of control and data signals */
#define LCD_CTRL_EN_PIN           		GPIO_Pin_15        		/* PB.1F */
#define LCD_CTRL_EN_GPIO_PORT      		GPIOB               	/* GPIOB */
#define LCD_CTRL_EN_GPIO_CLK      		RCC_AHBPeriph_GPIOB
#define LCD_CTRL_EN_SOURCE         		GPIO_PinSource15

#define LCD_CTRL_RS_PIN            		GPIO_Pin_13     		/* PB.13 */
#define LCD_CTRL_RS_GPIO_PORT      	 	GPIOB               	/* GPIOB */
#define LCD_CTRL_RS_GPIO_CLK        	RCC_AHBPeriph_GPIOB
#define LCD_CTRL_RS_SOURCE          	GPIO_PinSource13

#define LCD_CTRL_RW_PIN            		GPIO_Pin_14     		/* PB.14 */
#define LCD_CTRL_RS_GPIO_PORT      	 	GPIOB               	/* GPIOB */
#define LCD_CTRL_RS_GPIO_CLK        	RCC_AHBPeriph_GPIOB
#define LCD_CTRL_RS_SOURCE          	GPIO_PinSource14

#define LCD_CTRL_D4_PIN 				GPIO_Pin_6       		/* PC.6 */
#define LCD_CTRL_D4_GPIO_PORT       	GPIOC                	/* GPIOC */
#define LCD_CTRL_D4_GPIO_CLK        	RCC_AHBPeriph_GPIOC
#define LCD_CTRL_D4_SOURCE          	GPIO_PinSource6

#define LCD_CTRL_D5_PIN             	GPIO_Pin_7           	/* PC.7 */
#define LCD_CTRL_D5_GPIO_PORT       	GPIOC                 	/* GPIOC */
#define LCD_CTRL_D5_GPIO_CLK        	RCC_AHBPeriph_GPIOC
#define LCD_CTRL_D5_SOURCE          	GPIO_PinSource7

#define LCD_CTRL_D6_PIN             	GPIO_Pin_8        		/* PA.8 */
#define LCD_CTRL_D6_GPIO_PORT       	GPIOC               	/* GPIOC */
#define LCD_CTRL_D6_GPIO_CLK        	RCC_AHBPeriph_GPIOC
#define LCD_CTRL_D6_SOURCE          	GPIO_PinSource8

#define LCD_CTRL_D7_PIN             	GPIO_Pin_9     		/* PA.9 */
#define LCD_CTRL_D7_GPIO_PORT       	GPIOC               	/* GPIOC */
#define LCD_CTRL_D7_GPIO_CLK        	RCC_AHBPeriph_GPIOC
#define LCD_CTRL_D7_SOURCE      		GPIO_PinSource9

#define LCD_LINE_LENGTH					(uint8_t)16
#define LCD_LINE_TWO_ADDR				(uint8_t)64

#define LCD_EN_LOW()					GPIO_ResetBits(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_PIN)
#define LCD_EN_HIGH()					GPIO_SetBits(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_PIN)

#define LCD_RS_LOW()					GPIO_ResetBits(LCD_CTRL_RS_GPIO_PORT, LCD_CTRL_RS_PIN)
#define LCD_RS_HIGH()					GPIO_SetBits(LCD_CTRL_RS_GPIO_PORT, LCD_CTRL_RS_PIN)

#define LCD_RS(x)						GPIO_WriteBit(LCD_CTRL_RS_GPIO_PORT, LCD_CTRL_RS_PIN, x)
#define LCD_EN(x)						GPIO_WriteBit(LCD_CTRL_EN_GPIO_PORT, LCD_CTRL_EN_PIN, x)

#define GET_BIT(a, b)					((a >> b) & 1)


/*  LCD_Constants  */
#define LCD_DataLength_4Bit				(uint8_t)0

#define LCD_LineNumber_1Line			(uint8_t)0
#define LCD_LineNumber_2Lines			(uint8_t)8

#define LCD_CharacterFont_5x8Dots		(uint8_t)0
#define LCD_CharacterFont_5x10Dots		(uint8_t)4

#define LCD_CursorDirection_Decrement	(uint8_t)0
#define LCD_CursorDirection_Increment	(uint8_t)2

#define LCD_DisplayShift_NoShift		(uint8_t)0
#define LCD_DisplayShift_Shift			(uint8_t)1

#define LCD_DisplayState_On				(uint8_t)4
#define LCD_DisplayState_Off			(uint8_t)0

#define LCD_CursorState_On				(uint8_t)2
#define LCD_CursorState_Off				(uint8_t)0

#define LCD_BlinkCursor_On				(uint8_t)1
#define LCD_BlinkCursor_Off				(uint8_t)0

#define LCD_MoveOrShift_MoveCursor		(uint8_t)0
#define LCD_MoveOrShift_ShiftDisplay	(uint8_t)8

#define LCD_ShiftDirection_Left			(uint8_t)0
#define LCD_ShiftDirection_Right		(uint8_t)4

/*  LCD Commands  */
#define LCD_CMD_ClearDisplay			(uint8_t)1
#define LCD_CMD_CursorHome				(uint8_t)2

/*  LCD Command prefixes  */
#define LCD_PFX_EntryModeSet			(uint8_t)4
#define LCD_PFX_DisplayOnOff			(uint8_t)8
#define LCD_PFX_CursorDisplayShift		(uint8_t)16
#define LCD_PFX_FunctionSet				(uint8_t)32
#define LCD_PFX_CgramSetAddress			(uint8_t)64
#define LCD_PFX_DdramSetAddress			(uint8_t)128

/*  Structures  */
typedef struct
{
	uint8_t DataLength;			/*  LCD communication bus length. Only 4-bit supported yet  */
	uint8_t LineNumber;			/*  Number of lines displayed on LCD.  */
	uint8_t CharacterFont;		/*  Displayed character font  */
}LCD_InitTypeDef;

typedef struct
{
	uint8_t CursorDirection;	/*  Cursor move direction during data read/write  */
	uint8_t DisplayShift;		/*  Specifies display shift during data read/write  */
}LCD_EntryModeCmdTypeDef;

typedef struct
{
	uint8_t DisplayState;		/*  Display on/off control  */
	uint8_t CursorState;		/*  Cursor on/off control  */
	uint8_t BlinkCursor;		/*  Blinking at cursor position character on/off control  */
}LCD_DisplayOnOffCmdTypedef;

typedef struct
{
	uint8_t MoveOrShift;		/*  Specifies preferred printing mode  */
	uint8_t ShiftDirection;		/*  Specifies display shifting direcion if shifting on  */
}LCD_CursorDisplayShiftCmdTypeDef;

/*  Function Definitions  */
void LCD_Init(LCD_InitTypeDef *LCD_InitStruct);
void LCD_Clear(void);
void LCD_Goto(uint8_t cy, uint8_t cx);	//cx is column number, cy is row number
void LCD_WriteCustomCharacter(uint8_t num, const uint8_t *c);
void LCD_Putc(char c);
void LCD_Puts(const char *s);
void LCD_PutSignedInt(int32_t value);
void LCD_PutUnsignedInt(uint32_t value);

void LCD_LowLevel_Init();
void LCD_SendByte(uint8_t address, uint8_t n);
void LCD_SendNibble(uint8_t n);
void LCD_SetDdramAddress(uint8_t address);
void LCD_SetCgramAddress(uint8_t address);
void LCD_EntryModeCommand(LCD_EntryModeCmdTypeDef *LCD_EntryModeCmdStruct);
void LCD_DisplayOnOffCommand(LCD_DisplayOnOffCmdTypedef *LCD_DisplayOnOffStruct);
void LCD_CursorDisplayShiftCommand(LCD_CursorDisplayShiftCmdTypeDef *LCD_CursorDisplayShiftStruct);
void LCD_WriteCommand(uint8_t n);
void LCD_WriteData(uint8_t n);

void DelayMs(uint32_t nTime);

#endif
