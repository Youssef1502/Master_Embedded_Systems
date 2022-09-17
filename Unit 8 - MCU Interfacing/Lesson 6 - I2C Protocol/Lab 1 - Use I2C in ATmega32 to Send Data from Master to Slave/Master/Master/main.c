/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write I2C Application for ATmega32
==================================================**/

#include <avr/io.h>
#include <util/delay.h>
#include "I2C.h"

int main(void)
{
    unsigned char ch=0;
	I2C_Init(0x48);
    while (1) 
    {
		_delay_ms(5000);
		I2C_Start();                    // Transmit Start Condition
		I2C_Write(0b11010000+0);        // Transmit  SLA + W(0)
		while ((TWSR) != 0x18);         // SLA + W(0) has been transmitted and ACK has been Received
		I2C_Write(ch++);                // Transmit Data
		while ((TWSR) != 0x28);         // Data has been transmitted and ACK has been Received
		I2C_Stop();                     // Transmit Stop condition
    }
}

