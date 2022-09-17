/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   Calculate The Power of Number by Using Recursion
==================================================**/

#include <stdio.h>

int Power(int n , int p)
{
	if(p != 1)
		return n * Power(n , p-1);
}

int main()
{
	int num , pow , val ;
	printf("Enter Base number : ");
	fflush(stdin);    fflush(stdout);
	scanf("%d" , &num );
	printf("Enter Power number (Positive Integer) : ");
	fflush(stdin);    fflush(stdout);
	scanf("%d" , &pow );
	val = Power(num , pow);
	printf("%d^%d = %d" , num , pow , val);
	return 0;
}
