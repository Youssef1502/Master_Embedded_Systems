/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Create Stack Array-Based Implementation
==================================================**/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include"LIFO.h"

/** function: InitStack( ), to Make Stack Empty in beginning **/
status_e InitStack(SStack *s)
{
    s->TOP=0;
    return Stack_no_error;
}

/** function: End_Stack( ), to End the Stack **/
status_e End_Stack(SStack *s)
{
	char ch;
	DPRINTF("\nare you sure to end the Program and Clear all elements : (y\\n)\n");
    scanf("%c" , &ch);
    if(ch == 'y')
    {
    	DPRINTF("\nExit from the Program successfully\n");
        exit(0);
    }
    else if(ch == 'n')
    {
    	return Stack_no_error;
    }
    else
    {
    	DPRINTF("\n!Invalid Choice...\n")
    }

}

/** function: dispItem( ), to display Stack Elements. **/
status_e dispItems(SStack *s)
{
    int i=0;
    DPRINTF("\n");
    for(i=s->TOP;i>0;i--)
    	DPRINTF("%d->",s->Data[i-1]);

    DPRINTF("\n");
    return Stack_no_error;

}

/** function: Add_Item( ), to insert an item into stack. **/
status_e Add_Item(SStack *s,uint8_t item)
{
    s->Data[s->TOP] = item;
    s->TOP++;
    return Stack_no_error;
}

/** function: Remove_Item( ), to delete an item from stack. **/
status_e Remove_Item(SStack *s)
{
	int itm;
    s->TOP--;
    itm=s->Data[s->TOP];
    DPRINTF("\nItem removed : %d\n",itm);
    return Stack_no_error;
}


/** function: StackFull( ), to check stack Full or not before push items **/
status_e Stack_is_Full(SStack *s)
{
	if(s->TOP == MAX)
	{
		DPRINTF("\nSTACK is FULL.\n");
		return Stack_is_full;
	}

	else
		return Stack_no_error;
}

/** function: Stack_is_Empty( ), to check stack Empty or not before Pop items **/
status_e Stack_is_Empty(SStack *s)
{
	if(s->TOP == 0)
	{
		DPRINTF("\nSTACK is Empty.\n");
		return Stack_is_empty;
	}

	else
		return Stack_no_error;
}

/** function: StackTop( ), to get Top stack item **/
status_e StackTop(SStack *s)
{
    int TopItem ;
    TopItem = s->Data[s->TOP-1];
    printf("\nThe Top Item is : %d\n" , TopItem);
    return Stack_no_error;
}

/** function: ClearStack( ), to Make Stack Empty from items **/
status_e ClearStack(SStack *s)
{
	char ch;
	DPRINTF("\nare you sure to clear all elements : (y\\n)\n");
    scanf("%c" , &ch);
    if(ch == 'y')
    {
    	s->TOP = 0;
    	printf("\nSTACK is empty.\n");
    	return Stack_no_error;
    }
    else if(ch == 'n')
    {
    	return Stack_no_error;
    }
    else
    {
    	DPRINTF("\n!Invalid Choice...\n")
    }

}

/** function: no_of_elements( ), to return number of items from stack **/
status_e no_of_elements(SStack *s)
{
    printf("\nthe STACK have ( %d ) Elements from ( %d ) Elements\n" , s->TOP , MAX);
    return Stack_no_error;
}

#endif /* FUNCTIONS_H_ */
