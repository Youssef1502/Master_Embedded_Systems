/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to Multiply two Floating Point Numbers
==================================================**/

#include<stdio.h>

int main()
{
	float num1 , num2 ;
	printf("Enter Two Numbers : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%f %f" , &num1 , &num2);
	printf("Product = %f" , num1 * num2);
	return 0;
}
