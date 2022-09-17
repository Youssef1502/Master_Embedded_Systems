/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write Application to Use LCD Driver and 
                     Keypad Driver with ATMEGA32
==================================================**/

#include "LCD_Driver/LCD.h"
#include "Keypad_Driver/Keypad.h"

int main(void)
{
    LCD_Init();
	KEYPAD_INIT();
	LCD_WRITE_STRING("YOUSSEF ADEL :   ");
	LCD_Display_Number(1502);
	LCD_WRITE_STRING(" : ");
	LCD_Display_Real_Number(19.9600);
	
	unsigned char Pressed_Key;
    while (1) 
    {
		Pressed_Key = KEYPAD_GET_CHAR();
		switch(Pressed_Key)
		{
			case('!'):
				LCD_Clear();
			break;
			
			case('N'):
				
			break;
			
			default:
				LCD_WRITE_CHAR(Pressed_Key);
			break;
		}
    }
}

