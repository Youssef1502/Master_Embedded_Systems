/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :       LCD Driver
==================================================**/

#include "LCD.h"

static int count=0;

void LCD_Init (void)
{
	#ifdef EIGHT_BIT_MODE
	_delay_ms(100);
	LCD_Dir_Control |= (1<<ENPIN) | (1<<RWPIN) | (1<<RSPIN);
	LCD_Control &= ~((1<<ENPIN) | (1<<RWPIN) | (1<<RSPIN));
	LCD_DPin = 0xFF;											// MAKE LCD PORT DIRECTION AS OUTPUT
	LCD_Clear();
	
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
	
	LCD_DPin = 0xFF;							 				// CONTROL LCD PINS [D4-D7]
	LCD_Dir_Control = 0xFF;										// MAKE CONTROL PINS OUTPUT
	LCD_Control &= (1<<RWPIN);									// MAKE RW PIN AS OUTPUT [ GROUND ]
	_delay_ms(15);												// WAIT BEFORE LCD ACTIVATION
	LCD_WRITE_COMMAND(FOUR_BIT_CONTROL);						// 4-BIT CONTROL
	LCD_WRITE_COMMAND(LCD_FUNCTION_4BIT_2LINES);				// CONTROL MATRIX 4-BIT
	LCD_WRITE_COMMAND(DISABLE_CURSOR);			   			    // DISABLE CURSOR
	LCD_WRITE_COMMAND(LCD_ENTRY_MODE);							// MOVE CURSOR
	LCD_WRITE_COMMAND(LCD_CLEAR_SCREEN);						// CLEAN LCD
	_delay_ms(2);
	#endif
}

void LCD_WRITE_COMMAND( unsigned char command )
{
	#ifdef EIGHT_BIT_MODE
	// TO SEND COMMAND TO LCD
	// A) SET PORT DIRECTION AS OUTPUT [ DONE IN INIT FUN ]
	LCD_Port = command;
	// TURN RW OFF SO YOU CAN WRITE
	// TURN RS OFF FOR COMMAND MODE
	LCD_Control &= ~((1<<RWPIN) | (1<<RSPIN));
	LCD_kick();
	#endif
	
	#ifdef FOUR_BIT_MODE
	// SEND THE DATA TWICE
	LCD_Port = (LCD_Port & 0x0F) | (command & 0xF0);
	LCD_Control &= ~ (1<<RSPIN);
	LCD_kick();
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (command << 4);
	LCD_kick();
	_delay_ms(2);
	#endif
}

void LCD_Clear()
{
	LCD_WRITE_COMMAND (LCD_CLEAR_SCREEN);			// CLEAN LCD
	_delay_ms(2);						// WAIT TO CLEAN LCD
	LCD_WRITE_COMMAND (LCD_BEGIN_AT_FIRST_ROW); 		// MOVE TO POSITION LINE 1 AND POSITION 0
	count=0;
}

void LCD_WRITE_CHAR(unsigned char Character)
{
	#ifdef EIGHT_BIT_MODE
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
	LCD_Port = Character ;
	// TURN RS ON FOR DATA MODE
	LCD_Control |= (1<<RSPIN);
	_delay_us(10);
	LCD_kick();
	_delay_us(10);
	count++;
	_delay_ms(15);
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
	LCD_Port = (LCD_Port & 0x0F) | (Character & 0xF0);
	// TURN RS ON FOR DATA MODE
	LCD_Control |= (1<<RSPIN);
	LCD_kick();
	_delay_us(200);
	LCD_Port = (LCD_Port & 0x0F) | (Character << 4);
	LCD_kick();
	_delay_ms(10);
	count++;
	_delay_ms(15);
	
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
	LCD_Control |= (1<<ENPIN);
	_delay_us(1);
	LCD_Control &= ~ (1<<ENPIN);
}

void LCD_GOTO_XY(unsigned char line, unsigned char position)
{
	if(line == 1)
	{
		if(position<16 && position>=0)
		LCD_WRITE_COMMAND(LCD_BEGIN_AT_FIRST_ROW);
	}
	
	else if (line == 2)
	{
		if(position<32 && position>=0)
		LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW);
	}
}

void LCD_Display_Number(int Number)
{
	char  str[7];
	
	sprintf(str,"%d",Number);  // Adjust the formatting to your liking.
	
	LCD_WRITE_STRING(str);
}

void LCD_Display_Real_Number(double Number)
{
	char str[16];
	
	char* TempSign = (Number < 0) ? "-" : "" ;
	float TempVal = (Number < 0) ? -Number : Number ;
	
	int TempInt1 = TempVal;               // Get the Integer (123).
	float TempFrac = TempVal - TempInt1;  // Get the fraction (0.456).
	int TempInt2 = TempFrac * 10000;      // turn fraction into integer.
	
	// print as parts, Note that you need 0-padding for fractional bit.
	
	sprintf(str , "%s%d.%04d" , TempSign , TempInt1 , TempInt2);
	
	LCD_WRITE_STRING(str);
	
}