/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Make Collision Avoidance System by
                     using the Modules
==================================================**/

#include "state.h"
#include "DC.h"

//Variables
int DC_speed = 0;

// STATE Pointer to function
void (*DC_state)();

void DC_init()
{
	// init PWM
	printf("DC_init");
}

void DC_motor(int S)
{
	DC_speed = S;
	DC_state = STATE(DC_busy);
	printf("CA ----speed=%d----> DC\n" , DC_speed);

}

STATE_define(DC_idle)
{
	// state name
	DC_state_id = DC_idle;

	// state action
	// Call PWM to make speed = DC_speed
	printf("DC_idle_State: speed=%d\n", DC_speed);
}


STATE_define(DC_busy)
{
	// state name
	DC_state_id = DC_busy;

	// state action
	// Call PWM to make speed = DC_speed
	DC_state = STATE(DC_idle);
	printf("DC_busy_State: speed=%d\n", DC_speed);
}

