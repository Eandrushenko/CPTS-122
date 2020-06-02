#pragma once

#include "TestPerson.h"

typedef struct course
{
	string course_name = " ";
	int course_credits = 0;
	char course_grade = 0;

}Course;

class Student : public Person
{
	public:
		//Constructor
		Student(string newName = " ", int newAge = 0, char newGender = ' ', int newHeight = 0,  int newTaken = 0, int newCredits = 0, Course *newCourse = nullptr);

		//Destructor
		~Student();

		//Getters
		int getTaken();
		int getCredits();
		Course getCourse(int index);

		//Setters
		void setTaken(int newTaken);
		void setCredits(int newCredits);
		void setCourse(Course *newCourse, int index);


	private:
		Course mCourse[5];
		int mTaken;
		int mCredits;
};

ostream & operator<<(ostream &lhs, Student &rhs);


