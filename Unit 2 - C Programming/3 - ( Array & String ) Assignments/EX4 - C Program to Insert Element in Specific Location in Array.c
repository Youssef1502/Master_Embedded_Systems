/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Insert Element in Specific
                     Location in Array
==================================================**/

#include<stdio.h>
int main()
{
	int arr[20];
	int n=0 , i=0 , element=0 , location=0;

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


	printf("Enter the Element to be Inserted : \n");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&element);


	printf("Enter the Location : \n");
	fflush(stdin);   fflush(stdout);
	scanf("%d",&location);


	for(i=n ; i>0 ; i--)
	{
		if(i==(location-1))
		{
			arr[i] = element;
			break;
		}
		arr[i] = arr[i-1];
	}

	n=n+1;
	printf("Array after Insertion : \n");
	for(i=0 ; i<n ; i++)
		printf("%d ",arr[i]);

	return 0;
}
