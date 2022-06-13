/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   Write a C Program to Create Students Management System
                     by Queue
==================================================**/

#ifndef APIS_H_
#define APIS_H_

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define DPRINTF(...)     {fflush(stdout); \
		fflush(stdin); \
		printf(__VA_ARGS__);\
		fflush(stdout); \
		fflush(stdin);}


#define MAX 5

// Structure for Student Informations
struct SData
{
	char First_Name[20];
	char Last_Name[20];
	unsigned int ID;
	unsigned int Courses[5];
	float GPA;
};

// Structure for Queue Node
typedef struct s_student
{
	struct SData student;
	struct s_student* Next;
}SStudent;


// Enumeration States
typedef enum
{
	DONE,
	ERROR
}State_e;

// Define the APIs of the Program
void Exit();
State_e Add_Student_Manual();
State_e Add_Student_from_File();
State_e Find_Student_by_ID();
State_e Find_Student_by_First_Name();
State_e Find_Student_by_Course_ID();
void Total_Number();
State_e Update_Details();
State_e Delete_Student_by_ID();
State_e Print_All_Students();


#endif /* APIS_H_ */
