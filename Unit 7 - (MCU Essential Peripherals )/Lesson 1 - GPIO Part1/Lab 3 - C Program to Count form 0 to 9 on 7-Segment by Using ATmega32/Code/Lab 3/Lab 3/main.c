/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Count form 0 to 9 on 7-Segment
                     by Using ATMEGA32 Microcontroller
==================================================**/

#include "Memory_Map.h"
#include <util/delay.h>

#define  F_CPU 8000000UL  // Clock Configuration

int main(void)
{
	DDRC = 0xff;
	unsigned int i , j;
	
    while (1) 
    {
		for(i=0 ; i<10 ; i++)
		{
			PORTC = (0b1011) | (i<<4);
			_delay_ms(3000);
		}
    }
}

