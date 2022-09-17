/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Function to Count Number of Ones in Binary Number
					INPUT = 5   -->  OUTPUT = 2
					INPUT = 15  -->  OUTPUT = 4
==================================================**/

#include<stdio.h>

int convert_to_binary(int num , int arr[])
{
	int i=0;
    while(num>0)
    {
        if((num%2) == 0)
        {
            arr[i]=0;
            num /=2 ;
            ++i;
        }

        else
        {
            arr[i]=1;
            num /=2 ;
            ++i;
        }
    }
    --i;
    return i;

}


int main()
{
    int num  , i=0 , count=0;
    int arr[32];

    printf("Decimal Number : ");
    fflush(stdin);    fflush(stdout);
    scanf("%d",&num);
    printf("%d in binary = " , num);
    i=convert_to_binary(num , arr);
    while(i>=0)
        {
    		printf("%d" , arr[i]);
            if(arr[i] == 1)
            	count++;
            --i;
        }
        printf("\nNumber of ones = %d" , count);

}
