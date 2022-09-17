/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write Application to Use LCD Driver with ATMEGA32
==================================================**/

#include "LCD_Driver/LCD.h"

int main(void)
{
	int i=0;
    LCD_Init();
	
	LCD_WRITE_COMMAND(LCD_MOVE_CURSOR_RIGHT);
	LCD_WRITE_COMMAND(LCD_MOVE_CURSOR_RIGHT);
	LCD_WRITE_STRING("YOUSSEF ADEL");


	LCD_WRITE_COMMAND(LCD_BEGIN_AT_SECOND_ROW);
	Reset_Counter();
	for(i=0 ; i<5 ; i++)
	{
		LCD_WRITE_COMMAND(LCD_MOVE_CURSOR_RIGHT);
	}
	LCD_WRITE_STRING("YOUSSEF");
    while (1) 
    {

    }
}

