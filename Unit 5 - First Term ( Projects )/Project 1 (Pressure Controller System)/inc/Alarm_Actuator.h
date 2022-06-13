/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   First Term Project 1 " Pressure Controller System "
==================================================**/

#ifndef ALARM_ACTUATOR_H_
#define ALARM_ACTUATOR_H_

#include "state.h"

// Define States
enum
{
	AA_INIT,
	AA_WAITING,
	AA_ALARM_OFF,
	AA_ALARM_ON
}AA_State_id;


// Declare States functions for main program
STATE_DEFINE(AA_INIT);
STATE_DEFINE(AA_WAITING);
STATE_DEFINE(AA_ALARM_OFF);
STATE_DEFINE(AA_ALARM_ON);

// STATE Pointer to function
extern void (*AActuator_State)();

#endif /* ALARM_ACTUATOR_H_ */
