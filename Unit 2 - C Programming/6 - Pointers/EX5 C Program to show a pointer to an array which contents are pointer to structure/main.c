/**==================================================
--    Author     :   YOUSSEF ADEL YOUSSEF
--  Description  :   C Program to show a pointer to an array which 
                     contents are pointer to structure
==================================================**/

#include <stdio.h>

struct Employee
{
	char *emp_name;
	int emp_id;
}emp1={"Jhon",1001},emp2={"Alex",1002},emp3={"Taylor",1003};

int main()
{
	struct employee (*arr[]) = {&emp1 , &emp2 , &emp3};
	struct Employee (*(*pts)[3])=&arr;
	printf("Employee Name :%s\n" , (**(*pts+1)).emp_name);
	printf("Employee ID : %d\n" , (*(*pts+1))->emp_id);

	return 0;
}
