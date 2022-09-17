/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write Application to Use STM32F103x6 as I2C Master
                     with EEPROM as I2C Slave
==================================================**/


#include "STM32_F103C6_GPIO_Driver.h"
#include "STM32_F103C6_EXTI_Driver.h"
#include "STM32_F103C6_RCC_Driver.h"
#include "STM32_F103C6_USART_Driver.h"
#include "STM32_F103C6_SPI_Driver.h"
#include "STM32_F103C6_I2C_Driver.h"
#include "STM32F103X6.h"
#include "EEPROM.h"


void clock_init()
{
	//Enable CLock
	RCC_GPIOA_CLK_EN();
	RCC_GPIOB_CLK_EN();
}


int main()
{
	clock_init();

	//Test case 1
	uint8_t ch1[] = {0x1,0x2,0x3,0x4,0x5,0x6,0x7};
	uint8_t ch2[7]= {0};

	EEPROM_Init();
	EEPROM_Write_NBytes(0xAF, ch1, 7);
	EEPROM_Read_Byte(0xAF, ch2, 7);


	//Test case 2
	ch1[0] = 0xA;
	ch1[1] = 0xB;
	ch1[2] = 0xC;
	ch1[3] = 0xD;

	EEPROM_Write_NBytes(0xFFF, ch1, 4);
	EEPROM_Read_Byte(0xFFF, ch2, 4);

	while(1)
	{

	}
}
