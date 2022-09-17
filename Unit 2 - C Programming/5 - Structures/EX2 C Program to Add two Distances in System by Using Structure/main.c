/**==================================================
--    Author    :   				YOUSSEF ADEL YOUSSEF

-- Description  :   C Program to Add two Distances in [inch-feet ] System
					by Using Structure
==================================================**/

#include<stdio.h>

struct Distances
{
	int feet ;
	float inch ;
} D1 , D2 , sum;

int main()
{
	printf("Enter Information for 1st Distance :\n");
	printf("Enter feet : ");
	fflush(stdout); 	fflush(stdin);
	scanf("%d" , &D1.feet);
	printf("Enter inch : ");
	fflush(stdout); 	fflush(stdin);
	scanf("%f" , &D1.inch);

	printf("\nEnter Information for 2st Distance :\n");
	printf("Enter feet : ");
	fflush(stdout); 	fflush(stdin);
	scanf("%d" , &D2.feet);
	printf("Enter inch : ");
	fflush(stdout); 	fflush(stdin);
	scanf("%f" , &D2.inch);

	sum.feet = D1.feet + D2.feet;
	sum.inch = D1.inch + D2.inch;

	if(sum.inch >= 12)
	{
		sum.feet++ ;
		sum.inch -= 12.0 ;
	}

	printf("\nSum of  Distance = %d' %0.1f\" " , sum.feet , sum.inch);

	return 0;
}
