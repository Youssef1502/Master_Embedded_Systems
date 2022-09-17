/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a UART Application for ATmega32
==================================================**/

#include "avr/io.h"
#include "HAL/LCD_Driver/LCD.h"
#include "MCAL/UART/UART.h"

u8 str[100];
u32 num=0;

int main(void)
{
	/* Replace with your application code */
	LCD_Init();
	UART_Init();
	
	LCD_WRITE_STRING("UART TR");
	
	//UART_Send('Y');
	//UART_Send('A');
	//UART_Send('Y');
	
	UART_SendString("ahmed");
	UART_SendNumberU32(32767);
	
	while (1)
	{
		UART_ReceiveString(str);
		LCD_WRITE_STRING(str);
		
		//x = UART_Receive();
		//UART_Send(x);
		//LCD_WRITE_CHAR(x);
		
		
		
	}
}