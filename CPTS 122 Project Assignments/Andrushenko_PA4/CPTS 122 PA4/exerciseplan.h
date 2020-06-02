/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 121, Spring  2016; Lab Section 08

* Programming Assignment: PA4

* Date: February 26th, 2016

* Description: This program creates a weekly diet and exercise plan for the user.

* History: 10/08/2016 Created the DietPlan and ExercisePlan classes.
10/09/2016 Created the fitness functions and completed the program.

*******************************************************************************************/
#pragma once

#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;
using std::istream;
using std::ostream;
using std::string;

class ExercisePlan
{
public:
	ExercisePlan();

	//Constructors
	ExercisePlan(ExercisePlan &copy);

	//Destructors
	~ExercisePlan();

	//Overloaded Operators
	ExercisePlan & operator=(ExercisePlan &rhs);

	//Setters
	void setCalories(int newCalories);
	void setName(string newName);
	void setDate(string newDate);

	//Getters
	int getCalories();
	string getName();
	string getDate();


private:
	int mCalories;
	string mName;
	string mDate;
};

//Nonmember Overloaded Operators
ostream & operator<<(ostream &lhs, ExercisePlan &rhs);

istream & operator>>(istream &lhs, ExercisePlan &rhs);

ifstream & operator>>(ifstream &lhs, ExercisePlan &rhs);

ofstream & operator<<(ofstream &lhs, ExercisePlan &rhs);
