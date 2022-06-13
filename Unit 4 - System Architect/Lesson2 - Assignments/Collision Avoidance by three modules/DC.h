/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Make Collision Avoidance System by
                     using the Modules
==================================================**/

#ifndef DC_H_
#define DC_H_

#include"state.h"

// Define States
enum
{
	DC_idle,
	DC_busy
}DC_state_id;

// declare states functions CA
STATE_define(DC_idle);
STATE_define(DC_busy);

void DC_init();

// STATE Pointer to function
extern void (*DC_state)();


#endif /* DC_H_ */
