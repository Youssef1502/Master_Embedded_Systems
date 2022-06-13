/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Make Collision Avoidance System by
                     using one Module
==================================================**/

#include "state.h"
#include "CA.h"

//Variables
int CA_speed = 0;
int CA_distance = 0;
int CA_threshold = 50;

// STATE Pointer to function
void (*CA_state)();

// Function to generate Random Value
int US_Get_distance_random(int l , int r , int count);


STATE_define(CA_watting)
{
	// State Name
	CA_state_id = CA_watting;

	// State Action
	// DC_Motor (speed)
	CA_speed = 0;

	// Event Check
	CA_distance = US_Get_distance_random(45 , 55 , 1);
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_watting)) : (CA_state = STATE(CA_driving));
	printf("CA_wating_State: distance=%d  speed=%d\n" , CA_distance , CA_speed);
}


STATE_define(CA_driving)
{
	// State Name
	CA_state_id = CA_driving;

	// State Action
	// DC_Motor (CA_speed)
	CA_speed = 30;

	// event check
	// UltraSonic_Get_distance(CA_distance)
	CA_distance = US_Get_distance_random(45 , 55 , 1);
	(CA_distance <= CA_threshold)? (CA_state = STATE(CA_watting)) : (CA_state = STATE(CA_driving));
	printf("CA_driving_State: distance=%d  speed=%d\n" , CA_distance , CA_speed);
}


int US_Get_distance_random(int l , int r , int count)
{

	// this will generate random in range l to r
	int i;
	for(i=0 ; i<count ; i++)
	{
		int rand_num = (rand() %(r-l+1)) + l ;
		return rand_num;
	}
}
