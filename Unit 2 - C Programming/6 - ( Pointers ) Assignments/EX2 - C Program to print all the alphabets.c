/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a program in C to print all the alphabets using
                     a pointer. Go to the editor
==================================================**/

#include <stdio.h>

int main()
{

	char arr[27];
	char* pa = NULL;
	char i=0;

	pa = arr;
	for(i=0 ; i<26 ; i++)
	{
		*pa = i+'A';
		pa++;
	}

	pa = arr;
	for(i=0 ; i<26 ; i++)
	{
		printf("%c  " , *pa);
		pa++;
	}

	return 0;
}
