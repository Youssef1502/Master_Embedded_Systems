/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a program in C to print a string in
                     reverse using a pointer
==================================================**/

#include <stdio.h>

int main()
{
	char arr[50];
	char *ptr ;
	char i=0;
	char j=0;

	printf("Input a String : ");
	fflush(stdin);		fflush(stdout);
	scanf("%s" , arr);

	while(arr[j] != '\0')
	{
		i++;
		j++;
	}

	printf("Reverse of the String is :");
	ptr = arr;
	for(i ; i>=0 ; i--)
	{
		printf("%c" , *(ptr+i));
	}

	return 0;
}
