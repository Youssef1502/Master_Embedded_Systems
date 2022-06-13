/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Make Collision Avoidance System by
                     using the Modules
==================================================**/

#include "state.h"
#include "US.h"

//Variables
int US_distance = 0;

// STATE Pointer to function
void (*US_state)();
int US_Get_distance_random(int l , int r , int count);

void US_init()
{
	// init US Driver
	printf("US_init \n");
}


STATE_define(US_busy)
{
	// state name
	US_state_id = US_busy;

	// state action
	US_distance = US_Get_distance_random(45 , 55 , 1);
	printf("US_busy_State: distance=%d\n" , US_distance);
	US_set_distance(US_distance);
	US_state = STATE(US_busy);
}


int US_Get_distance_random(int l , int r , int count)
{

	// this will generate random in range i to r
	int i;
	for(i=0 ; i<count ; i++)
	{
		int rand_num = (rand() %(r-l+1)) + l ;
		return rand_num;
	}
}
