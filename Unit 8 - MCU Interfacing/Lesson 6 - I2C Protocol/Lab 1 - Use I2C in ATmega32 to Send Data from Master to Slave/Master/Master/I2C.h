/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write I2C Application for ATmega32
==================================================**/

//Master Transmitter Slave Receiver

#ifndef I2C_H_
#define I2C_H_

#include <avr/io.h>
#define F_CPU 16000000UL /* 16 MegaHz(16 Million) */

void I2C_Init(unsigned long SCL_Clock);
void I2C_Start(void);
void I2C_Write(unsigned char cByte);
void I2C_Stop();


#endif /* I2C_H_ */s