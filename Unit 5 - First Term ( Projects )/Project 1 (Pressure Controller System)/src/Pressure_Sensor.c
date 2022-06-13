/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   First Term Project 1 " Pressure Controller System "
==================================================**/

#include "state.h"
#include "Pressure_Sensor.h"

static uint32_t PS_val;

void (*PSensor_State)();


STATE_DEFINE(PS_INIT)
{
	// Define function state
	PS_State_id = PS_INIT;

	// call reading function to read pressure value
	PSensor_State = STATE(PS_READIGN);
}

STATE_DEFINE(PS_READIGN)
{
	// Define function state
	PS_State_id = PS_READIGN;

	// Read Value From Pressure Sensor
	PS_val = getPressureVal();

	// call Waiting function to wait time until read another value
	PSensor_State = STATE(PS_WAITING);
}

STATE_DEFINE(PS_WAITING)
{
	// Define function state
	PS_State_id = PS_WAITING;

	// Call Delay function
	Delay(1000);

	// Call Reading function to read new Pressure Sensor value
	PSensor_State = STATE(PS_READIGN);
}

uint32_t Get_PS_Val()
{
	return PS_val;
}
