/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Make Collision Avoidance System by
                     using the Modules
==================================================**/

#include "state.h"
#include "CA.h"

//Variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

// STATE Pointer to function
void (*CA_state)();

void US_set_distance(int d)
{
	CA_distance = d;
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_waiting)) : (CA_state = STATE(CA_driving));
	printf("US ----distance=%d----> CA\n\n" , CA_distance);
}


STATE_define(CA_waiting)
{
	// state name
	CA_state_id = CA_waiting;
	printf("CA_wating_State: distance=%d  speed=%d\n" , CA_distance , CA_speed);

	// state action
	// DC_Motor (speed)
	CA_speed = 0;
	DC_motor(CA_speed);
}

STATE_define(CA_driving)
{
	// state name
	CA_state_id = CA_driving;
	printf("CA_driving_State: distance=%d  speed=%d\n" , CA_distance , CA_speed);

	// state action
	// DC_Motor (CA_speed)
	CA_speed = 30;
	DC_motor(CA_speed);

	// event check
	// UltraSonic_Get_distance(CA_distance)

}
