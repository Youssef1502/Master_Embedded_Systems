/* startup.c
   Author : Youssef Adel Youssef
 */

#include<stdint.h>
extern int main(void);

void Reset_Handler(void);

void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler(void) __attribute__((weak,alias ("Default_Handler")));;
void H_fault_Handler(void) __attribute__((weak,alias ("Default_Handler")));;
void Bus_Handler(void) __attribute__((weak,alias ("Default_Handler")));;
void Usage_Fault_Handler(void) __attribute__((weak,alias ("Default_Handler")));;

static unsigned long stack_top[256] ;

void (* const g_p_fn_vectors[])() __attribute__((section(".vectors"))) =
{
	(void (*)()) ((unsigned long)stack_top + sizeof(stack_top)),
	&Reset_Handler,
	&NMI_Handler,
	&H_fault_Handler,
	&Bus_Handler,
	&Usage_Fault_Handler,
};

extern unsigned int _E_text ;
extern unsigned int _S_DATA ;
extern unsigned int _E_DATA ;
extern unsigned int _S_bss ;
extern unsigned int _E_bss ;

void Reset_Handler(void)
{
	int i=0;

	//  copy data section from flash to ram
	unsigned int DATA_size = (unsigned char*)&_E_DATA - (unsigned char*)&_S_DATA ;
	unsigned char* P_scr = (unsigned char*)&_E_text ;
	unsigned char* P_dst = (unsigned char*)&_S_DATA ;
	for(i=0 ; i<DATA_size ; i++)
	{
		*((unsigned char*)P_dst++) = *((unsigned char*)P_scr++);
	}

	// init the .bss with zero
	unsigned int bss_size = (unsigned char*)&_E_bss - (unsigned char*)&_S_bss ;
	P_dst = (unsigned char*)&_S_bss ;
	for(i=0 ; i<bss_size ; i++)
	{
		*((unsigned char*)P_dst++) = (unsigned char)0 ;
	}

	// jump to main()
	main();
}