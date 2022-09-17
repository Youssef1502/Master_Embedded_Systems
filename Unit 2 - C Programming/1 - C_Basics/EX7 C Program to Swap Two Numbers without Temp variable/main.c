/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to Swap Two Numbers without TEMP variable
==================================================**/

#include<stdio.h>

int main()
{
	float a , b ;
	printf("Enter Value of a : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f" , &a );
	printf("Enter Value of b : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f" , &b );
	a = a + b ;
	b = a - b ;
	a = a - b ;
	printf("After swapping, value of a = %f\n" , a);
	printf("After swapping, value of b = %f" , b);
	return 0;
}

