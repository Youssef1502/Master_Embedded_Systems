/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a UART Application for ATmega32
==================================================**/

#include "avr/io.h"
#include "HAL/LCD_Driver/LCD.h"
#include "MCAL/UART/UART.h"

u8 str[100];
u32 num=0;
u8 x=0 , y=0;

int main(void)
{
	sei();
	/* Replace with your application code */
	LCD_Init();
	UART_Init();
	//LCD_WRITE_STRING("UART TR");
	
	//UART_Send('Y');
	//UART_Send('A');
	//UART_Send('Y');
	
	//UART_SendString("ahmed");
	//UART_SendNumberU32(32767);
	
	UART_Send_String_Asynch("Ahmed");
	
	while (1)
	{
		//UART_ReceiveString(str);
		//LCD_WRITE_STRING(str);
		
		/*  first method to solve CPU stock in receiving data
		if (UART_Receive_Periodic_Check(&y))
		{
			LCD_WRITE_CHAR(y);
		}
		*/
		
		
		LCD_GOTO_XY(1,0);
		UART_ReceiveString(str);
		LCD_WRITE_STRING(str);
		LCD_GOTO_XY(2,9);
		LCD_Display_Number(x);
		x++;
		if(x==10)
			x=0;
		LCD_WRITE_STRING(" ");
		_delay_ms(200);
		
		//x = UART_Receive();
		//UART_Send(x);
		//LCD_WRITE_CHAR(x);
		
		
		
	}
}

