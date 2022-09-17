/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program for Toggle Led by Using External Interrupt
==================================================**/

typedef volatile unsigned int vuint32_t;

#include<stdint.h>

// RCC
#define  RCC_BASE      0x40021000
#define  RCC_APB2ENR   *((volatile uint32_t *)(RCC_BASE + 0x18))

// GPIO
#define  GPIOA_BASE    0x40010800
#define  GPIOA_CRL     *((volatile uint32_t *)(GPIOA_BASE + 0x00))
#define  GPIOA_CRH     *((volatile uint32_t *)(GPIOA_BASE + 0x04))
#define  GPIOA_ODR     *((volatile uint32_t *)(GPIOA_BASE + 0x0C))

// EXTI  ( External Interrupt )
#define  EXTI_BASE     0x40010400
#define  EXTI_IMR      *((volatile uint32_t *)(EXTI_BASE + 0x00))
#define  EXTI_RTSR     *((volatile uint32_t *)(EXTI_BASE + 0x08))
#define  EXTI_PR       *((volatile uint32_t *)(EXTI_BASE + 0x14))

// AFIO  ( Alternative Function I/O )
#define  AFIO_BASE     0x40010000
#define  AFIO_EXTICR1  *((volatile uint32_t *)(AFIO_BASE + 0x08))

// NVIC  ( Nested vectored interrupt controller )
#define  NVIC_EXTI0  *((volatile uint32_t *)(0xE000E100))


void Clock_Init ()
{
	// Enable Clock GPIOA
	RCC_APB2ENR |= (1<<2);

	// Bit 0 AFIOEN: Alternate function I/O clock enable
	RCC_APB2ENR |= (1<<0);
}

void GPIO_Init()
{
	// pin 13 port A output
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;

    // pinA 0 : Floating input (reset state)
    GPIOA_CRL |= (1<<2);
}

void EXTI0_IRQHandler()
{
	// Interrupt is Happened
	// EXTI0  >>>  PORTA Pin 0  ( Rising Edge )
	// Toggle Led Pin A 13
	GPIOA_ODR ^= (1<<13);

	// Clear Pending Request for Line 0  ( rc_w1 )
	EXTI_PR |= (1<<0) ;

	// EXTI0 configuration to PortA0
	AFIO_EXTICR1 = 0 ;


}

int main()
{
	Clock_Init();
	GPIO_Init();

	// Enable ExTI Line 0 ( Mask 1 )
	EXTI_IMR  |=  (1<<0) ;

	// Enable Rising Trigger
	EXTI_RTSR |=  (1<<0) ;

	// Enable NVIC IRQ6  <<>>  EXTI0  ( From Interrupt Vector Table )
	NVIC_EXTI0 |= (1<<6) ;



	while(1);

	return 0;
}
