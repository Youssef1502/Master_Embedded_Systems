/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Make Collision Avoidance System by
                     using one Module
==================================================**/

#ifndef CA_H_
#define CA_H_

#include"state.h"

// Define States
enum
{
	CA_watting,
	CA_driving
}CA_state_id;

// declare states functions CA
STATE_define(CA_watting);
STATE_define(CA_driving);

// STATE Pointer to function
extern void (*CA_state)();


#endif /* CA_H_ */
