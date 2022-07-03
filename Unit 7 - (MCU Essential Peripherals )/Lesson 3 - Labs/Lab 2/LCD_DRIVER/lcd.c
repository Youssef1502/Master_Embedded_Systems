/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :       LCD Driver
==================================================**/

#include "lcd.h"

static int count=0;


void delay_ms(uint32_t time)
{
	uint32_t i, j;
	for (i = 0; i < time; i++)
		for (j = 0; j < 255; j++);
}


void LCD_Init()
{
#ifdef EIGHT_BIT_MODE
	delay_ms(100);
	// LCD_Dir_Control |= (1<<ENPIN) | (1<<RWPIN) | (1<<RSPIN);
	PinCfg.GPIO_PinNumber = RSPIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = RWPIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = ENPIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	// LCD_Control &= ~((1<<ENPIN) | (1<<RWPIN) | (1<<RSPIN));
	MCAL_GPIO_WritePin(LCD_PORT, ENPIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RSPIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RWPIN, GPIO_PIN_RESET);

	//============================
	// SET THE NEXT 8 PINS AS OUTPUT
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	LCD_WRITE_COMMAND(LCD_FUNCTION_8BIT_2LINES);				// SELECT THE LCD COMMAND MODE

	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);
	LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	LCD_WRITE_COMMAND(LCD_DISP_ON_CURSOR_BLINK);
#endif

#ifdef FOUR_BIT_MODE
	// TO MAKE SURE THE FOUR BIT MODE WILL WORK GOOD
	// CONNECT RW PIN BY GROUND EXTERNALLY AND DO NOT CONNECT BY ANY SoC PINS

	// For 4-bit interface data, only four bus lines (DB4 to DB7) are used for transfer
	// SHOULD SEND [ 0x02 ] in LCD COMMAND BEFORE USE FOUR BIT MODE FROM LCD DATA SHEET
	//	DataDir_LCD_PORT |= (1 << EN_SWITCH | 1 << RS_SWITCH | 1 << RW_SWITCH);
	PinCfg.GPIO_PinNumber = RSPIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = RWPIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = ENPIN;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);


	MCAL_GPIO_WritePin(LCD_PORT, RWPIN, GPIO_PIN_RESET);

	//============================
	// SET THE NEXT 8 PINS AS INPUT
	PinCfg.GPIO_PinNumber = GPIO_PIN_0;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_1;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_2;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_3;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_4;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_5;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_6;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	PinCfg.GPIO_PinNumber = GPIO_PIN_7;
	PinCfg.GPIO_MODE = GPIO_MODE_OUTPUT_PP;
	PinCfg.GPIO_Output_Speed = GPIO_SPEED_10M;
	MCAL_GPIO_Init(LCD_PORT, &PinCfg);

	delay_ms(15);
	LCD_WRITE_COMMAND(FOUR_BIT_CONTROL);						// 4-BIT CONTROL
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);				// CONTROL MATRIX 4-BIT
	LCD_WRITE_COMMAND(DISABLE_CURSOR);			   			    // DISABLE CURSOR
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);							// MOVE CURSOR
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);						// CLEAN LCD
	delay_ms(2);
#endif
}


void LCD_WRITE_COMMAND(unsigned char command)
{
#ifdef EIGHT_BIT_MODE
	// TO SEND COMMAND TO LCD
	// A) SET PORT DIRECTION AS OUTPUT [ DONE IN INIT FUN ]
	MCAL_GPIO_WritePort(LCD_PORT, command);
	// TURN RW OFF SO YOU CAN WRITE
	// TURN RS OFF FOR COMMAND MODE
	MCAL_GPIO_WritePin(LCD_PORT, RWPIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RSPIN, GPIO_PIN_RESET);
	//	LCD_PORT &= ~((1 << RSPIN) | (1<<RWPIN));
	delay_ms(1);
	LCD_kick();
#endif

#ifdef FOUR_BIT_MODE
	// SEND THE DATA TWICE
	MCAL_GPIO_WritePort(LCD_PORT,(LCD_PORT->ODR & 0xFF0F) | (command & 0xF0));
	MCAL_GPIO_WritePin(LCD_PORT, RSPIN, GPIO_PIN_RESET);
	MCAL_GPIO_WritePin(LCD_PORT, RWPIN, GPIO_PIN_RESET);
	LCD_kick();
	delay_ms(2);
	MCAL_GPIO_WritePort(LCD_PORT, (LCD_PORT->ODR & 0xFF0F) | (command << 4));
	LCD_kick();
	delay_ms(2);
#endif
}


void LCD_Clear()
{
	LCD_WRITE_COMMAND (LCD_CLEAR_SCREEN);							// CLEAN LCD
	delay_ms(2);													// WAIT TO CLEAN LCD
	LCD_WRITE_COMMAND (LCD_BEGIN_AT_FIRST_ROW);
	count=0;
}


void LCD_WRITE_CHAR(unsigned char character)
{
#ifdef  EIGHT_BIT_MODE
	// TO SEND COMMAND TO LCD
	// A) SET PORT DIRECTION AS OUTPUT [ DONE IN INIT FUN ]

	if(count == 16)
	{
		LCD_GOTO_XY(2,0);
	}
	else if (count == 32)
	{
		LCD_Clear();
		LCD_GOTO_XY(1,0);
		count = 0;
	}
	MCAL_GPIO_WritePort(LCD_PORT, character);
	// TURN RS ON FOR DATA MODE
	MCAL_GPIO_WritePin(LCD_PORT, RSPIN, GPIO_PIN_SET);
	delay_ms(1);
	LCD_kick();
	delay_ms(2);
	count++;
	delay_ms(200);
#endif

#ifdef FOUR_BIT_MODE
	// TO MAKE SURE THE FOUR BIT MODE WILL WORK GOOD
	// CONNECT RW PIN BY GROUND EXTERNALLY AND DO NOT CONNECT BY ANY SoC PINS
	// TO SEND COMMAND TO LCD
	// A) SET PORT DIRECTION AS OUTPUT [ DONE IN INIT FUN ]
	if(count == 16)
	{
		LCD_GOTO_XY(2,0);
	}
	else if (count == 32)
	{
		LCD_Clear();
		LCD_GOTO_XY(1,0);
		count = 0;
	}
	MCAL_GPIO_WritePort(LCD_PORT,(LCD_PORT->ODR & 0xFF0F) | (character & 0xF0));
	// TURN RS ON FOR DATA MODE
	MCAL_GPIO_WritePin(LCD_PORT, RSPIN, GPIO_PIN_SET);
	LCD_kick();
	delay_ms(200);
	MCAL_GPIO_WritePort(LCD_PORT,(LCD_PORT->ODR & 0xFF0F) | (character << 4));
	delay_ms(1);
	LCD_kick();
	delay_ms(100);
#endif

}


void LCD_WRITE_STRING (char *str)
{
	while(*str > 0)
	{
		LCD_WRITE_CHAR(*str++);
	}
}


void LCD_kick()
{
	MCAL_GPIO_WritePin(LCD_PORT, ENPIN, GPIO_PIN_SET);
	delay_ms(2);
	MCAL_GPIO_WritePin(LCD_PORT, ENPIN, GPIO_PIN_RESET);
}


void LCD_GOTO_XY(unsigned char line, unsigned char position) {
	if (line == 1) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW + position);
		}
	}
	if (line == 2) {
		if (position < 16 && position >= 0) {
			LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW + position);
		}
	}
}
