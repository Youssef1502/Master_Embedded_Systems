/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   UART Application
==================================================**/

#include "uart.h"

#define  Default_Stop  '\r'

void UART_Init(void)
{
	/*----- Baud rate----*/
	// 9600 and Crystal 8 MHz
	UBRRL = 51 ;
	CLEAR_BIT(UCSRA,U2X);  //normal mode (Divide by 16 bit)
	
	/*----- Frame-----*/
	// No Parity
	// 8 bit data is initialized value by default

	
	/*----- Enable UART TX , RX Pins ----*/
	SET_BIT(UCSRB,TXEN);
	SET_BIT(UCSRB,RXEN);
}


void UART_Send(u8 data)
{
	while(!READ_BIT(UCSRA,UDRE)); //UDRE: USART Data Register Empty (FLAG)
	UDR = data ;
}


u8 UART_Receive(void)
{
	while(!READ_BIT(UCSRA,RXC)); //RXC: USART Receive Complete (FLAG)
	return UDR ;
}


void UART_SendNumberU32(u32 num)
{
	char  str[7];
		
	sprintf(str,"%d",num);  // Adjust the formatting to your liking.
		
	UART_SendString(str);
}


void UART_SendString(char *str)
{
	while(*str > 0)
	{
		UART_Send(*str++);
	}
	UART_Send(Default_Stop);
}


void UART_ReceiveString(u8 *Buff)
{
	u8 i=0;
	Buff[i] =UART_Receive();
	UART_Send(Buff[i]);
	while(Buff[i] != Default_Stop)
	{
		i++;
		Buff[i] = UART_Receive();
		UART_Send(Buff[i]);
	}
	Buff[i]='\0';
}