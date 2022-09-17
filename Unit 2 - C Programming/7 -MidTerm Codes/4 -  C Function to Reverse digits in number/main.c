/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Function to Reverse digits in number
					INPUT = 2457  -->  OUTPUT = 7542
					INPUT = 1057  -->  OUTPUT = 7501
==================================================**/

#include<stdio.h>

void reverse(int num)
{
	int i=0 , j=0 , count=0;
	int arr[10];
	while(num!=0)
	{
		arr[i] = num % 10;
		i++;
		num = num / 10;
		if(num > 0)
		{
			count++;
		}
		else
		{
			count++;
			break;
		}
	}
	for(j=0 ; j<count ; j++)
		printf("%d" , arr[j]);
}

int main()
{
	unsigned int val=2457;
	printf("Input = ");
	fflush(stdin);	fflush(stdout);
	scanf("%d" , &val);
	reverse(val);
}
