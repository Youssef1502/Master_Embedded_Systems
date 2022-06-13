/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   First Term Project 1 " Pressure Controller System "
==================================================**/

#include "state.h"
#include "Alarm_Actuator.h"

void (*AActuator_State)();


void Start_Alarm()
{
	AActuator_State = STATE(AA_ALARM_ON);
}

void Stop_Alarm()
{
	AActuator_State = STATE(AA_ALARM_OFF);
}


STATE_DEFINE(AA_INIT)
{
	// Define function state
	AA_State_id = AA_INIT;

	// go to AA_WAITING function to check the events
	AActuator_State = STATE(AA_WAITING);
}

STATE_DEFINE(AA_WAITING)
{
	// Define function state
	AA_State_id = AA_WAITING;
}

STATE_DEFINE(AA_ALARM_OFF)
{
	// Define function state
	AA_State_id = AA_ALARM_OFF;

	// Reset Alarm Actuator
	Set_Alarm_actuator(1);

	// Go to AA_WAITING Function to check another Event
	AActuator_State = STATE(AA_WAITING);
}

STATE_DEFINE(AA_ALARM_ON)
{
	// Define function state
	AA_State_id = AA_ALARM_ON;

	// Reset Alarm Actuator
	Set_Alarm_actuator(0);

	// Go to AA_WAITING Function to check another Event
	AActuator_State = STATE(AA_WAITING);
}
