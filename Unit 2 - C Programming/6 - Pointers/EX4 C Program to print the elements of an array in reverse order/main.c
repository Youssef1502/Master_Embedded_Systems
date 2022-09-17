/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to print the elements of an array in reverse order
==================================================**/

#include <stdio.h>

int main()
{
	int arr[15]={0} , n=0 , i=0;
	int *ptr ;

	printf("Input the number of elements to store in the array (max 15) : ");
	fflush(stdin);		fflush(stdout);
	scanf("%d" , &n);
	printf("Input %d number of elements in the array : \n" ,n);

	ptr = arr;
	for(i=0 ; i<n ; i++)
	{
		printf("Element-%d : " , i+1);
		fflush(stdin);		fflush(stdout);
		scanf("%d" , ptr);
		ptr++;
	}

	printf("The elements of array in reverse order are :\n");
	ptr = &arr[n-1];
	for(i=n ; i>0 ; i--)
	{
		printf("Element-%d : %d\n" , i , *ptr);
		ptr--;
	}

	return 0;
}
