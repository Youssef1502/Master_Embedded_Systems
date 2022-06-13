/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   In This C Program, a Structure (student) in created which
                     Contains Name, roll and Marks as its data member. then, an
                     array of Structure of 10 elements is created. Then, data
                     (name , roll , marks) for 10 elements is asked to user and
                     stored in array of structure. Finally, the data Entered by
                     User is displayed

==================================================**/

#include<stdio.h>

struct Students
{
	int roll;
	char name[50];
	float marks;


} student[10] ;

int main()
{
	int i=0;
	printf("      Enter Information of Students\n");
	for(i=0 ; i<10 ; i++)
	{
		printf("\nEnter roll Number : ");
		fflush(stdout);		fflush(stdin);
		scanf("%d" , &student[i].roll);

		printf("Enter Name : ");
		fflush(stdout);		fflush(stdin);
		gets(student[i].name);

		printf("Enter Marks : ");
		fflush(stdout);		fflush(stdin);
		scanf("%f" , &student[i].marks);
	}

	printf("\n      Displaying Information of Students\n");
	for(i=0 ; i<10 ; i++)
	{
		printf("\nInformation for roll Number : %d\n" , student[i].roll);
		printf("Name : %s\n" , student[i].name);
		printf("Marks : %0.1f\n" , student[i].marks);
	}

	return 0;
}
