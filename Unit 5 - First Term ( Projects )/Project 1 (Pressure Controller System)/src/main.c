/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   First Term Project 1 " Pressure Controller System "
==================================================**/

#include <stdint.h>
#include <stdio.h>

#include "driver.h"
#include "Pressure_Sensor.h"
#include "Main_Program.h"
#include "Alarm_Monitor.h"
#include "Alarm_Actuator.h"

void Setup()
{
	GPIO_INITIALIZATION();

	PSensor_State = STATE(PS_INIT);
	MProgram_State = STATE(MP_HIGH_PRESSURE_DETECT);
	AMonitor_State = STATE(AM_ALARM_OFF);
	AActuator_State = STATE(AA_INIT);
}

int main ()
{
	Setup();

	while (1)
	{

		PSensor_State();
		MProgram_State();
		AMonitor_State();
		AActuator_State();
	}

	return 0;
}
