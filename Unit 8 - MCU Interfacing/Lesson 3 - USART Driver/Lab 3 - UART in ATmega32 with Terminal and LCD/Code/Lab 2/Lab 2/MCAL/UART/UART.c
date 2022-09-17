/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   UART Application
==================================================**/

#include "uart.h"

#define  Default_Stop  '\r'

static u8* TX_Str;
static u8 flag_send = 1;

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

//  first method (Periodic Check) to solve CPU stock in receiving data
u8 UART_Receive_Periodic_Check(u8 * pdata)
{
	if(READ_BIT(UCSRA , RXC))
	{
		UART_Send(*pdata);
		*pdata = UDR;
		return 1;
	}
	return 0;
}

// Second method (Interrupt) to solve CPU stock in receiving data

void UART_SendNoBlock(u8 data)
{
	UDR = data;
}

u8 UART_ReceiveNoBlock(void)
{
	return UDR;
}

void UART_RX_InterrupEnable(void)
{
	SET_BIT(UCSRB , RXCIE);
}

void UART_RX_InterrupDisable(void)
{
	CLEAR_BIT(UCSRB , RXCIE);
}

void UART_TX_InterrupEnable(void)
{
	SET_BIT(UCSRB , TXCIE);
}

void UART_TX_InterrupDisable(void)
{
	CLEAR_BIT(UCSRB , TXCIE);
}


// function Asynchronous to send string
void UART_Send_String_Asynch(u8*str)
{
	if(flag_send == 1)
	{
		UART_TX_InterrupEnable();
		UART_SendNoBlock(str[0]);
		TX_Str = str;
		flag_send = 0;
	}
}


ISR(USART_TXC_vect)
{
	static u8 i = 1;
	if(TX_Str[i] != 0)
	{
		UART_SendNoBlock(TX_Str[i]);
		i++;
	}
	else
	{
		i=1;
		flag_send = 1;
		UART_TX_InterrupDisable();
	}
	
}