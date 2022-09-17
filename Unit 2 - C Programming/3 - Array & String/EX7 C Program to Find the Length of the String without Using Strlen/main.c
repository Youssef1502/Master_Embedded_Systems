/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to Find the Length of the String
					Without Using Strlen Function
==================================================**/

#include<stdio.h>
int main()
{
	char str[50];
	int i=0 , count=0;

	printf("Enter the String : ");
	fflush(stdin);   fflush(stdout);
	gets(str);


	while(str[i] != 0)
	{
		count++;
		i++;
	}


	printf("Number of characters = %d" , count);

	return 0;
}
