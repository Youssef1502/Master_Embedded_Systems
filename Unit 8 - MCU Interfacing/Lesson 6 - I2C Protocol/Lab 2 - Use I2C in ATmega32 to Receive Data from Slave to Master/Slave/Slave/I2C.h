/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write I2C Application for ATmega32
==================================================**/

// Slave Transmitter Master Receiver


#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
#define F_CPU 16000000UL /* 16 MegaHz(16 Million) */

void I2C_Set_Address(unsigned char address);
unsigned char I2C_Read(unsigned char ack);
void I2C_Write(unsigned char cByte);



#endif /* I2C_H_ */