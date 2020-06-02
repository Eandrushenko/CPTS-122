#include "Student.h"

int main(void)
{
	Course classes[5];

	//Fill the struct
	classes[0].course_name = "Cpts 223";
	classes[0].course_grade = 'B';
	classes[0].course_credits = 3;

	classes[1].course_name = "Cpts 260";
	classes[1].course_grade = 'B';
	classes[1].course_credits = 3;

	classes[2].course_name = "Math 273";
	classes[2].course_grade = 'B';
	classes[2].course_credits = 2;

	classes[3].course_name = "Math 220";
	classes[3].course_grade = 'A';
	classes[3].course_credits = 2;

	classes[4].course_name = "Stats 360";
	classes[4].course_grade = 'A';
	classes[4].course_credits = 3;

	Student s1("Elijah", 19, 'M', 6, 45, 13, classes);

	cout << s1;

	return 0;
}