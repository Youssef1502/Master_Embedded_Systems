/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Find the Largest Number Between 3 Numbers
==================================================**/

#include<stdio.h>

int main()
{
	int x , y , z ;
	printf("Enter Three Numbers : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d %d %d" , &x , &y , &z);

	if ( x>y && x>z)
		printf("Largest Number is : %d" , x);

	else if ( y>x && y>z)
		printf("Largest Number is : %d" , y);

	else
		printf("Largest Number is : %d" , z);

	return 0;
}
