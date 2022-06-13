/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   First Term Project 1 " Pressure Controller System "
==================================================**/

#ifndef PRESSURE_SENSOR_H_
#define PRESSURE_SENSOR_H_

#include "state.h"

// Define States
enum
{
	PS_INIT,
	PS_READIGN,
	PS_WAITING
}PS_State_id;


// Declare States functions for Pressure Sensor
STATE_DEFINE(PS_INIT);
STATE_DEFINE(PS_READIGN);
STATE_DEFINE(PS_WAITING);

// STATE Pointer to function
extern void (*PSensor_State)();

#endif /* PRESSURE_SENSOR_H_ */
