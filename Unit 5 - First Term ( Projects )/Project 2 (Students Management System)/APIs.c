/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Create Students Management System
                     by Queue
==================================================**/

#include "APIs.h"

// Initialize the Queue
SStudent* head = NULL;
unsigned int count = 0;


void Exit()
{
	char ch;
	DPRINTF("\nare you sure to end the Program and Clear all Students : (y\\n)\n");
	scanf("%c" , &ch);

	// if you need to end the program
	if(ch == 'y')
	{
		free(head);
		DPRINTF("\nExit from the Program successfully\n");
		exit(0);
	}

	// if you need to continue
	else if(ch == 'n');

	// Invalid choice
	else
	{
		DPRINTF("\n![ERROR] Invalid Choice...\n")
	}
}


State_e Add_Student_Manual()
{
	SStudent* PNew ;
	SStudent* PLast ;
	SStudent* Ptest = head;

	if(head == NULL)
	{
		PNew = (SStudent*)malloc(sizeof(SStudent));
		if(PNew == NULL)
		{
			DPRINTF("[ERROR] Memory Not Allocated\n");
			return ERROR;
		}
		// if Memory succeed in allocated
		else
			head = PNew;
	}

	else if(count == MAX)
	{
		DPRINTF("[ERROR] The List is FULL\n");
		return ERROR;
	}

	else
	{
		PLast = head;
		// iterate until arrive the last node
		while(PLast->Next != NULL)
			PLast = PLast->Next;

		/// create new record
		PNew = (SStudent*)malloc(sizeof(SStudent));
		// Check if the Memory allocated or Not
		if(PNew == NULL)
		{
			DPRINTF("[ERROR] Memory Not Allocated\n");
			return ERROR;
		}
		else
			PLast->Next = PNew;
	}


	DPRINTF("\nEnter the ID : ");
	scanf("%d" , &PNew->student.ID);
	// Check if the ID Number is Used or Not
	for(int i=0 ; i<count ; i++)
	{
		if(PNew->student.ID == Ptest->student.ID)
		{
			DPRINTF("[ERROR : ID %d is Used]" , PNew->student.ID);
			PLast->Next = NULL;
			free(PNew);
			return ERROR;
		}
		else
			Ptest = Ptest->Next;
	}
	// Input Student Details
	DPRINTF("The First Name is ");
	gets(PNew->student.First_Name);
	DPRINTF("The Last Name is ");
	gets(PNew->student.Last_Name);
	DPRINTF("The GPA is ");
	scanf("%f" , &PNew->student.GPA);
	DPRINTF("Enter Number of Courses :\n")
	for(int j=0 ; j<5 ; j++)
	{
		DPRINTF("Course %d id : " , j );
		scanf("%d" , &PNew->student.Courses[j]);
	}
	PNew->Next = NULL;
	count++;
	DPRINTF("-----------------\n")
	DPRINTF("[INFO] : The Total Number of Students is : %d\n" , count);
	DPRINTF("[INFO] : You Can Add up to ( %d ) Students\n" , MAX);
	DPRINTF("[INFO] : You Can Add ( %d ) more Students\n" , (MAX - count));
	return DONE;
}


State_e Add_Student_from_File()
{
	FILE* PFile;
	unsigned int ID_Num;

	// Read the File
	PFile = fopen("students.txt" , "r");

	// Check is This File Existed or Not
	if(PFile == NULL)
	{
		printf("[ERROR] students.txt file isn't founded \n");
		return ERROR;
	}

	while(!feof(PFile))
	{

		//Reading ID Number of The Student
		fscanf( PFile , "%d" , &ID_Num );

		// Pointers to Build New Node for New Student Details
		SStudent* PNew ;
		SStudent* PLast ;
		SStudent* Ptest = head;

		if(head == NULL)
		{
			PNew = (SStudent*)malloc(sizeof(SStudent));
			if(PNew == NULL)
			{
				DPRINTF("[ERROR] Memory Not Allocated\n");
				return ERROR;
			}
			// if Memory succeed in allocated
			else
				head = PNew;
		}

		else if(count == MAX)
		{
			DPRINTF("[ERROR] The List is FULL\n");
			return ERROR;
		}

		else
		{
			PLast = head;
			// iterate until arrive the last node
			while(PLast->Next != NULL)
				PLast = PLast->Next;

			/// create new record
			PNew = (SStudent*)malloc(sizeof(SStudent));
			// Check if the Memory allocated or Not
			if(PNew == NULL)
			{
				DPRINTF("[ERROR] Memory Not Allocated\n");
				return ERROR;
			}
			else
				PLast->Next = PNew;
		}

		for(int i=0 ; i<count ; i++)
		{
			if(ID_Num == Ptest->student.ID)
			{
				DPRINTF("[ERROR] : ID Number %d Already Taken\n" , ID_Num);
				PLast->Next = NULL;
				// Ignore This Line
				fscanf(PFile, "%*[^\n]");
				break;
			}
			else
				Ptest = Ptest->Next;
		}

		// Entry to This Loop to Store the Data
		if((PLast->Next != NULL))
		{
			PNew->student.ID = ID_Num;
			fscanf( PFile , "%s" , &PNew->student.First_Name );
			fscanf( PFile , "%s" , &PNew->student.Last_Name );
			fscanf( PFile , "%f" , &PNew->student.GPA );
			for(int j=0 ; j<5 ; j++)
			{
				fscanf( PFile , "%d" , &PNew->student.Courses[j]);
			}
			DPRINTF("[INFO] : ID Number %d Successful Added\n" , ID_Num);
			PNew->Next = NULL;
			count++;
		}
	}


	fclose(PFile);
	return DONE;
}


State_e Find_Student_by_ID()
{
	SStudent* Pstudent = head;
	unsigned int ID_Num;

	// if the Queue is Empty
	if(head == NULL)
	{
		DPRINTF("[ERROR] : No Student to Print");
		return ERROR;
	}

	// if the Queue have Students
	else
	{
		DPRINTF("Enter ID Number for the Student : ");
		scanf("%d" , &ID_Num);

		for(int i=0 ; i<count ; i++)
		{
			if(Pstudent->student.ID == ID_Num)
			{
				// Print the Student Informations
				DPRINTF("First Name is : %s\n" , Pstudent->student.First_Name);
				DPRINTF("Last Name is : %s\n" , Pstudent->student.Last_Name);
				DPRINTF("ID is : %d\n" , Pstudent->student.ID);
				DPRINTF("GPA is : %0.2f\n" , Pstudent->student.GPA);
				DPRINTF("The Courses ID are : ")
				for(int j=0 ; j<5 ; j++)
					DPRINTF("%d   " , Pstudent->student.Courses[j] );
				return 1;
			}
			else
			{
				Pstudent = Pstudent->Next;
			}
		}

		// if we don't found this ID Number
		DPRINTF("[ERROR] ID Number ( %d ) Not Founded" , ID_Num);
		return ERROR;
	}

	return DONE;
}



State_e Find_Student_by_First_Name()
{
	SStudent* Pstudent = head;
	char text[20];
	unsigned char state = 0;

	if(head == NULL)
	{
		DPRINTF("[ERROR] : No Student to Print");
		return ERROR;
	}

	else
	{
		DPRINTF("Enter First Name for the Student : ");
		scanf("%s" , &text);

		for(int i=0 ; i<count ; i++)
		{
			if(strcmp(Pstudent->student.First_Name , text) == 0)
			{
				DPRINTF("First Name is : %s\n" , Pstudent->student.First_Name);
				DPRINTF("Last Name is : %s\n" , Pstudent->student.Last_Name);
				DPRINTF("ID is : %d\n" , Pstudent->student.ID);
				DPRINTF("GPA is : %0.2f\n" , Pstudent->student.GPA);
				DPRINTF("The Courses ID are : ")
				for(int j=0 ; j<5 ; j++)
					DPRINTF("%d   " , Pstudent->student.Courses[j] );
				DPRINTF("\n-------------\n");
				state++;
				Pstudent = Pstudent->Next;

			}
			else
			{
				Pstudent = Pstudent->Next;
			}
		}

		if(state==0)
		{
			DPRINTF("[ERROR] the Student ( %s ) Not Founded" , text);
			return ERROR;
		}
	}

	return DONE;
}


State_e Find_Student_by_Course_ID()
{
	SStudent* Pstudent = head;
	unsigned int Course_ID = 0;
	unsigned char state = 0;

	if(head == NULL)
	{
		DPRINTF("[ERROR] : No Student to Print");
		return ERROR;
	}

	else
	{
		DPRINTF("Enter Course ID to print the Students : ");
		scanf("%d" , &Course_ID);

		for(int i=0 ; i<count ; i++)
		{
			for(int j=0 ; j<5 ; j++)
			{
				if(Pstudent->student.Courses[j] == Course_ID)
				{
					DPRINTF("First Name is : %s\n" , Pstudent->student.First_Name);
					DPRINTF("Last Name is : %s\n" , Pstudent->student.Last_Name);
					DPRINTF("ID is : %d\n" , Pstudent->student.ID);
					DPRINTF("GPA is : %0.2f\n" , Pstudent->student.GPA);
					DPRINTF("\n-------------\n");
					state++;
					Pstudent = Pstudent->Next;
					break;
				}
				else
				{
					if(j==4)
						Pstudent = Pstudent->Next;
				}
			}
		}

		if(state==0)
		{
			DPRINTF("[ERROR] The Course ( %d ) do not has Students" , Course_ID);
			return ERROR;
		}

	return DONE;
	}

}



void Total_Number()
{
	// Give Informations to the User
	DPRINTF("[INFO] : The Total Number of Students is : %d\n" , count);
	DPRINTF("[INFO] : You Can Add up to ( %d ) Students\n" , MAX);
	DPRINTF("[INFO] : You Can Add ( %d ) more Students\n" , (MAX - count));
}


State_e Update_Details()
{
	SStudent* Pstudent = head;
	unsigned int ID_Num;
	unsigned int ch;

	if(head == NULL)
	{
		DPRINTF("[ERROR] : No Student to update");
		return 1;
	}

	else
	{
		DPRINTF("Enter ID Number to update the Student Information : ");
		scanf("%d" , &ID_Num);

		for(int i=0 ; i<count ; i++)
		{
			// If We Found the Required ID
			if(Pstudent->student.ID == ID_Num)
			{
				DPRINTF("1. First Name\n");
				DPRINTF("2. Last Name\n");
				DPRINTF("3. ID\n");
				DPRINTF("4. GPA\n");
				DPRINTF("5. Courses\n");
				DPRINTF("Enter Your choice 1/2/3/4/5 :");
				scanf("%d" , &ch);

				switch(ch)
				{
				case 1:
					DPRINTF("First Name is : \n");
					scanf("%s" , &Pstudent->student.First_Name);
					break;

				case 2:
					DPRINTF("Last Name is : ");
					scanf("%s" , &Pstudent->student.Last_Name);
					break;

				case 3:
					DPRINTF("ID is : ");
					scanf("%d" , &Pstudent->student.ID);
					break;

				case 4:
					DPRINTF("GPA is : ");
					scanf("%f" , &Pstudent->student.GPA);
					break;

				case 5:
					DPRINTF("The Courses ID are : ")
					for(int j=0 ; j<5 ; j++)
						scanf("%d" , &Pstudent->student.Courses[j] );
					break;

				default:
					DPRINTF("[ERROR] : !Invalid Choice\n");
				}
				DPRINTF("[INFO] UPDATED SUCCESSFULLY")
				return 1;
			}
			else
			{
				Pstudent = Pstudent->Next;
			}
		}

		DPRINTF("[ERROR] ID Number ( %d ) Not Founded" , ID_Num);
	}
}


State_e Delete_Student_by_ID()
{
	SStudent* PPrev;
	SStudent* PCurrent;
	unsigned int ID_Num;

	// if the Queue is Empty
	if(head == NULL)
	{
		DPRINTF("[ERROR] : No Student to Deleted\n");
		return ERROR;
	}

	// if the Queue have Students
	else
	{
		PPrev = head;
		PCurrent = head->Next;
		DPRINTF("Enter the ID Number for the Student : ");
		scanf("%d" , &ID_Num);

		while(PPrev!=NULL)
		{
			// if the Requires Student is the First Student
			if((PPrev->student.ID == ID_Num))
			{
				head = head->Next;
				free(PPrev);
				--count;
				return DONE;
			}

			else if(PCurrent->student.ID == ID_Num)
			{
				PPrev->Next = PCurrent->Next;
				free(PCurrent);
				--count;
				return DONE;
			}

			else
			{
				PCurrent = PCurrent->Next;
				PPrev = PPrev->Next;
			}
		}
		DPRINTF("[ERROR] ID Number ( %d ) Not Founded" , ID_Num);
		return ERROR;
	}
}

State_e Print_All_Students()
{
	SStudent* Pnode = head;

	if(Pnode == NULL)
	{
		DPRINTF("[ERROR] : No Student to Print");
		return ERROR;
	}
	else
	{
		for(int i=0 ; i<count ; i++)
		{
			DPRINTF("The Student Number %d :\n" , i+1);
			DPRINTF("First Name is : %s\n" , Pnode->student.First_Name);
			DPRINTF("Last Name is : %s\n" , Pnode->student.Last_Name);
			DPRINTF("ID is : %d\n" , Pnode->student.ID);
			DPRINTF("GPA is : %f\n" , Pnode->student.GPA);
			DPRINTF("The Courses ID are : ")
			for(int j=0 ; j<5 ; j++)
				DPRINTF("%d   " , Pnode->student.Courses[j] );
			DPRINTF("\n--------------------------------\n");

			Pnode = Pnode->Next;
		}
		return DONE;
	}

}
