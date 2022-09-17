/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Function to Count the Max Number of Ones Between
					Two Zeros
					INPUT = 14(01110)      -->  OUTPUT = 3
					INPUT = 110(01101110)  -->  OUTPUT = 3
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
    int num=0 , i=0 , count=0 , max=0;
    int arr[32]={0};

    printf("Decimal Number : ");
    fflush(stdin);    fflush(stdout);
    scanf("%d",&num);
    printf("%d in binary = " , num);
    i=convert_to_binary(num , arr);
    while(i>=0)
        {
    		printf("%d" , arr[i]);
            --i;
        }

    for(int j=0 ; j<32 ; j++)
    {
    	x:
    	if(arr[j]==0)
    	{
    		for(j=j+1 ; j<32 ; j++)
    		{
    			if(arr[j]==1)
    				count++;
    			else if(arr[j]==0)
    			{
    				if(max<count)
    				{
    					max = count;
    				}
    				count=0;
    				goto x;
    			}
    		}
    	}
    }
    printf("\n%d" , max);

}
