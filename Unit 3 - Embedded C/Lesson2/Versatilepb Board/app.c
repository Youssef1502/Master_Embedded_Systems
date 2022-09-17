/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to send a “learn-in-depth:<your_Name>” 
                     by using UART on Versatilepb Board
==================================================**/

#include"uart.h"

unsigned char Buffer1_str[100] = "Leran-in-depth:<Youssef_Adel>";
unsigned char const Buffer2_str[100] = "for test only";

void main(void)
{
	Uart_Send_String(Buffer1_str);
}