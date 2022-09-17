/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Make Collision Avoidance System by
                     using the Modules
==================================================**/

#ifndef US_H_
#define US_H_

#include"state.h"

// Define States
enum
{
	US_busy
}US_state_id;

// declare states functions US
STATE_define(US_busy);

void US_init();

// STATE Pointer to function
extern void (*US_state)();


#endif /* US_H_ */
