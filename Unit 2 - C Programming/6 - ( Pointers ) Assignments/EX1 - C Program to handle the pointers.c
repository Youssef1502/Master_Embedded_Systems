/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a program in C to demonstrate how to handle the
                     pointers in the program
==================================================**/

#include <stdio.h>

int main()
{
	int m = 29;
	int* ab = NULL;
	printf("Address of m = 0x%p\n" , &m);
	printf("Value of m = %d\n" , m);

	printf("\nNow ab is assigned with the address of m\n");
	ab = &m;
	printf("Address of pointer ab = 0x%p\n" , ab);
	printf("Value of pointer ab = %d\n" , *ab);

	printf("\nThe value of m assigned to 34 now\n");
	m = 34;
	printf("Address of pointer ab = 0x%p\n" , ab);
	printf("Value of pointer ab = %d\n" , *ab);

	printf("\nThe pointer variable ab is assigned with the value 7 now\n");
	*ab = 7;
	printf("Address of m = 0x%p\n" , &m);
	printf("Value of m = %d\n" , m);

	return 0;
}
