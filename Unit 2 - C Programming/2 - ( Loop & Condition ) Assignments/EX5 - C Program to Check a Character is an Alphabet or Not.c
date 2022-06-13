/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Check Whether a Character is
                     Alphabet or Not
==================================================**/

#include<stdio.h>

int main()
{
	char x ;
	printf("Enter a Character : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c" , &x );

	if ( (x>='a' && x<='z') || (x>='A' && x<='Z') )
		printf("%c is an Alphabet" , x);

	else
		printf("%c is not an Alphabet" , x);

	return 0;
}
