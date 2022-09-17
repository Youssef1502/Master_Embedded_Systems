/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Make Collision Avoidance System by
                     using the Modules
==================================================**/

#ifndef STATE_H_
#define STATE_H_

#include <stdio.h>
#include <stdlib.h>

// Automatic STATE Function generated
#define STATE_define(_statFUN_) void ST_##_statFUN_()
#define STATE(_statFUN_) ST_##_statFUN_

//states connection
void US_set_distance(int d);
void DC_motor(int S);

#endif /* STATE_H_ */
