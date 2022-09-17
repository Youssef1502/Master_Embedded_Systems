/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Create Circler Queue Array-Based Implementation
==================================================**/

#ifndef FUNCTIONS_H_
#define FUNCTIONS_H_

#include "FIFO.h"

/** function: InitQueue( ), to Make Queue Empty in beginning **/
status_e InitQueue(SQueue *Q)
{
	Q->Base = 0;
	Q->TOP = 0;
	return Queue_no_error;
}
/** function: End_Queue( ), to End the Queue **/
status_e End_Queue(SQueue *Q)
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
    	return Queue_no_error;
    }
    else
    {
    	DPRINTF("\n!Invalid Choice...\n")
    }
}

/** function: dispItem( ), to display Queue Elements. **/
status_e dispItems(SQueue *Q)
{
    int i=0;
    DPRINTF("\n");
    for(i=Q->TOP;i>0;i--)
    	DPRINTF("%d->",Q->Data[i-1]);

    DPRINTF("\n");
    return Queue_no_error;
}

/** function: Add_Item( ), to insert an item into Queue. **/
status_e Add_Item(SQueue *Q,uint8_t item)
{
	Q->Data[Q->TOP] = item;
	Q->TOP++;
	return Queue_no_error;
}

/** function: Remove_Item( ), to delete an item from Queue. **/
status_e Remove_Item(SQueue *Q)
{
	int itm , i=0;
	itm=Q->Data[Q->Base];
	DPRINTF("\nItem removed : %d\n",itm);

	for(i=0 ; i<Q->TOP ; i++)
	{
		Q->Data[i] = Q->Data[i+1];
	}
	Q->TOP--;

	return Queue_no_error;
}

/** function: Queue_is_Full( ), to check Queue Full or not before push items **/
status_e Queue_is_Full(SQueue *Q)
{
	if(Q->TOP == MAX)
	{
		DPRINTF("\Queue is FULL.\n");
		return Queue_is_full;
	}

	else
		return Queue_no_error;

}

/** function: Queue_is_Empty( ), to check Queue Empty or not before Pop items **/
status_e Queue_is_Empty(SQueue *Q)
{
	if(Q->TOP == 0)
	{
		DPRINTF("\Queue is Empty.\n");
		return Queue_is_empty;
	}

	else
		return Queue_no_error;
}

/** function: QueueTop( ), to get Top Queue item **/
status_e QueueTop(SQueue *Q)
{
    int TopItem ;
    TopItem = Q->Data[Q->TOP-1];
    printf("\nThe Top Item is : %d\n" , TopItem);
    return Queue_no_error;
}

/** function: QueueClear( ), to Make Queue Empty from items **/
status_e QueueClear(SQueue *Q)
{
	char ch;
	DPRINTF("\nare you sure to clear all elements : (y\\n)\n");
    scanf("%c" , &ch);
    if(ch == 'y')
    {
    	Q->TOP = 0;
    	printf("\nSTACK is empty.\n");
    	return Queue_no_error;
    }
    else if(ch == 'n')
    {
    	return Queue_no_error;
    }
    else
    {
    	DPRINTF("\n!Invalid Choice...\n")
    }
}

/** function: no_of_elements( ), to return number of items from Queue **/
status_e no_of_elements(SQueue *Q)
{
	printf("\nthe STACK have ( %d ) Elements from ( %d ) Elements\n" , Q->TOP , MAX);
	return Queue_no_error;
}


#endif /* FUNCTIONS_H_ */
