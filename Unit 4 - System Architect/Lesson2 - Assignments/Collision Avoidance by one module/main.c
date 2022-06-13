/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Make Collision Avoidance System by
                     using one Module
==================================================**/

#include "CA.h"

void setup()
{
	// Init all drivers
	// Init IRQ
	// Init HAL US_Driver DC_Driver
	// Init Block
	// set States pointers for each block
	CA_state = STATE(CA_watting);
}

void main()
{
	setup();

	while(1)
	{
		//call state for each block
		CA_state();
	}
}
