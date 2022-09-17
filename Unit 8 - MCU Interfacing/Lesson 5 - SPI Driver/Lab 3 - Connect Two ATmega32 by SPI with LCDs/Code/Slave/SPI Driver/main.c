/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Connect Two MCU with SPI as [Master / Slave]
                     and Display Data on Two LCD
==================================================**/

#define F_CPU 8000000UL

#include <avr/io.h>
#include <util/delay.h>
#include "HAL/LCD.h"

//#define MASTER
#define SLAVE

void SPI_Init(void)
{
	#ifdef MASTER
		SPCR |= (1<<MSTR);
		SPCR &= ~(1<<CPOL);
	#endif
	
	#ifdef SLAVE
		SPCR &= ~(1<<MSTR);
	#endif
	
	SPCR |= (1<<SPE);   // Enable SPI Peripheral
	// speed 2MHz -> SPR1 = 0 , SPR0 = 0 -> SPCR  (Fcpu / 4)
}

uint8_t SPI_SendReceive(uint8_t data)
{
	SPDR = data;
	while(!((SPSR>>SPIF)&1));
	return SPDR;
}


int main(void)
{
	char data = '0' , receive_data;
	LCD_Init();
	SPI_Init();
	LCD_WRITE_STRING("SLAVE");
	
    while (1) 
    {
		receive_data = SPI_SendReceive(data);
		data++;
		if(data == '9'+1)
		{
			data = '0';
		}
		LCD_GOTO_XY(2,0);
		LCD_WRITE_CHAR(receive_data);
		_delay_ms(100);
		

    }
}

