/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   First Term Project 1 " Pressure Controller System "
==================================================**/

#ifndef MAIN_PROGRAM_H_
#define MAIN_PROGRAM_H_

#include "state.h"

// Define States
enum
{
	MP_HIGH_PRESSURE_DETECT
}MP_State_id;


// Declare States functions for main program
STATE_DEFINE(MP_HIGH_PRESSURE_DETECT);

// STATE Pointer to function
extern void (*MProgram_State)();

#endif /* PS_H_ */
