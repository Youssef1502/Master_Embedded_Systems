/**==================================================
--    Author    :   YOUSSEF ADEL YOUSSEF
-- Description  :   C Program to find area of a Circle
==================================================**/

#include <stdio.h>
#define PI 3.14159

double areaCirlce (float radius)
{
	return (PI * radius * radius);
}

int main()
{
	float radius ;

	printf ("Enter the radius of the circle: ");
	fflush (stdin);	fflush (stdout);
	scanf ("%f", &radius);

	printf ("The Area of the circle is: %.2lf", areaCirlce (radius));

	return 0;
}