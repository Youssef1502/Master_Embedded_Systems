/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   Find The Prime Numbers Between Two Intervals by using
					Function
==================================================**/

#include<stdio.h>

int Check_Interval(int num)
{
	int j , flag=0;
	for(j=2 ; j<=num/2 ; j++)
	{
		if(num%j == 0)
		{
			flag=1;
		}
	}
	return flag;
}

int main()
{
	int num1 , num2 , i , flag;
	printf("Enter Two Numbers : ");
	fflush(stdin);    fflush(stdout);
	scanf("%d   %d" , &num1 , &num2);
	for(i=num1+1 ; i<num2 ; i++)
	{
		flag = Check_Interval(i);
		if(flag == 0)
			printf("%d  " , i);
	}
}

