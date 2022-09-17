/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to ask the User to Enter a Matrix (size of
					matrix defined by user ) , and then find the Transpose
					of this matrix
==================================================**/

#include<stdio.h>
int main()
{
	int matrix[10][10];
	int transpose[10][10];
	int r=0 , c=0 ;
	int i=0 , j=0 ;


	printf("Enter Number of Rows and columns of the matrix (0 to 10) : ");
	fflush(stdin);   fflush(stdout);
	scanf("%d %d" , &r , &c);
	while(r<0 || r>10 || c<0 || c>10)
	{
		printf("Error!!! Number should be between 0 to 10 \n");
		printf("Enter the Number again : ");
		fflush(stdin);   fflush(stdout);
		scanf("%d %d" , &r , &c);
	}


	printf("Enter Elements of Matrix : \n");
	for(i=0 ; i<r ; i++)
	{
		for(j=0 ; j<c ; j++)
		{
			fflush(stdin);   fflush(stdout);
			scanf("%d" , &matrix[i][j]);
		}
	}


	printf("Entered Matrix : \n");
	for(i=0 ; i<r ; i++)
	{
		for(j=0 ; j<c ; j++)
		{
			printf("%d\t" , matrix[i][j]);
		}
		printf("\n");
	}


	for(i=0 ; i<r ; i++)
	{
		for(j=0 ; j<c ; j++)
		{
			transpose[j][i] = matrix[i][j];
		}
	}


	printf("Transpose of Matrix : \n");
	for(int i=0 ; i<c ; i++)
	{
		for(int j=0 ; j<r ; j++)
		{
			printf("%d\t" , transpose[i][j]);
		}
		printf("\n");
	}


	return 0;
}
