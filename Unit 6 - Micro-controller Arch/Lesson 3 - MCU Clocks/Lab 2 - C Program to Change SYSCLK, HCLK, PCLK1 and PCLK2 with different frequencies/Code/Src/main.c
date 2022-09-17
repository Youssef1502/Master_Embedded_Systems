/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Change SYSCLK, HCLK, PCLK1 and
                     PCLK2 with different frequencies
==================================================**/

#if !defined(__SOFT_FP__) && defined(__ARM_FP)
#warning "FPU is not initialized, but the project is compiling for an FPU. Please initialize the FPU before use."
#endif

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
#define RCC_CFGR *(volatile uint32_t *)(RCC_BASE + 0x04)




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

	//	Bits 10:8 PPRE1[2:0]: APB Low-speed prescaler (APB1)
	//	Set and cleared by software to control the division factor of the APB Low speed clock (PCLK1).
	//	0xx: HCLK not divided
	//	100: HCLK divided by 2
	//	101: HCLK divided by 4
	//	110: HCLK divided by 8
	//	111: HCLK divided by 16
	RCC_CFGR |= (0b100 << 8);

	//	Bits 13:11 PPRE2[2:0]: APB high-speed prescaler (APB2)
	//	Set and cleared by software to control the division factor of the APB High speed clock (PCLK2).
	//	0xx: HCLK not divided
	//	100: HCLK divided by 2
	//	101: HCLK divided by 4
	//	110: HCLK divided by 8
	//	111: HCLK divided by 16
	RCC_CFGR |= (0b101 << 11);


	while(1)
	{
		GPIOA_ODR |= 1<<13 ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
		GPIOA_ODR &= ~(1<<13) ;
		for (int i = 0; i < 5000; i++); // arbitrary delay
	}
}
