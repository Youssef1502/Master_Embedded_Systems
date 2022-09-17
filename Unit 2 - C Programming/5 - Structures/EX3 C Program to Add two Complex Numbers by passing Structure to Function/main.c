/**==================================================
--    Author    :   				YOUSSEF ADEL YOUSSEF

-- Description  :   C Program to Add two Complex Numbers by passing
					Structures to Function
==================================================**/

#include<stdio.h>

struct Complex
{
	float real;
	float img;

} C1 , C2 , sum ;

void Add(struct Complex num1 , struct Complex num2)
{
	sum.real = num1.real + num2.real;
	sum.img  = num1.img + num2.img;
	printf("sum = %0.1f + %0.1fi" , sum.real , sum.img);
}

int main()
{
	printf("      For 1st Complex Number\n");
	printf("Enter real and imaginary respectively : ");
	fflush(stdout);		fflush(stdin);
	scanf("%f   %f" , &C1.real , &C1.img);

	printf("\n      For 2st Complex Number\n");
	printf("Enter real and imaginary respectively : ");
	fflush(stdout);		fflush(stdin);
	scanf("%f   %f" , &C2.real , &C2.img);

	Add(C1 , C2);

	return 0;
}


