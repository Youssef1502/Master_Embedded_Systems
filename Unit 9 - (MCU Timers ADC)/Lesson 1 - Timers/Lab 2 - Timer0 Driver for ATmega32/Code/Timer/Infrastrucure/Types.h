/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Type Definitions
==================================================**/


#ifndef TYPES_H_
#define TYPES_H_

typedef unsigned char		uint8_t;
typedef char				sint8_t;
typedef short				sint16_t;
typedef int					sint32_t;


typedef unsigned char * ptr_uint8_t;
typedef char * ptr_sint8_t;

typedef void(*PTR_VoidFuncVoid_t)(void);
#define NULL_PTR		((void*) (0))

typedef unsigned char E_STATUS_t;

#define E_OK		(E_STATUS_t)(0)  // returned if everything in configurations is Good
#define E_NOK		(E_STATUS_t)(1)  // returned if there error in configuration


#endif /* TYPES_H_ */