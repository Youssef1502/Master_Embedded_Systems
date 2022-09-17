/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to use ADC in ATmega32
==================================================**/


#define F_CPU 8000000UL 
#include <avr/io.h>
#include <stdlib.h>
#include "Infrastructure/LCD.h"
#include "HAL/ADC.h"

 
int main()
{
	u16 data;
	u16 pre_value;
	
	ADC_Init(VREF_AVCC , ADC_SCALER_128);
	LCD_Init();			/* Initialization of LCD */
	LCD_GOTO_XY(1,0);
	LCD_WRITE_STRING("ADC value :    ");	/* Write string on 1st line of LCD */
	LCD_GOTO_XY(2,0);
	LCD_WRITE_STRING("Pre value :    %");	/* Write string on 1st line of LCD */
	

	while(1)
	{
	
		LCD_GOTO_XY(1,12);				// LCD16x2 cursor position 
		data=ADC_Read(CH_7);			// Read ADC channel 0 
		LCD_Display_Number(data);
		if(data < 1000)
		{
			LCD_GOTO_XY(1,15);
			LCD_WRITE_CHAR(' ');
		}		
		
		LCD_GOTO_XY(2,12);
		pre_value = (ADC_Read(CH_7) / 1023.0) * 100.0;
		LCD_Display_Number(pre_value);
		if(pre_value < 100)
		{
			LCD_GOTO_XY(2,14);
			LCD_WRITE_CHAR(' ');
		}
	}
	return 0;
}
