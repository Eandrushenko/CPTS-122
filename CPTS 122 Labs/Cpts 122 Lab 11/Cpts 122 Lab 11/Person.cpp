#include "TestPerson.h"

Person::Person(string newName, int newAge, char newGender, int newHeight)
{
	mName = newName;
	mAge = newAge;
	mGender = newGender;
	mHeight = newHeight;
}

Person::Person(Person &copy)
{
	mName = copy.mName;
	mAge = copy.mAge;
	mGender = copy.mGender;
	mHeight = copy.mHeight;
}

Person::~Person()
{

}

string Person::getName()
{
	return mName;
}

int Person::getAge()
{
	return mAge;
}

char Person::getGender()
{
	return mGender;
}

int Person::getHeight()
{
	return mHeight;
}

void Person::setName(string newName)
{
	mName = newName;
}

void Person::setAge(int newAge)
{
	mAge = newAge;
}

void Person::setGender(char newGender)
{
	mGender = newGender;
}

void Person::setHeight(int newHeight)
{
	mHeight = newHeight;
}

ostream & operator<<(ostream &lhs, Person &rhs)
{
	lhs << "Name: " << rhs.getName() << endl;
	lhs << "Age: " << rhs.getAge() << endl;
	lhs << "Gender: " << rhs.getGender() << endl;
	lhs << "Height: " << rhs.getHeight() << endl;
	return lhs;
}

istream & operator>>(istream &lhs, Person &rhs)
{
	string name;
	char gender;
	int age, height;

	cout << "Enter the person's name: ";
	cin >> name;
	rhs.setName(name);

	cout << "Enter the person's age: ";
	cin >> age;
	rhs.setAge(age);

	cout << "Enter the person's gender: ";
	cin >> gender;
	rhs.setGender(gender);

	cout << "Enter the person's height: ";
	cin >> height;
	rhs.setHeight(height);

	return lhs;
}

void TestPerson::testAll()
{
	string name = "Tom";
	int age = 5, height = 7;
	char gender = 'M';

	mName = name;
	mAge = age;
	mGender = gender;
	mHeight = height;

	if (name == getName())
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	if (age == getAge())
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	if (gender == getGender())
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
	if (height == getHeight())
	{
		cout << "Test Passed" << endl;
	}
	else
	{
		cout << "Test Failed" << endl;
	}
}