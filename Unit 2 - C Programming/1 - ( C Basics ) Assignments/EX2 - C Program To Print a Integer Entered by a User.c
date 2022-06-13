/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Print a Integer Entered by a User
==================================================**/

#include<stdio.h>

int main()
{
	int val ;
	printf("Enter a Integer : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &val);
	printf("You Entered : %d" , val);
	return 0;
}
