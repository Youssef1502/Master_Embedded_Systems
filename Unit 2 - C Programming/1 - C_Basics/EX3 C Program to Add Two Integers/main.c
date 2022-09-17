/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to Add Two Integers
==================================================**/

#include<stdio.h>

int main()
{
	int num1 , num2 ;
	printf("Enter Two Integer Numbers : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d" , &num1 , &num2);
	printf("sum = %d" , num1 + num2);
	return 0;
}
