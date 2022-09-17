/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to Check whether a Number is
					Positive or Negative
==================================================**/

#include<stdio.h>

int main()
{
	int val ;
	printf("Enter a Number : ");
	fflush(stdin);
	fflush(stdout);
	scanf("%d" , &val);

	if ( val>0  )
		printf("%d is Positive" , val);

	else if ( val==0)
		printf("%d is Zero" , val);

	else
		printf("%d is Negative" , val);

	return 0;
}
