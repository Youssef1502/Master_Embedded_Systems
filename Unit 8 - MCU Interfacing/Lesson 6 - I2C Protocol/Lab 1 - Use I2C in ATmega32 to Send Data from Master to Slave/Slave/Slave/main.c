/*
 * Slave.c
 *
 * Created: 8/12/2021 3:18:23 AM
 * Author : Kirellos Emad Samir
 */ 

#include <avr/io.h>


int main(void)
{
   DDRA=0xFF;
   I2C_Set_Address(0b11010000);         //Enable slave at address 01101000 and Don't accept general call
    while (1) 
    {
		PORTA = I2C_Read(1);             // Receive Byte and send ACK
    }
	return 0;
}


