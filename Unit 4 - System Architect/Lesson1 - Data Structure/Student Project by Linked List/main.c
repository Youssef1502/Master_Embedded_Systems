/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Create Student Database by Using
                     Linked List
==================================================**/

#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<conio.h>

#define DPRINTF(...)     {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__); \
		fflush(stdout); \
		fflush(stdin);}

// Effective Data
struct SData
{
	unsigned int ID;
	char Name[40];
	float Hight;
};


// Linked List Node
typedef struct S_student
{
	struct SData student;
	struct S_student* Next;
}SStudent;

// pointer to Build a Linked List
SStudent* head = NULL;

//APIs

int Close_Program()
{
	char ch;
	DPRINTF("\nare you sure to end the Program and Clear all Students : (y\\n)\n");
	scanf("%c" , &ch);
	// if you need to end the program
	if(ch == 'y')
	{
		DPRINTF("\nExit from the Program successfully\n");
		exit(0);
	}
	// if you need to continue
	else if(ch == 'n')
	{
		return 1;
	}
	// Invalid choice
	else
	{
		DPRINTF("\n!Invalid Choice...\n")
	}
}


int Add_Student()
{
	// Function Definitions
	SStudent* PNewStudent;
	SStudent* PLastStudent;
	char text[40];

	// Check List is empty == yes
	if(head == NULL)
	{
		PNewStudent = (SStudent*)malloc(sizeof(SStudent));
		// Check if the Memory Not allocated
		if(PNewStudent == NULL)
		{
			DPRINTF("Error! Memory Not Allocated\n");
			return 1;
		}
		// if Memory succeed in allocated
		else
			head = PNewStudent;
	}

	// NO
	else  // List have a record
	{
		// navigate until reach to the last record
		PLastStudent = head;
		while(PLastStudent->Next)  /// also can be write while(PLastStudent->PNextStudent != NULL)
			PLastStudent = PLastStudent->Next;

		/// create new record
		PNewStudent = (SStudent*)malloc(sizeof(SStudent));
		// Check if the Memory allocated or Not
		if(PNewStudent == NULL)
		{
			DPRINTF("Error! Memory Not Allocated\n");
			return 1;
		}
		else
			PLastStudent->Next = PNewStudent;
	}

	// fill new record
	DPRINTF("\n Enter the Student ID: ");
	gets(text);
	PNewStudent->student.ID = atoi(text);

	DPRINTF("\n Enter Student Full Name : ");
	gets(text);
	strcpy(PNewStudent->student.Name , text);

	DPRINTF("\n Enter the Student height: ");
	gets(text);
	PNewStudent->student.Hight = atof(text);
	/// set the next pointer (new_student) null
	PNewStudent->Next = NULL;
}


void View_All_Students()
{
	unsigned char count=1;
	SStudent* PList;
	// Check if List is Empty
	if(head == NULL)
		printf("There is no Students in the List\n");

	else
	{
		// navigate until arrive the end of Linked List
		PList = head;
		while(PList != NULL)
		{
			DPRINTF("\n  Student Number %d :" , count);
			DPRINTF("\n\t ID : %d" , PList->student.ID);
			DPRINTF("\n\t Name : %s" , PList->student.Name);
			DPRINTF("\n\t height : %0.2f\n" , PList->student.Hight);
			PList = PList->Next;
			count++;
		}
	}
}


void Delete_First_Student()
{
	SStudent* PCurrent;

	// Check if List is Empty
	if(head == NULL)
	{
		DPRINTF("NO Students in the List\n");
	}

	else
	{
		PCurrent = head;
		head = head->Next;
		free(PCurrent);
	}
}


void Delete_Last_Student()
{
	SStudent* PLast;
	SStudent* PPrev;

	if(head == NULL)
	{
		DPRINTF("NO Students in the List\n");
	}

	// if there is one node(Student) only
	else if(head->Next == NULL)
	{
		head = NULL;
	}

	// navigate until arrived the last node(student)
	else
	{
		PLast = head->Next;
		PPrev = head;

		while(PLast->Next != NULL)
		{
			PLast = PLast->Next;
			PPrev = PPrev->Next;
		}
		PPrev->Next = NULL;
		free(PLast);
	}
}


int Delete_ID_Num()
{
	// recive the specific ID
	unsigned int num;
	DPRINTF("\nEnter the ID will be deleted : ");
	scanf("%d" , &num);

	SStudent* PCurrent = head->Next;
	SStudent* PPrev = head;

	// if List is Empty
	if(head == NULL)
	{
		DPRINTF("NO Students in the List\n");
		return 0;
	}

	// if the First Student have the required ID
	else if((PPrev->student.ID) == num)
	{
		head = head->Next;
		free(PPrev);
		return 0;
	}

	// if the List not Empty and the First Student do not have
	// the required ID
	else
	{
		while(PCurrent!=NULL)
		{
			// if we found the required ID
			if((PCurrent->student.ID) == num)
			{
				// if the ID belongs to the Last Student
				if(PCurrent->Next == NULL)
				{
					PPrev->Next = NULL;
					free(PCurrent);
					return 0;
				}
				// if the ID is not the last ID
				else
				{
					PPrev->Next = PCurrent->Next;
					free(PCurrent);
					return 0;
				}
			}// if we do not found the required ID and not end the list
			else
			{
				PCurrent = PCurrent->Next;
				PPrev = PPrev->Next;
			}
		}
	}
	// if we do not found the required ID and end the list
	DPRINTF("This ID Not Founded \n");

}


int Count_List(SStudent *temp)
{
	/* Recursive Solution */
	if(temp == NULL)
	{
		return 0;
	}
	else
	{
		return(1+Count_List(temp->Next));
	}


	/* Iterative Solution */
	/*int count=0;
	SStudent* PCounter = head;

	while(PCounter != NULL)
	{
		count++;
		PCounter = PCounter->Next;
	}

	DPRINTF("Number of Students = %d" , count);*/
}


int Delete_All_Students()
{
	char ch;
	DPRINTF("\nare you sure to end the Program and Clear all Students : (y\\n)\n");
	scanf("%c" , &ch);
	// if you need to delete all students
	if(ch == 'y')
	{
		SStudent* PCurrent = head ;

		if(head == NULL)
		{
			DPRINTF("NO Students in the List\n");
			return 0;
		}
		while(PCurrent != NULL)
		{
			// define PTemp pointer here to defined every-time in the loop
			// from beginning to point on PCurrent pointer
			SStudent* PTemp = PCurrent;
			PCurrent =PCurrent->Next;
			free(PTemp);
		}
		head = NULL;
	}
	// if you need to continue
	else if(ch == 'n')
	{
		return 0;
	}
	// Invalid choice
	else
	{
		DPRINTF("\n!Invalid Choice...\n")
	}
}


int Add_student_in_Start()
{
	char text[40];
	// define a new student
	SStudent* PNewStudent;
	PNewStudent = (SStudent*)malloc(sizeof(SStudent));
	// Check if the Memory allocated or Not
	if(PNewStudent == NULL)
	{
		DPRINTF("Error! Memory Not Allocated\n");
		return 0;
	}
	else
	{
		// fill new record
		DPRINTF("\n Enter the Student ID: ");
		gets(text);
		PNewStudent->student.ID = atoi(text);

		DPRINTF("\n Enter Student Full Name : ");
		gets(text);
		strcpy(PNewStudent->student.Name , text);

		DPRINTF("\n Enter the Student height: ");
		gets(text);
		PNewStudent->student.Hight = atof(text);
		/// set the next pointer (new_student) null
		PNewStudent->Next = head;
		head = PNewStudent;
	}

}


int Print_Student_Nth_from_Beginnig()
{
	// if List is Empty
	if(head == NULL)
	{
		DPRINTF("NO Students in the List\n");
	}
	// if List Not Empty
	else
	{
		SStudent* PCurrent = head;
		unsigned int index , iterate=0 ;
		// receive Index from User
		DPRINTF("Enter the Index of Student form 0 to n to view : ");
		scanf("%d" , &index);
		// navigate until arrived to index
		while(PCurrent!=NULL)
		{
			if(index == iterate)
			{
				DPRINTF("\n\t ID : %d" , PCurrent->student.ID);
				DPRINTF("\n\t Name : %s" , PCurrent->student.Name);
				DPRINTF("\n\t height : %0.2f\n" , PCurrent->student.Hight);
				return 0;
			}
			else
			{
				PCurrent = PCurrent->Next;
				iterate++;
			}
		}
		// if the index is less than number of elements
		DPRINTF("This Index Not Founded");
	}
}


int Print_Student_Nth_from_End()
{
	unsigned int i=0;
	// if List is Empty
	if(head == NULL)
	{
		DPRINTF("NO Students in the List\n");
	}
	// if List is Not Empty
	else
	{
		SStudent* PCurrent = head;
		SStudent* PEnd = head;
		// receive Index from User
		unsigned int index ;
		DPRINTF("Enter the Index of Student to view : ");
		scanf("%d" , &index);
		// move reference pointer to n nodes from head
		for(i=0 ; i<index ; i++)
		{
			PEnd=PEnd->Next;
			// if the index is large the number of nodes
			if(PEnd == NULL)
			{
				DPRINTF("this index is Large than number of Students\n");
				return 0;
			}
		}

		// Navigate until arrived to the required index
		while(PEnd!=NULL)
		{
			PEnd = PEnd->Next;
			PCurrent = PCurrent->Next;
		}

		// print the data of the required student
		DPRINTF("\n\t ID : %d" , PCurrent->student.ID);
		DPRINTF("\n\t Name : %s" , PCurrent->student.Name);
		DPRINTF("\n\t height : %0.2f\n" , PCurrent->student.Hight);
		return 0;
	}
}

void Sorting()
{
	SStudent* Pi = head;
	SStudent* Pj = head;
	// make variable from the same data type will be changed
	struct SData temp;

	// Sorting Loop (small to large)
	for(Pi=head ; Pi!=NULL ; Pi=Pi->Next)
	{
		for(Pj=Pi->Next ; Pj!=NULL ; Pj=Pj->Next)
		{
			if(Pi->student.ID > Pj->student.ID)
			{
				temp = Pi->student;
				Pi->student = Pj->student;
				Pj->student = temp;
			}
		}
	}
}


void Middle_Student()
{
	SStudent* PReference = head;
	SStudent* PMiddle = head;
	// if List is Empty
	if(head == NULL)
	{
		DPRINTF("NO Students in the List\n");
	}
	// if List is Not Empty
	else
	{
		while((PReference != NULL) && (PReference->Next != NULL))
		{
			PReference = PReference->Next->Next;
			PMiddle = PMiddle->Next;
		}
		// print the data of the required student
		DPRINTF("the Middle Student informations :\n");
		DPRINTF("\n\t ID : %d" , PMiddle->student.ID);
		DPRINTF("\n\t Name : %s" , PMiddle->student.Name);
		DPRINTF("\n\t height : %0.2f\n" , PMiddle->student.Hight);
	}

}


void Reverse_List()
{
	SStudent* PCurrent = head;
	SStudent* PPrev = NULL;
	SStudent* PLevel = NULL;
	// if List is Empty
	if(head == NULL)
	{
		DPRINTF("NO Students in the List\n");
	}
	// if List is Not Empty
	else
	{
		// This Loop will Build a new List
		while(PCurrent != NULL)
		{
			PLevel = PCurrent->Next;
			PCurrent->Next = PPrev;
			PPrev = PCurrent;
			PCurrent = PLevel;
		}

		// Now make the main pointer pointing on the second List
		// to make it the main list */
		head = PPrev;
	}
}


int main()
{
	unsigned int choice=0 ;
	while(1)
	{
		DPRINTF("\n=================================== \n")
	    				/** display stack elements Each Order **/
	    				//DPRINTF("\nSTACK ELEMENTS :"); dispItems();

				DPRINTF("\n-------BASIC LINKED LIST OPERATIONS (press (0) for exit)-------");
		DPRINTF("\n(1) Add New Student");
		DPRINTF("\n(2) View all Students");
		DPRINTF("\n(3) Delete First Student from the List");
		DPRINTF("\n(4) Delete Last Student from the List");
		DPRINTF("\n(5) Delete the Student by ID Number");
		DPRINTF("\n(6) Number of Students in the List");
		DPRINTF("\n(7) Delete All Students");
		DPRINTF("\n(8) Add Student in Start");
		DPRINTF("\n(9) Print Nth Student form the Beginning");
		DPRINTF("\n(10) Print Nth Student form the End");
		DPRINTF("\n(11) Sort the Students by ID");
		DPRINTF("\n(12) Find the Middle Student");
		DPRINTF("\n(13) Reverse the Students List");
		DPRINTF("\nPLEASE ENTER YOUR CHOICE :: ");

		// get integer value only
		while(scanf("%d" , &choice)!= 1)
		{
			while(getchar() != '\n');
			DPRINTF("Enter integer Number :");
		}

		switch(choice)
		{
		case 0:
			Close_Program();
			break;

		case 1:
			Add_Student();
			break;

		case 2:
			View_All_Students();
			break;

		case 3:
			Delete_First_Student();
			break;

		case 4:
			Delete_Last_Student();
			break;

		case 5:
			Delete_ID_Num();
			break;

		case 6:
		{
			int c=0;
			c = Count_List(head);
			DPRINTF("Number of Elements = %d",c);
		}
		break;

		case 7:
			Delete_All_Students();
			break;

		case 8:
			Add_student_in_Start();
			break;

		case 9:
			Print_Student_Nth_from_Beginnig();
			break;

		case 10:
			Print_Student_Nth_from_End();
			break;

		case 11:
			Sorting();
			break;

		case 12:
			Middle_Student();
			break;

		case 13:
			Reverse_List();
			break;

		default:
			DPRINTF("!Invalid Choice ...");
			break;

		}
	}
	return 0;
}
