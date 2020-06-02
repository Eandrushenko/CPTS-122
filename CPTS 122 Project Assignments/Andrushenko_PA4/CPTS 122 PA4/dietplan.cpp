/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 121, Spring  2016; Lab Section 08

* Programming Assignment: PA4

* Date: February 26th, 2016

* Description: This program creates a weekly diet and exercise plan for the user.

* History: 10/08/2016 Created the DietPlan and ExercisePlan classes.
10/09/2016 Created the fitness functions and completed the program.

*******************************************************************************************/
#include "dietplan.h"

/*************************************************************
* Function: DietPlan()
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: A constructor to initalize the DietPlan object
* Input parameters: N/A
* Returns: N/A
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
DietPlan::DietPlan()
{
	mCalories = 0;
	mDate = "mm/dd/yyyy";
	mName = "Plan Name";
}

/*************************************************************
* Function: setCalories(int newCalories)
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: Sets mCalories to the value of newCalories
* Input parameters: int newCalories
* Returns: N/A
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
void DietPlan::setCalories(int newCalories)
{
	mCalories = newCalories;
}

/*************************************************************
* Function: setDate(string newDate)
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: Sets mDate to the value of newDate
* Input parameters: string newDate
* Returns: N/A
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
void DietPlan::setDate(string newDate)
{
	mDate = newDate;
}

/*************************************************************
* Function: setName(string newName)
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: Sets mName to the value of newName
* Input parameters: string newName
* Returns: N/A
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
void DietPlan::setName(string newName)
{
	mName = newName;
}

/*************************************************************
* Function: getCalories();
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: returns the value of mCalories
* Input parameters: N/A
* Returns: mCalories
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
int DietPlan::getCalories()
{
	return mCalories;
}

/*************************************************************
* Function: getDate();
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: returns the value of mDate
* Input parameters: N/A
* Returns: mDate
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
string DietPlan::getDate()
{
	return mDate;
}

/*************************************************************
* Function: getName();
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: returns the value of mName
* Input parameters: N/A
* Returns: mName
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
string DietPlan::getName()
{
	return mName;
}

/*************************************************************
* Function: DietPlan(DietPlan &copy);
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: A copy constructor for the DietPlan object
* Input parameters: DietPlan &copy
* Returns: N/A
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
DietPlan::DietPlan(DietPlan &copy)
{
	setCalories(copy.getCalories());
	setDate(copy.getDate());
	setName(copy.getName());
}

/*************************************************************
* Function: &operator=(DietPlan &rhs);
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: overloaded operator for the = symbol, makes two DietPlans the same
* Input parameters: DietPlan &rhs
* Returns: *this
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
DietPlan & DietPlan::operator=(DietPlan &rhs)
{
	if (this != &rhs)
	{
		mCalories = rhs.getCalories();
		mDate = rhs.getDate();
		mName = rhs.getName();
	}
	return *this;
}

/*************************************************************
* Function: &operator<<(ostream &lhs, DietPlan &rhs);
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: overloaded operator for the << symbol, prints DietPlans to the output stream
* Input parameters: ostream &lhs, DietPlan &rhs
* Returns: lhs
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
ostream & operator<<(ostream &lhs, DietPlan &rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}

/*************************************************************
* Function: &operator>>(istream &lhs, DietPlan &rhs);
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: overloaded operator for the >> symbol, scans DietPlans from the output stream
* Input parameters: istream &lhs, Dietplan &rhs
* Returns: lhs
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
istream & operator>>(istream &lhs, DietPlan &rhs)
{
	char string0[100];
	int num;
	lhs.getline(string0, 100);
	cout << "Enter the Plan Name: ";
	lhs.getline(string0, 100);
	rhs.setName(string0);
	cout << "Enter the Goal Calories: ";
	lhs >> num;
	rhs.setCalories(num);
	cout << "Enter the Date: ";
	lhs >> string0;
	rhs.setDate(string0);
	lhs.getline(string0, 100);
	return lhs;
}

/*************************************************************
* Function: ~DietPlan()
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: A destructor for the DietPlan class
* Input parameters: N/A
* Returns: N/A
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
DietPlan::~DietPlan()
{

}

/*************************************************************
* Function: &operator>>(ifstream &lhs, DietPlan &rhs);
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: overloaded operator for the >> symbol, scans DietPlans from a file
* Input parameters: ifstream &lhs, Dietplan &rhs
* Returns: lhs
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
ifstream & operator>>(ifstream &lhs, DietPlan &rhs)
{
	char string0[100];
	int num;
	char discard[100];
	lhs.getline(string0, 100);
	rhs.setName(string0);
	lhs >> num;
	rhs.setCalories(num);
	lhs >> string0;
	rhs.setDate(string0);
	lhs.getline(discard, 100);
	lhs.getline(discard, 100);
	return lhs;
}

/*************************************************************
* Function: &operator<<(ostream &lhs, DietPlan &rhs);
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: overloaded operator for the >> symbol, prints DietPlans to a file
* Input parameters: ostream &lhs, Dietplan &rhs
* Returns: lhs
* Preconditions: DietPlan.h
* Postconditions: N/A
*************************************************************/
ofstream & operator<<(ofstream &lhs, DietPlan &rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}


