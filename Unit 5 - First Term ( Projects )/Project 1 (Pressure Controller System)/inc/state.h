/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   First Term Project 1 " Pressure Controller System "
==================================================**/

#ifndef STATE_H_
#define STATE_H_

#include<stdint.h>
#include<stdbool.h>
#include"driver.h"

typedef volatile unsigned int vuint32_t;

// Automatic STATE Function generated
#define STATE_DEFINE(_StateFun_) void ST_##_StateFun_()
#define STATE(_StateFun_) ST_##_StateFun_

// states connection
void Set_Pressure_Val(uint32_t value);
void High_Pressure_Detected(uint32_t st_val);
void Start_Alarm();
void Stop_Alarm();



#endif /* STATE_H_ */
