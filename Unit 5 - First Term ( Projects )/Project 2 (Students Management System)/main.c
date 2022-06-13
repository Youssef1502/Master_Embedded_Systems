/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Create Students Management System
                     by Queue
==================================================**/

#include "APIs.h"

int main()
{
	// initialize Variable for Switch Case
	unsigned int choice;
	DPRINTF("Welcome to Students Management System");


	while(1)
	{
		DPRINTF("\n=================================== \n");

		DPRINTF("\n-------BASIC QUEUE OPERATIONS (press (0) for exit)-------");
		DPRINTF("\n(1) Add New Student Details Manually");
		DPRINTF("\n(2) Add New Student Details from Text File");
		DPRINTF("\n(3) Find the Student Details by ID");
		DPRINTF("\n(4) Find the Student Details by First Name");
		DPRINTF("\n(5) Find the Student Details by Course ID");
		DPRINTF("\n(6) Find the Total Number of Students");
		DPRINTF("\n(7) Update the Student Details by ID");
		DPRINTF("\n(8) Delete the Student Details by ID");
		DPRINTF("\n(9) Show All Informations");

		DPRINTF("\nEnter integer Number :");

		// Wait Until Get Integer Value
		while(scanf("%d" , &choice)!= 1)
		{
			while(getchar() != '\n');
			DPRINTF("Enter integer Number :");
		}

		switch(choice)
		{
		case 0:
			Exit();
			break;

		case 1:
			Add_Student_Manual();
			break;

		case 2:
			Add_Student_from_File();
			break;

		case 3:
			Find_Student_by_ID();
			break;

		case 4:
			Find_Student_by_First_Name();
			break;

		case 5:
			Find_Student_by_Course_ID();
			break;

		case 6:
			Total_Number();
			break;

		case 7:
			Update_Details();
			break;

		case 8:
			Delete_Student_by_ID();
			break;

		case 9:
			Print_All_Students();
			break;

		default:
			DPRINTF("[ERROR] : Invalid Choice\n");
			break;
		}

	}

	return 0;
}
