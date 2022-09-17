/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Create Stack Array-Based Implementation
==================================================**/

#include"LIFO.h"
#include"Functions.h"

int main()
{
	uint8_t num=0;
	SStack uart_stack ;
	InitStack(&uart_stack);

	unsigned int choice=0 ;

	while(1)
	{
		DPRINTF("\n=================================== \n")
	    /** display stack elements Each Order **/
	    DPRINTF("\nSTACK ELEMENTS :"); dispItems(&uart_stack);

	    DPRINTF("\nSTACK OPTIONS \n0: Exit\n1: Add item\n2: Remove item \n3: Display items\
	    \n4: Top Item\n5: Clear Stack\n6: no. of stack elements\
	    		\n7: Stack is Full\n8: Stack is Empty \nchoice :::");

	    // get integer value only
	    while(scanf("%d" , &choice)!= 1)
	    {
	    	while(getchar() != '\n');
	    	DPRINTF("Enter integer Number :");
	    }

	    switch(choice)
	    {
	    case 0 :
	    	End_Stack(&uart_stack);
	    	break;

	    case 1:
	    	if(!Stack_is_Full(&uart_stack))
	    	{
	    		DPRINTF("Enter your Item :");
	    		scanf("%d" , &num);
	    		Add_Item(&uart_stack , num);
	    	}
	    	break;

	    case 2:
	    	if(!Stack_is_Empty(&uart_stack))
	    	{
	    		Remove_Item(&uart_stack);
	    	}
	    	break;

	    case 3:
	    	if(!Stack_is_Empty(&uart_stack))
	    	{
	    		dispItems(&uart_stack);
	    	}
	    	break;

	    case 4:
	    	if(!Stack_is_Empty(&uart_stack))
	    	{
	    		StackTop(&uart_stack);
	    	}
	    	break;

	    case 5:
	    	if(!Stack_is_Empty(&uart_stack))
	    	{
	    		ClearStack(&uart_stack);
	    	}
	    	break;

	    case 6:
	    	if(!Stack_is_Empty(&uart_stack))
	    	{
	    		no_of_elements(&uart_stack);
	    	}
	    	break;

	    case 7 :
	    	if(!Stack_is_Full(&uart_stack))
	    	{
	    		DPRINTF("\nStack Not Full\n");
	    	}
	    	break;

	    case 8 :
	    	if(!Stack_is_Empty(&uart_stack))
	    	{
	    		DPRINTF("\nStack Not Empty\n");
	    	}
	    	break;

	    default :
	    	printf("\n!Valid Choice...\n");
	    	break;


	    }
	}
	return 0;
}







