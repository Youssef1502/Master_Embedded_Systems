/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Function to Take a Number and Sum All Digits ?
					INPUT = 123   -->  OUTPUT = 6
            		INPUT = 4565  -->  OUTPUT = 20
==================================================**/

#include<stdio.h>

int summation(int num)
{
	int rem;                        // variable for reminder
	int sum=0;
	while(num!=0)
	{
		rem = num % 10;
		num = num / 10;
		if(num > 0)
		{
			sum += rem;
		}
		else
		{
			sum = sum + rem;
		}
	}
	return sum;
}

int main()
{
	unsigned int val=123;
	int sum ;
	printf("Input = ");
	fflush(stdin);	fflush(stdout);
	scanf("%d" , &val);
	sum = summation(val);
	printf("Output = %d" , sum);
}
