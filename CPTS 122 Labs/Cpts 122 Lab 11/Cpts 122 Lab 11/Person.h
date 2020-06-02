#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ostream;
using std::istream;

class Person
{
	public:
		//Constructor
		Person(string newName = " ", int newAge = 0, char newGender = ' ', int newHeight = 0);

		//Copy Constructor
		Person(Person &copy);

		//Destructor
		~Person();

		//Getters
		string getName();
		int getAge();
		char getGender();
		int getHeight();

		//Setters
		void setName(string newName);
		void setAge(int newAge);
		void setGender(char newGender);
		void setHeight(int newHeight);

	protected:
		string mName;
		int mAge;
		char mGender;
		int mHeight;
};

//Nonmember Functions
ostream & operator<<(ostream &lhs, Person &rhs);
istream & operator>>(istream &lhs, Person &rhs);
