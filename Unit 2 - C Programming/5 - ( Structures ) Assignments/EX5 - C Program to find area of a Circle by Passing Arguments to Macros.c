/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to find area of a Circle by Passing
                     Arguments to Macros [ Area of Circle = PI * r^2 ]

==================================================**/

#include<stdio.h>
#define PI 3.14
#define Area(r) (PI*(r)*(r))

int main()
{
	float radius ;
	float area ;

	printf("Enter The Radius : ");
	fflush(stdout);	fflush(stdin);
	scanf("%f" , &radius);

	area = Area(radius);
	printf("Area = %0.2f", area);

	return 0;
}


