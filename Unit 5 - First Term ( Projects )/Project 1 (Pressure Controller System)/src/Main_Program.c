/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   First Term Project 1 " Pressure Controller System "
==================================================**/

#include "state.h"
#include "Main_Program.h"

static uint32_t MP_val;
static uint32_t threshold = 20;

void (*MProgram_State)();


STATE_DEFINE(MP_HIGH_PRESSURE_DETECT)
{
	// Define function state
	MP_State_id = MP_HIGH_PRESSURE_DETECT;

	MP_val = Get_PS_Val();

	if(MP_val > threshold)
	{
		High_Pressure_Detected(true);
		MProgram_State = STATE(MP_HIGH_PRESSURE_DETECT);
	}
	else
	{
		MProgram_State = STATE(MP_HIGH_PRESSURE_DETECT);
	}

}
