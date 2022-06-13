/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program for Toggle Led
==================================================**/

typedef volatile unsigned int vuint32_t;

#include<stdint.h>

#define  RCC_BASE    0x40021000
#define  GPIOA_BASE  0x40010800
#define RCC_APB2ENR  *((volatile uint32_t *)(RCC_BASE + 0x18))
#define GPIOA_CRH    *((volatile uint32_t *)(GPIOA_BASE + 0x04))
#define GPIOA_ODR    *((volatile uint32_t *)(GPIOA_BASE + 0x0C))

#define RCC_IOPAEN  (1<<2)
#define GPIO13      (1UL<<13)

typedef union
{
	vuint32_t  all_fields;
	struct
	{
		vuint32_t reserved:13;
		vuint32_t P_13:1;
	}Pin;
}R_ODR_t;

volatile R_ODR_t* R_ODR = (volatile R_ODR_t*)(GPIOA_BASE + 0x0C);
volatile char g_variables[3] = {1,2,3};
volatile char const const_variables[3] = {1,2,3};

int main()
{
	int i=0;
    RCC_APB2ENR |= RCC_IOPAEN;
    GPIOA_CRH &= 0xFF0FFFFF;
    GPIOA_CRH |= 0x00200000;
    while(1)
    {
    	R_ODR->Pin.P_13 =1;
    	for(i=0 ; i<500000 ; i++);
    	R_ODR->Pin.P_13 =0;
    	for(i=0 ; i<500000 ; i++);
    }
	return 0;
}
