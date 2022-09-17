/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Function to Return Unique Number in Array
					with ( One Loop )
					INPUT = a[7] = {4,2,5,2,5,7,4}  -->  OUTPUT = 7
					INPUT = a[3] = {4,2,4} -->  OUTPUT = 2
==================================================**/

#include<stdio.h>

int main()
{
	printf("Note : THIS PROGRAM WORK ONLY WHEN THE DUPLICATE "
			"NUMBERS ARE PAIRS\n");
	int arr[7] = {4,2,5,2,5,7,4};
	int i=1 , num=arr[0];
	for(i=1 ; i<7 ; i++)
	{
	num ^= arr[i];
	}
	printf("The Unique Number = %d" , num);
}

