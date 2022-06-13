/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Calculate The Factorial of Number by Using Recursion
==================================================**/

#include <stdio.h>

int factorial (int n)
{
	if(n!=1)
		return n * factorial(n-1);
}


int main()
{
	int num , fact;
	printf("Enter integer Number : ");
	fflush(stdin);   fflush(stdout);
	scanf("%d" , &num);
	fact = factorial(num);
	printf("facorial (%d) = %d" , num , fact);
	return 0;
}

