/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Function to Sum Numbers from 1 to 100 (Without Loop)
==================================================**/

#include<stdio.h>

int summation(int i)
{
	static int sum=0;
	if(i > 0)
	{
		summation(i-1);
		sum += i;
	}
	return sum;
}

int main()
{
	int sum=0 , n=100;
	sum = summation(n);
	printf("Summation from 1 to 100 = %d" , sum);
}
