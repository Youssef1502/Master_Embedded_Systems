/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Takes n Numbers of Elements From User,
                     Stored Data in Array and then Calculates the Average
==================================================**/

#include<stdio.h>
int main()
{
	float arr[50];
	int n;
	float sum = 0.0 , avg=0.0;

	printf("Enter The Number of data between 0 to 50 : ");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&n);

	while(n<0 || n>50)
	{
		printf("Error!!! Number should be between 0 to 50 \n");
		printf("Enter The Number Again : ");
		fflush(stdin);   fflush(stdout);
		scanf("%d",&n);
	}

	for(int i=0 ; i<n ; i++)
	{
		scanf("%f",&arr[i]);
		sum += arr[i];
	}

	avg = sum / n;
	printf("Average = %f",avg);

	return 0;
}
