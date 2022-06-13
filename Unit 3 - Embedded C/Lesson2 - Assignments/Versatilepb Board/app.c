/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to send a “learn-in-depth:<your_Name>” 
                     by using UART
==================================================**/

#include<string.h>
#include"uart.h"

unsigned char Buffer1_str[100] = "Leran-in-depth : Youssef Adel";
unsigned char const Buffer2_str[100] = "for test only";

void main(void)
{
	Uart_Send_String(Buffer1_str);
}