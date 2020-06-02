#include "Student.h"

Student::Student(string newName, int newAge, char newGender, int newHeight, int newTaken,
	int newCredits, Course *newCourse) : Person(newName, newAge, newGender, newHeight)
{
	mTaken = newTaken;
	mCredits = newCredits;

	int i = 0;
	if (newCourse != nullptr)
	{
		while (i < 5)
		{
			mCourse[i] = newCourse[i];
			i += 1;
		}
	}
}

Student::~Student()
{

}

int Student::getTaken()
{
	return mTaken;
}

int Student::getCredits()
{
	return mCredits;
}

Course Student::getCourse(int index)
{
	return mCourse[index];
}

void Student::setTaken(int newTaken)
{
	mTaken = newTaken;
}

void Student::setCredits(int newCredits)
{
	mCredits = newCredits;
}

void Student::setCourse(Course *newCourse, int index)
{
	mCourse[index] = newCourse[index];
}

ostream & operator<<(ostream &lhs, Student &rhs)
{
	lhs << "Student's Name: " << rhs.getName() << endl;
	lhs << "Student's Age: " << rhs.getAge() << endl;
	lhs << "Student's Gender: " << rhs.getGender() << endl;
	lhs << "Student's Height: " << rhs.getHeight() << endl;
	lhs << "Number of Student's Credits: " << rhs.getCredits() << endl;
	lhs << "Number of Student's Credits already taken: " << rhs.getTaken() << endl << endl;
	lhs << "Students Course:" << endl;
	
	int index = 0;

	while (index < 5)
	{
		lhs << "Class #" << (index + 1) << endl;
		lhs << "Class name: " << rhs.getCourse(index).course_name << endl;
		lhs << "Class grade: " << rhs.getCourse(index).course_grade << endl;
		lhs << "Class credits: " << rhs.getCourse(index).course_credits << endl;
		index += 1;
	}
	return lhs;

}



