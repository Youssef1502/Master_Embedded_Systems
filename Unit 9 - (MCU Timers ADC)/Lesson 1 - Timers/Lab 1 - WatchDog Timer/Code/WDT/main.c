/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Watch Dog Timer for ATmega32
==================================================**/

#define F_CPU 8000000UL
#include <avr/io.h>
#include <util/delay.h>

#define SET_BIT(PORT, BIT)			PORT |= (1<< BIT)
#define RESET_BIT(PORT, BIT)		PORT &= ~(1<<BIT)
#define TOG_BIT(PORT, BIT)			PORT ^= (1<<BIT)
#define GET_BIT(PORT, BIT)			PORT & (1<<BIT)
#define LED_Pin                     0

#define LED_DDR                     DDRC
#define LED_PORT                    PORTC


void WDT_Enable()
{
	// Watchdog Timer Prescale Select
	// 1 1 0 [ 1.0 sec ]
	WDTCR = (1 << WDP1) | (1 << WDP2) | (1 << WDE);
	RESET_BIT(WDTCR , WDP0);
}

void WDT_Disable()
{
	// To disable an enabled Watchdog Timer, the following procedure must be followed:
	// 1. In the same operation, write a logic one to WDTOE and WDE. A logic one must be written to WDE
	// even though it is set to one before the disable operation starts.
	// 2. Within the next four clock cycles, write a logic 0 to WDE. This disables the Watchdog
	
	WDTCR = (1<<WDTOE)|(1<<WDE);
	WDTCR = 0x00;
}

int main(void)
{
	// Make Led pin as Output
	SET_BIT(LED_DDR , LED_Pin);
	_delay_ms(500);
    
	while (1) 
    {
		WDT_Enable();
		_delay_ms(500);
		TOG_BIT(LED_PORT, LED_Pin);
		_delay_ms(900);
		WDT_Disable();
    }
}