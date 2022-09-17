/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Create Stack Array-Based Implementation
==================================================**/

#ifndef _LIFO_H_
#define _LIFO_H_

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
	uint8_t Data[MAX] ;
	uint8_t TOP ;
}SStack;

typedef enum
{
	Stack_no_error,
	Stack_is_full,
	Stack_is_empty,
}status_e;


#endif
