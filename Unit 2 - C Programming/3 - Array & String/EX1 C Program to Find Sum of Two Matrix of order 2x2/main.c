/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to Find Sum of Two Matrix of Order (2x2)
==================================================**/

#include<stdio.h>
int main()
{
	float matrix1[2][2];
	float matrix2[2][2];
	int i=0 , j=0;
	printf("Enter The Elements of First Matrix : \n");
	fflush(stdin);   fflush(stdout);
	for(i=0 ; i<2 ; i++)
		for(j=0 ; j<2 ; j++)
			scanf("%f",&matrix1[i][j]);

	printf("\nEnter The Elements of Second Matrix : \n");
	fflush(stdin);   fflush(stdout);
	for(i=0 ; i<2 ; i++)
		for(j=0 ; j<2 ; j++)
			scanf("%f",&matrix2[i][j]);

	printf("\nSum of Matrix : \n");
	fflush(stdin);   fflush(stdout);
	for(i=0 ; i<2 ; i++)
	{
		for(j=0 ; j<2 ; j++)
		{
			printf("%0.1f\t",matrix1[i][j]+matrix2[i][j]);
		}
		printf("\n");
	}


	return 0;
}
