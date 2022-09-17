/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to Check Vowel or Constnent Letter [ where :
					(a,e,i,o,u) is Vowel , and all alphabets
					considered as Constnent ]
==================================================**/

#include<stdio.h>

int main()
{
	char x;
	printf("Enter an Alphabet : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%c" , &x);

	if (x=='a' || x=='A' || x=='e' || x=='E' || x=='i' || x=='I'
			|| x=='o' || x=='O' || x=='u' || x=='U' )
		printf("%c is a Vowel" , x);

	else
		printf("%c is a Constnent" , x);
	return 0;
}
