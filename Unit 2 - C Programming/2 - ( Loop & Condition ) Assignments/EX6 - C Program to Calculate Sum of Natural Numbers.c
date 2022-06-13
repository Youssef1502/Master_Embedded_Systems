/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Sum the Numbers from ( 1 to n )
==================================================**/

#include<stdio.h>

int main()
{
	int n , sum=0 ;
	printf("Enter an Integer Number : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &n );

	for (int i=1 ; i<=n ; i++)
	{
		sum += i ;
	}
	printf("Sum = %d" , sum);

	return 0;
}
