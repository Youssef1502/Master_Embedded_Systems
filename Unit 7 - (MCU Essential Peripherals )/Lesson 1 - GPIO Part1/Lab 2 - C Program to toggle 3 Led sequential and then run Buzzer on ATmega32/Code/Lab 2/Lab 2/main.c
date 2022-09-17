/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to toggle 3 Led on sequential way and 
                     then start a tick(pulse) by Buzzer then and Return Again
                     by Using  ATMEGA32 Microcontroller
==================================================**/

#include <util/delay.h>
#include "Memory_Map.h"

#define  F_CPU 8000000UL  // Clock Configuration

int main(void)
{
	// PD0 AS OUTPUT PIN
	DDRD &= ~(1<<0);
	// P4 , DPD5 , PD6 , PD7 AS OUTPUT PINS
	DDRD |= (0b1111<<4);

    while (1) 
    {
		if(((PIND & (1<<0))>>0) == 0)
		{
			PORTD = (0b0010<<4);
			_delay_ms(1000);
			PORTD = (0b0100<<4);
			_delay_ms(1000);
			PORTD = (0b1000<<4);
			_delay_ms(1000);
			PORTD = (0b0001<<4);
			_delay_ms(2000);
			PORTD = (0b0000<<4);
		}
			
		
    }
}