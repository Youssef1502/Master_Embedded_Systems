/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Make a Simple Calculator to Add ,
                     Subtract , Multiply , Divide by Using Switch...Case
==================================================**/

#include<stdio.h>

int main()
{
	float x , y ;
	char character ;
	printf("Enter Two Numbers : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f" , &x , &y);
	printf("Enter operation either (+ , - , * , /) : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c" , &character);

	switch(character)
	{

	case '+':
		printf("%f + %f = %f" , x , y , x+y);
		break;

	case '-':
		printf("%f - %f = %f" , x , y , x-y);
		break;

	case '*':
		printf("%f * %f = %f" , x , y , x*y);
		break;

	case '/':
		printf("%f / %f = %f" , x , y , x/y);
		break;

	default :
		printf("invalid Choice !!!");
		break;

	}
	return 0;
}
