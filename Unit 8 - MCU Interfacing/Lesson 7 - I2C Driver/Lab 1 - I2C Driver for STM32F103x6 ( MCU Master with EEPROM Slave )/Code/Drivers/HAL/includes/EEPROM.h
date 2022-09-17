/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :       EEPROM Driver
==================================================**/

#ifndef INCLUDES_EEPROM_H_
#define INCLUDES_EEPROM_H_

#include "STM32F103X6.h"
#include "STM32_F103C6_I2C_Driver.h"


// E2PROM is an I2C Slave
// Idle Mode : Device is high impedance state and wait for data
// Master Transmitter Mode : the device transmit data to a slave receiver
// Master Receive Mode : the device receives data from a slave transmitter

#define EEPROM_Slave_Address	0x2A  // this value defined by default

void EEPROM_Init(void);
unsigned char EEPROM_Write_NBytes(unsigned int Memory_address , unsigned char *bytes , uint8_t Data_Length);
unsigned char EEPROM_Read_Byte(unsigned int address , unsigned char *dataOut , uint8_t dataLen);

#endif /* INCLUDES_EEPROM_H_ */
