/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Make Collision Avoidance System by
                     using the Modules
==================================================**/

#include "CA.h"
#include "US.h"
#include "DC.h"

void setup()
{
	// init all drivers
	// init IRQ
	// init HAL US_Driver DC_Driver
	// init Block
	US_init();
	DC_init();
	// set States pointers for each block
	CA_state = STATE(CA_waiting);
	US_state = STATE(US_busy);
	DC_state = STATE(DC_idle);
}

void main()
{
	volatile int i;
	setup();

	while(1)
	{
		//call state for each block
		US_state();
		CA_state();
		DC_state();
		//delay
		for(i=0 ; i<1000 ; i++);
	}
}
