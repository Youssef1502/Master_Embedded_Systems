/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to Reverse a Sentence by Using Recursion
==================================================**/

#include <stdio.h>

void Reverse ()
{
	char c;
	scanf("%c" , &c);
	if(c != '\n')
	{
		Reverse();
		printf("%c",c);
	}
}


int main()
{
	printf("Enter a Sentence : ");
	fflush(stdin);    fflush(stdout);
	Reverse();
	return 0;
}

