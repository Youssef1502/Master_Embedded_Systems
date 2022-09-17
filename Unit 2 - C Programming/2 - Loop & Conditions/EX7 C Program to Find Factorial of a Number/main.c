/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to Find Factorial of a Number
==================================================**/

#include<stdio.h>

int main()
{
	int n , sum=1 ;
	printf("Enter an Integer Number : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &n );

	if ( n>0 )
	{
		for (int i=1 ; i<=n ; i++)
		{
			sum *= i ;
		}
		printf("factorial (%d) is : %d " , n , sum);
	}

	else if ( n==0 )
		printf("factorial (%d) is : %d" , n , 1);

	else
		printf("Error!!! : Factorial of negative number not Exist");

	return 0;
}
