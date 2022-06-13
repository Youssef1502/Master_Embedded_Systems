/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write Source Code to Swap Two Numbers
==================================================**/

#include<stdio.h>

int main()
{
	float a , b , temp ;
	printf("Enter Value of a : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f" , &a );
	printf("Enter Value of b : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f" , &b );
	temp = a ;
	a = b ;
	b = temp ;
	printf("After swapping, value of a = %f\n" , a);
	printf("After swapping, value of b = %f" , b);
	return 0;
}
