/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Find ASCII Value of a Character
==================================================**/

#include<stdio.h>

int main()
{
	char x ;
	printf("Enter a Character : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c", &x);
	printf("The ASCII Value of %c : %d" , x , x);
	return 0;
}
