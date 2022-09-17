/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Timer0 Driver for ATmega32
==================================================**/


#ifndef TIMERS_H_
#define TIMERS_H_


/*
 * =======================================================================================
 * 							Includes
 * =======================================================================================
 */

#include <avr/io.h>
#include <avr/interrupt.h>
#include "../Infrastrucure/Types.h"
#include "../Infrastrucure/Utils.h"

/*
 * =======================================================================================
 * 							Enumerations
 * =======================================================================================
 */

// Waveform Generation Mode Bit Description
typedef enum 
{
	NORMAL,
	CTC = 0x08,		
}TIMER0_MODE_t;


// Bit 1 – OCIE0:?Timer/CounterTimer/Counter0 Output Compare Match Interrupt Enable
typedef enum
{
	OCIE_DISABLE = 0x00,
	OCIE_ENABLE = 0x02
}OCMIE0_t;


// Bit 0 – TOIE0:?Timer/CounterTimer/Counter0 Overflow Interrupt Enable
typedef enum
{
	TOIE_DISABLE = 0x00,
	TOIE_ENABLE = 0x01
}TOVFIE0_t;


// Bits 2:0 – CS0n:?Clock Select
typedef enum
{
	NO_CLK_SRC,
	NO_PRESCALING,
	PRESCALING_CLK8,
	PRESCALING_CLK64,
	PRESCALING_CLK256,
	PRESCALING_CLK1024,
	EXT_CLK_FALLING,
	EXT_CLK_RISING,
}TIMER0_CLOCK_t;


/*
 * =======================================================================================
 * 							Configuration Structure
 * =======================================================================================
 */

typedef struct 
{
	TIMER0_MODE_t MODE;
	OCMIE0_t  OUT_CMP_INTERRUPT;
	TOVFIE0_t OVF_INTERRUPT;
	TIMER0_CLOCK_t CLK;	
}Timer0_Config_t;


/*
 * =======================================================================================
 * 							         APIs
 * =======================================================================================
 */

E_STATUS_t TIMER0_Init(Timer0_Config_t* Timer0_Config);
E_STATUS_t TIMER0_Stop();

E_STATUS_t TIMER0_GetCompareValue(ptr_uint8_t ptr_TicksNumber);
E_STATUS_t TIMER0_SetCompareValue(uint8_t TicksNumber);

E_STATUS_t TIMER0_GetCounterValue(ptr_uint8_t ptr_TicksNumber);
E_STATUS_t TIMER0_SetCounterValue(uint8_t TicksNumber);

E_STATUS_t TIMER0_GetOverflowValue(ptr_uint8_t ptr_TicksNumber);
E_STATUS_t TIMER0_SetOverflowValue(uint8_t TicksNumber);

void TIMER0_CALLBACK_Overflow_INTERRUPT(PTR_VoidFuncVoid_t callback);
void TIMER0_CALLBACK_CompareMatch_INTERRUPT(PTR_VoidFuncVoid_t callback);

#endif /* TIMERS_H_ */