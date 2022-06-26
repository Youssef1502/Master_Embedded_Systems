#define  F_CPU 8000000UL
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>

#define  IO_Base      0x20
#define  IO_DDRD      *((volatile unsigned char *)(IO_Base + 0x11))
#define  IO_PORTD     *((volatile unsigned char *)(IO_Base + 0x12))
#define  INT_GICR     *((volatile unsigned char *)(IO_Base + 0x3B))
#define  INT_MCUCR    *((volatile unsigned char *)(IO_Base + 0x35))
#define  INT_MCUCSR   *((volatile unsigned char *)(IO_Base + 0x34))
#define  INT_SREG     *((volatile unsigned char *)(IO_Base + 0x3F))

ISR(INT0_vect)
{
	IO_PORTD |=(1<<5);
	_delay_ms(300);
}

ISR(INT1_vect)
{
	IO_PORTD |=(1<<6);
	_delay_ms(300);
}

ISR(INT2_vect)
{
	IO_PORTD |=(1<<7);
	_delay_ms(300);
}

int main (void)
{
	// Make Pin ( 5 , 6 , 7 ) as Output Pins on portD
	IO_DDRD |= (0b111<<5);
	
	// Interrupt 0 Sense Control ( Any Logical Change )
	INT_MCUCR |= (1<<0);
	
	// Interrupt 1 Sense Control ( Rising Edge )
	INT_MCUCR |= (0b11<<2);
	
	// Interrupt 2 Sense Control ( Falling Edge )
	INT_MCUCSR &= ~(1<<6);
	
	// Enable Interrupt 0 , 1 , 2
	INT_GICR |= (0b111<<5);
	
	// Enable Global Interrupt
	sei();
	
	while(1)
	{
		IO_PORTD &=~(0b111<<5);
	}
	return 0;
}

