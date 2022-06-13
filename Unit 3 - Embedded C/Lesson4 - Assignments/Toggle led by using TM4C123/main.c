/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program for Toggle Led
==================================================**/

typedef volatile unsigned long vulong32_t;

//#include<stdint.h>

#define  SYSCTL_BASE    0x400FE000
#define  GPIOF_BASE  0x40025000
#define SYSCTL_RCGC2_R  *((volatile vulong32_t *)(SYSCTL_BASE + 0x108))
#define GPIO_PORTF_DIR_R    *((volatile vulong32_t *)(GPIOF_BASE + 0x400))
#define GPIO_PORTF_DEN_R    *((volatile vulong32_t *)(GPIOF_BASE + 0x51C))
#define GPIO_PORTF_DATA_R    *((volatile vulong32_t *)(GPIOF_BASE + 0x3FC))

int main()
{
	// to close optimization for variable i use volatile
	volatile unsigned int i=0;
    SYSCTL_RCGC2_R = 0x00000020;
    // delay to make sure GPIOf is up and running
    for(i=0 ; i<200 ; i++);
    GPIO_PORTF_DIR_R |= 1<<3;
    GPIO_PORTF_DEN_R |= 1<<3;
    
    while(1)
    {
    	GPIO_PORTF_DATA_R |= 1<<3;
    	for(i=0 ; i<500000 ; i++);
    	GPIO_PORTF_DATA_R &= ~(1<<3);
    	for(i=0 ; i<500000 ; i++);
    }
	
	return 0;
}
