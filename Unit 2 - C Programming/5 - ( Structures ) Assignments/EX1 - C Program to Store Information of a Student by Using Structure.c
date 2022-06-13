/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to Store Information [name , roll , marks]
                     of a Student by Using Structure
==================================================**/

#include<stdio.h>

struct Student
{
	char name[50];
	int roll;
	float marks;
}GS_student;

int main()
{
	printf("Enter Information of Students :\n");
	printf("Enter Name : ");
	fflush(stdout); 	fflush(stdin);
	gets(GS_student.name);
	printf("Enter roll Number : ");
	fflush(stdout); 	fflush(stdin);
	scanf("%d" , &GS_student.roll);
	printf("Enter marks Number : ");
	fflush(stdout); 	fflush(stdin);
	scanf("%f" , &GS_student.marks);
	printf("\nDisplay Information : \n");
	printf("Name : %s\n" , GS_student.name);
	printf("roll : %d\n" , GS_student.roll );
	printf("marks : %f\n" , GS_student.marks );
	return 0;
}
