/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program for Toggle Led on STM32F103xx
==================================================**/

typedef volatile unsigned int vuint32_t ;

#include <stdint.h>
#include <stdlib.h>
#include <stdio.h>

// register address
#define GPIOA_BASE 0x40010800
#define GPIOA_CRH *(volatile uint32_t *)(GPIOA_BASE + 0x04)
#define GPIOA_ODR *(volatile uint32_t *)(GPIOA_BASE + 0x0C)

#define RCC_BASE  0x40021000
#define RCC_APB2ENR *(volatile uint32_t *)(RCC_BASE + 0x18)

int main(void)
{
	// Init GPIOA
	GPIOA_CRH &= 0xFF0FFFFF;
	GPIOA_CRH |= 0x00200000;


	//  Enable I/O PortA Clock
	//	Bit 2 IOPAEN: I/O port A clock enable
	//	Set and cleared by software.
	//	0: I/O port A clock disabled
	//	1:I/O port A clock enabled
	RCC_APB2ENR |= (1<<2);


	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}
