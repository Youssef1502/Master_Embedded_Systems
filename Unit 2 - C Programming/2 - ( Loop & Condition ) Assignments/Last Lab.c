/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Use Nested Loop to Predict The Output
==================================================**/

#include<stdio.h>

int main()
{
	for(int i=0 ; i<=9 ; i++)
	{
		for(int j=i ; j<=9 ; j++)
		{
			printf("%d" , j);
		}
		printf("\n");
	}
	return 0;
}
