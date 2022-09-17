/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Function to Take an Integer Number and Calculates it's
					Square Root
					INPUT = 4   -->  OUTPUT = 2.000
            		INPUT = 10  -->  OUTPUT = 3.162
==================================================**/

#include<stdio.h>
#include<math.h>

void square_root (int num)
{
	printf("Output = %f" , sqrt(num));
}

int main()
{
	int val;
	printf("Input = ");
	fflush(stdin);	fflush(stdout);
	scanf("%d" , &val);
	square_root(val);
}
