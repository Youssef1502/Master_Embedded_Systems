/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Function to Take an Array and Reverse it's Elements
					INPUT = a[5]={1,2,3,4,5}  -->  OUTPUT = 5 4 3 2 1
==================================================**/

#include<stdio.h>

int main()
{
	int arr[] = {1,2,3,4,5};
	int size = sizeof(arr)/sizeof(arr[0]);
	int i;
	printf("array after reverse : ");
	for(i=size-1 ; i>=0 ; i--)
	{
		printf("%d " , arr[i]);
	}
}
