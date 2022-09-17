/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Function to Print All Prime Numbers Between Two
					Numbers
					INPUT = n1=1,n2=20  -->  OUTPUT = 1 2 3 5 7 11 13 17 19
==================================================**/

#include<stdio.h>

void prime (int num1 , int num2)
{
	int i,a,count;
	for(i=num1 ; i<=num2;i++)
	{
		count=0;
		for(a=1 ; a<=i ; a++)
		{
			if(i%a == 0)
				count++;
		}
		if(count==2)
			printf("%d  ",i);
	}

}

int main()
{
	int n1 , n2 , temp;
	printf("Enter Two Values : ");
	fflush(stdin);	fflush(stdout);
	scanf("%d %d" , &n1 , &n2);
	if(n1 > n2)
	{
		temp = n1;
		n1 = n2;
		n2 = temp;
	}
	if(n1 == 1)
	{
		printf("%d  ",n1);
		++n1;
	}
	prime(n1,n2);
}
