/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write I2C Application for ATmega32
==================================================**/

// Slave Transmitter Master Receiver

#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"

int main(void)
{
   unsigned char ch;
   DDRA=0xFF;                                    //PORTA is Output
   I2C_Init(0x48);                               //Initialize TWI for Master Code
    while (1) 
    {
		_delay_ms(5000);
		I2C_Start();                             //Transmit Start condition
		I2C_Write(0b11010000+1);                 //Transmit SLA+R(1)
		ch=I2C_Read(0);                          //read last Byte , send NACK
		I2C_Stop();
		PORTA=ch;
    }
	return 0;
}

