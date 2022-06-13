#include"uart.h"

#define UARTDR *((volatile unsigned int* const)((unsigned int*)(0x101f1000)))

void Uart_Send_String(unsigned char *P_str)
{
	while(*P_str != '\0')
	{
		UARTDR = (unsigned int)(*P_str);
		*P_str++;
	}
}