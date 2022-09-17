/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to Make User Input the String and then Check
					how many times That Character is represented
					in the String
==================================================**/

#include<stdio.h>
#include<string.h>

int main()
{
	char str[50] , character;
	int i=0 , num=0 , count=0;

	printf("Enter the String : ");
	fflush(stdin);   fflush(stdout);
	gets(str);


	printf("Enter the Character to count : ");
	fflush(stdin);   fflush(stdout);
	scanf("%c" , &character);


	num = strlen(str);
	for(i=0 ; i<num ; i++)
	{
		if(str[i] == character)
			count++;
	}


	printf("Number of %c = %d" , character , count);

	return 0;
}
