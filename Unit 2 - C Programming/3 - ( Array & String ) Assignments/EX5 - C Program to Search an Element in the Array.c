/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Search an Element in the Array
==================================================**/

#include<stdio.h>
int main()
{
	int arr[20];
	int n=0 , i=0 , element=0;

	printf("Enter Number of elements between 0 to 20 : ");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&n);
	while(n<0 || n>20)
	{
		printf("Error!!! Number of Elements Should be Between 0 to 20 ");
		printf("Enter the Number Again : ");
		fflush(stdin);   fflush(stdout);
		scanf("%d",&n);
	}


	printf("Enter the Elements : \n");
	fflush(stdin);   fflush(stdout);
	for(i=0 ; i<n ; i++)
		scanf("%d",&arr[i]);


	printf("Enter the Element to be Searched : \n");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&element);


	for(i=0 ; i<n ; i++)
	{
		if(element==arr[i])
		{
			printf("Number Founded at the Location = %d" , i+1);
			break;
		}

	}

	if(i>=n)
	{
		printf("Number not Founded ... ");
	}

	return 0;

}
