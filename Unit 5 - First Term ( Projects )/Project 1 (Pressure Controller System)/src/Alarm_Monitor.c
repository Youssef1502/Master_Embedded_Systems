/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   First Term Project 1 " Pressure Controller System "
==================================================**/

#include"state.h"
#include"Alarm_Monitor.h"

void (*AMonitor_State)();


void High_Pressure_Detected(uint32_t st_val)
{
	if(st_val == true)
		AMonitor_State = STATE(AM_ALARM_ON);

	else
		AMonitor_State = STATE(AM_ALARM_OFF);
}


STATE_DEFINE(AM_ALARM_OFF)
{
	// Define function state
	AM_State_id = AM_ALARM_OFF;

	// stop Alarm Actuator at the beginning of program
	Stop_Alarm();

}

STATE_DEFINE(AM_ALARM_ON)
{
	// Define function state
	AM_State_id = AM_ALARM_ON;

	// Make Alarm Actuator On
	Start_Alarm();

	// Make Timer Start
	AMonitor_State = STATE(AM_WAITING);

}

STATE_DEFINE(AM_WAITING)
{
	// Define function state
	AM_State_id = AM_WAITING;

	// Run Alarm for Specific Duration
	Delay(600);

	// Stop Alarm Actuator Again until New Event
	AMonitor_State = STATE(AM_ALARM_OFF);
}
