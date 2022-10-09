/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Macros Definition
==================================================**/


#ifndef UTILS_H_
#define UTILS_H_

#define SET_BIT(PORT, BIT)					( PORT |= (1 << BIT) )
#define CLEAR_BIT(PORT, BIT)				( PORT &= ~(1 << BIT) )
#define TOG_BIT(PORT, BIT)					( PORT ^= (1 << BIT) )
#define GET_BIT(PORT, BIT)					( (PORT & (1 << BIT)) >> BIT )

#endif /* UTILS_H_ */