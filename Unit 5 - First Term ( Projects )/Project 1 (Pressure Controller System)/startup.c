/* startup.c
   Author     :   YOUSSEF ADEL YOUSSEF
 */

#include<stdint.h>

extern int main(void);

extern unsigned int _stack_top ;

void Reset_Handler(void);

void Default_Handler()
{
	Reset_Handler();
}

void NMI_Handler(void)             __attribute__((weak,alias ("Default_Handler")));;
void H_fault_Handler(void)         __attribute__((weak,alias ("Default_Handler")));;
void Bus_Handler(void)             __attribute__((weak,alias ("Default_Handler")));;
void Usage_Fault_Handler(void)     __attribute__((weak,alias ("Default_Handler")));;


uint32_t vectors[] __attribute__((section(".vectors"))) =
{
	(uint32_t) &_stack_top,
	(uint32_t) &Reset_Handler,
	(uint32_t) &NMI_Handler,
	(uint32_t) &H_fault_Handler,
	(uint32_t) &Bus_Handler,
	(uint32_t) &Usage_Fault_Handler,
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
