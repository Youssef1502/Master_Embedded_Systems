/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Create Circler Queue Array-Based Implementation
==================================================**/

#include "Functions.h"

int main()
{
	unsigned int choice;
	uint8_t num;
	SQueue uart_Buffer;

	InitQueue(&uart_Buffer);

	while(1)
	{
		DPRINTF("\n=================================== \n")
	    /** display Queue elements Each Order **/
	    DPRINTF("\nSTACK ELEMENTS :"); dispItems(&uart_Buffer);

	    DPRINTF("\Queue OPTIONS \n0: Exit\n1: Add item\n2: Remove item \n3: Display items\
	    \n4: Top Item\n5: Clear Queue\n6: no. of stack elements\
	    		\n7: Queue is Full\n8: Queue is Empty \nchoice :::");

	    // get integer value only
	    while(scanf("%d" , &choice)!= 1)
	    {
	    	while(getchar() != '\n');
	    	DPRINTF("Enter integer Number :");
	    }

		switch(choice)
		{
		case 0:
			End_Queue(&uart_Buffer);
			break;

	    case 1:
	    	if(!Queue_is_Full(&uart_Buffer))
	    	{
	    		DPRINTF("Enter your Item :");
	    		scanf("%d" , &num);
	    		Add_Item(&uart_Buffer , num);
	    	}
	    	break;

	    case 2:
	    	if(!Queue_is_Empty(&uart_Buffer))
	    	{
	    		Remove_Item(&uart_Buffer);
	    	}
	    	break;

	    case 3:
	    	if(!Queue_is_Empty(&uart_Buffer))
	    	{
	    		dispItems(&uart_Buffer);
	    	}
	    	break;

	    case 4:
	    	if(!Queue_is_Empty(&uart_Buffer))
	    	{
	    		QueueTop(&uart_Buffer);
	    	}
	    	break;

	    case 5:
	    	if(!Queue_is_Empty(&uart_Buffer))
	    	{
	    		QueueClear(&uart_Buffer);
	    	}
	    	break;

	    case 6:
	    	if(!Queue_is_Empty(&uart_Buffer))
	    	{
	    		no_of_elements(&uart_Buffer);
	    	}
	    	break;

	    case 7 :
	    	if(!Queue_is_Full(&uart_Buffer))
	    	{
	    		DPRINTF("\nQueue Not Full\n");
	    	}
	    	break;

	    case 8 :
	    	if(!Queue_is_Empty(&uart_Buffer))
	    	{
	    		DPRINTF("\nQueue Not Empty\n");
	    	}
	    	break;

	    default :
	    	printf("\n!Valid Choice...\n");
	    	break;

		}

	}
	return 0;
}
