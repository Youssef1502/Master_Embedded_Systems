/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Create Circler Queue Array-Based Implementation
==================================================**/

#ifndef FIFO_H_
#define FIFO_H_

#include<stdio.h>
#include<stdlib.h>

#define MAX 10
#define DPRINTF(...)     {fflush(stdout); \
                          fflush(stdin); \
                          printf(__VA_ARGS__); \
                          fflush(stdout); \
                          fflush(stdin);}

typedef unsigned char   uint8_t ;

typedef struct
{
	uint8_t Data[MAX];
	uint8_t Base;
	uint8_t TOP;
}SQueue;

typedef enum
{
	Queue_no_error,
	Queue_is_full,
	Queue_is_empty
}status_e;


#endif /* FIFO_H_ */
