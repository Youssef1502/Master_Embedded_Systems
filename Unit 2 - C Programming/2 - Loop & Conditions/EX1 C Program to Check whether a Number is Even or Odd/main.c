/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to Check whether a Number is Even or Odd
==================================================**/

#include<stdio.h>

int main()
{
	int val ;
	printf("Enter an Integer you want to Check : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &val);
	if (val%2 == 0)
		printf("%d is Even" , val);
	else
		printf("%d is Odd" , val);
	return 0;
}
