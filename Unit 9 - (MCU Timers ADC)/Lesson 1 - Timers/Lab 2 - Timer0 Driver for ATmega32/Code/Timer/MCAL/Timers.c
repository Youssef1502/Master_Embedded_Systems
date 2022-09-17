/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Timer0 Driver for ATmega32
==================================================**/

/*
 * =======================================================================================
 * 									Includes 
 * =======================================================================================
 */

#include "Timers.h"

/*
 * =======================================================================================
 * 							GLOBAL & EXTERN VARIABLES   
 * =======================================================================================
 */

PTR_VoidFuncVoid_t CALLBACK_OVF;
PTR_VoidFuncVoid_t CALLBACK_CM;
uint8_t TOV_Number;

Timer0_Config_t* TIMER0_Configurations;


/*
 * =======================================================================================
 * 							APIS IMPLEMENTATION   
 * =======================================================================================
 */

E_STATUS_t TIMER0_Init(Timer0_Config_t* Timer0_Config)
{
	E_STATUS_t Ret_val = E_NOK;
	
	if (Timer0_Config == NULL_PTR)
	{
		Ret_val = E_NOK;
	}
	
	else
	{
		TIMER0_Configurations = Timer0_Config;
		
		if ((TIMER0_Configurations->MODE == NORMAL) || (TIMER0_Configurations->MODE == CTC))
		{
			TCCR0 |= TIMER0_Configurations->MODE;
			Ret_val = E_OK;
		}
		else
		{
			Ret_val = E_NOK;
		}
		
		
		if ((TIMER0_Configurations->CLK >= NO_CLK_SRC) && (TIMER0_Configurations->CLK <= EXT_CLK_RISING))
		{
			TCCR0 |= TIMER0_Configurations->CLK;
			Ret_val = E_OK;
		}
		else
		{
			Ret_val = E_NOK;
		}
		
		
		if ((TIMER0_Configurations->OUT_CMP_INTERRUPT == OCIE_DISABLE) || (TIMER0_Configurations->OUT_CMP_INTERRUPT == OCIE_ENABLE))
		{
			TIMSK |= TIMER0_Configurations->OUT_CMP_INTERRUPT;
			Ret_val = E_OK;
		}
		else
		{
			Ret_val = E_NOK;
		}
		
		
		if ((TIMER0_Configurations->OVF_INTERRUPT == TOIE_DISABLE) || (TIMER0_Configurations->OVF_INTERRUPT == TOIE_ENABLE))
		{
			TIMSK |= TIMER0_Configurations->OVF_INTERRUPT;
			Ret_val = E_OK;
		}
		else
		{
			Ret_val = E_NOK;
		}
		
	}
	return Ret_val;
}



E_STATUS_t TIMER0_Stop()
{
	E_STATUS_t Ret_val = E_NOK;
	TIMSK |= NO_CLK_SRC;
	return Ret_val;
}



E_STATUS_t TIMER0_GetCompareValue(ptr_uint8_t ptr_TicksNumber)
{
	E_STATUS_t Ret_val = E_NOK;
	*ptr_TicksNumber = OCR0;
	return Ret_val;
}



E_STATUS_t TIMER0_SetCompareValue(uint8_t TicksNumber)
{
	E_STATUS_t Ret_val = E_NOK;
	OCR0 = TicksNumber;
	return Ret_val;
}


E_STATUS_t TIMER0_GetCounterValue(ptr_uint8_t ptr_TicksNumber)
{
	E_STATUS_t Ret_val = E_NOK;
	*ptr_TicksNumber = TCNT0;
	return Ret_val;
}



E_STATUS_t TIMER0_SetCounterValue(uint8_t TicksNumber)
{
	E_STATUS_t Ret_val = E_NOK;
	TCNT0 = TicksNumber;
	return Ret_val;
}




E_STATUS_t TIMER0_GetOverflowValue(ptr_uint8_t ptr_TicksNumber)
{
	E_STATUS_t Ret_val = E_NOK;
	*ptr_TicksNumber = TOV_Number;
	return Ret_val;
}




E_STATUS_t TIMER0_SetOverflowValue(uint8_t TicksNumber)
{
	E_STATUS_t Ret_val = E_OK;
	TOV_Number = TicksNumber;
	return Ret_val;
}

void TIMER0_CALLBACK_CompareMatch_INTERRUPT(PTR_VoidFuncVoid_t callback)
{
	CALLBACK_CM = callback;
}

void TIMER0_CALLBACK_Overflow_INTERRUPT(PTR_VoidFuncVoid_t callback)
{
	CALLBACK_OVF = callback;
}

ISR(TIMER0_COMP_vect)
{
	CALLBACK_CM();
}

ISR(TIMER0_OVF_vect)
{
	TOV_Number++;
	CALLBACK_OVF();
}