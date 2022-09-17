/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Utils
==================================================**/


#ifndef UTILS_H_
#define UTILS_H_

// set bit to 1
#define SET_BIT(reg, bit)         (reg |= (1<<bit))

// clear bit to 0
#define CLEAR_BIT(reg, bit)       (reg &= ~(1<<bit))

// read bit digital value ( 1 or 0 )
#define READ_BIT(reg, bit)        ((reg>>bit) & 1)

#define TOGGLE_BIT(reg, bit)      (reg ^= (1<<bit))



#endif /* UTILS_H_ */