/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write I2C Application for ATmega32
==================================================**/

// Slave Transmitter Master Receiver

#include <avr/io.h>
#include "I2C.h"

int main(void)
{
    unsigned char ch=0;
	I2C_Set_Address(0b11010000);        //Set Slave Address
    while (1) 
    {
		I2C_Read(1);                    //Read Byte send ACK
		I2C_Write(ch++);                //SLA(1001100)+R(1)
    }
	return 0;
}

