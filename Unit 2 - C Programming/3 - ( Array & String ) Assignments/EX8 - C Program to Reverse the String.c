/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Reverse the String
==================================================**/

#include<stdio.h>
#include<string.h>
int main()
{
	char str[50] ;
	int i=0 , num=0 ;

	printf("Enter the String : ");
	fflush(stdin);   fflush(stdout);
	gets(str);


	num = strlen(str);
	for(i=num ; i>=0 ; i--)
	{
		printf("%c",str[i]);
	}


	return 0;
}
