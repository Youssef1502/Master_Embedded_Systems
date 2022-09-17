/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Function to Reverse Words in String
					INPUT = Ahmed Adel Youssef  -->
					OUTPUT = Youssef Adel Ahmed
==================================================**/

#include<stdio.h>

void reverse(char arr[] , int size , int k)
{
	int j=0 , i;
	++size;
	for(i=size , j=0 ; j<k ; i++,j++)
	{
		printf("%c" , arr[i]);
	}
	printf(" ");
}

int main()
{
	char arr[] = "Ahmed Adel Youssef";
	unsigned int i=0 , k=0;
	int size = sizeof(arr) / sizeof(arr[0]);
	while(size >= 0)
	{
	--size;
	for(i=size , k=0 ; arr[i]!=' ' ; i--)
	{
		++k;
		if(i==0)
			break;
	}
	size = size - k;
	reverse(arr , size , k);

	}
}
