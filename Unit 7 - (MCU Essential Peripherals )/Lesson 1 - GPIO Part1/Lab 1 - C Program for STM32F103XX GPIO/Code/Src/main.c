/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program for STM32F103XX GPIO
==================================================**/

typedef volatile unsigned int vuint32_t;

#include<stdint.h>

// RCC
#define  RCC_BASE      0x40021000
#define  RCC_APB2ENR   *((volatile uint32_t *)(RCC_BASE + 0x18))

// GPIOA
#define  GPIOA_BASE    0x40010800
#define  GPIOA_CRL     *((volatile uint32_t *)(GPIOA_BASE + 0x00))
#define  GPIOA_CRH     *((volatile uint32_t *)(GPIOA_BASE + 0x04))
#define  GPIOA_ODR     *((volatile uint32_t *)(GPIOA_BASE + 0x0C))
#define  GPIOA_IDR     *((volatile uint32_t *)(GPIOA_BASE + 0x08))

// GPIOB
#define  GPIOB_BASE    0x40010C00
#define  GPIOB_CRL     *((volatile uint32_t *)(GPIOB_BASE + 0x00))
#define  GPIOB_CRH     *((volatile uint32_t *)(GPIOB_BASE + 0x04))
#define  GPIOB_ODR     *((volatile uint32_t *)(GPIOB_BASE + 0x0C))
#define  GPIOB_IDR     *((volatile uint32_t *)(GPIOB_BASE + 0x08))


void Clock_Init ()
{
	// Enable Clock GPIOA
	RCC_APB2ENR |= (1<<2);

	// Enable Clock GPIOB
	RCC_APB2ENR |= (1<<3);

}

void GPIO_Init()
{
	// Take Care CNF by Default 1 [ Check the Rest Value ]
	GPIOA_CRL = 0;
	GPIOA_CRH = 0;
	GPIOA_ODR = 0;

	// ================== Input Configuration ================== //

	// PA1 AS INPUT [ Floating ]
	// 00: Input mode (reset state)
	GPIOA_CRL &=~(0b11<<4);
	// 01: Floating input (reset state)
	GPIOA_CRL |=(0b01<<6);

	// PA13 AS INPUT [ Floating ]
	// 00: Input mode (reset state)
	GPIOA_CRH &=~(0b11<<20);
	// 01: Floating input (reset state)
	GPIOA_CRH |=(0b01<<22);

	// ================== Output Configuration ================== //

	// PB1 AS OUTPUT [ PUSH PULL mode ]
	// 01: Output mode, max speed 10 MHz
	GPIOB_CRL |=(0b01<<4);
	// 00: General purpose output push-pull
	GPIOB_CRL &=~(0b11<<6);

	// PB13 AS OUTPUT  [ PUSH PULL mode ]
	// 01: Output mode, max speed 10 MHz
	GPIOB_CRH |=(0b01<<20);
	// 00: General purpose output push-pull
	GPIOB_CRH &=~(0b11<<22);


}


void wait(vuint32_t time){
	vuint32_t i,j;
	for(i =0 ; i < time; i++)
		for(j= 0 ; j < 255; j++);
}

int main()
{
	Clock_Init();
	GPIO_Init();

	while(1)
	{
		if(((GPIOA_IDR & (1<<1)) >> 1) == 0)
		{
			GPIOB_ODR ^= (1<<1);
			while(((GPIOA_IDR & (1<<1)) >> 1) == 0);
		}

		if(((GPIOA_IDR & (1<<13)) >> 13) == 1)
		{
			GPIOB_ODR ^= (1<<13);
		}

		wait(1);
	}

	return 0;
}
