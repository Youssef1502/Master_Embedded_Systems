/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   First Term Project 1 " Pressure Controller System "
==================================================**/

#ifndef ALARM_MONITOR_H_
#define ALARM_MONITOR_H_

#include "state.h"

// Define States
enum
{
    AM_ALARM_OFF,
	AM_ALARM_ON,
	AM_WAITING
}AM_State_id;


// Declare States functions for main program
STATE_DEFINE(AM_ALARM_OFF);
STATE_DEFINE(AM_ALARM_ON);
STATE_DEFINE(AM_WAITING);

// STATE Pointer to function
extern void (*AMonitor_State)();

#endif /* PS_H_ */
