/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 121, Spring  2016; Lab Section 08

* Programming Assignment: PA4

* Date: February 26th, 2016

* Description: This program creates a weekly diet and exercise plan for the user.

* History: 10/08/2016 Created the DietPlan and ExercisePlan classes.
10/09/2016 Created the fitness functions and completed the program.

*******************************************************************************************/
#include "exerciseplan.h"


/*************************************************************
* Function: ExercisePlan()
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: Constructor for the ExercisePlan class
* Input parameters: N/A
* Returns: N/A
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
ExercisePlan::ExercisePlan()
{
	mCalories = 0;
	mDate = "mm/dd/yyyy";
	mName = "Plan Name";
}

/*************************************************************
* Function: setCalories()
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: sets mCalories to newCalories
* Input parameters: int newCalories
* Returns: N/A
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
void ExercisePlan::setCalories(int newCalories)
{
	mCalories = newCalories;
}

/*************************************************************
* Function: setDate()
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: sets mDate to newDate
* Input parameters: string newDate
* Returns: N/A
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
void ExercisePlan::setDate(string newDate)
{
	mDate = newDate;
}

/*************************************************************
* Function: setName()
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: sets mName to newName
* Input parameters: string newName
* Returns: N/A
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
void ExercisePlan::setName(string newName)
{
	mName = newName;
}

/*************************************************************
* Function: getCalories()
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: returns mCalories
* Input parameters: N/A
* Returns: mCalories
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
int ExercisePlan::getCalories()
{
	return mCalories;
}

/*************************************************************
* Function: getDate()
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: returns mDate
* Input parameters: N/A
* Returns: N/A
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
string ExercisePlan::getDate()
{
	return mDate;
}

/*************************************************************
* Function: getName()
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: return mName
* Input parameters: N/A
* Returns: mName
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
string ExercisePlan::getName()
{
	return mName;
}

/*************************************************************
* Function: ExercisePlan()
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: The copy constructor for the ExercisePlan class
* Input parameters: ExercisePlan &copy
* Returns: N/A
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
ExercisePlan::ExercisePlan(ExercisePlan &copy)
{
	setCalories(copy.getCalories());
	setDate(copy.getDate());
	setName(copy.getName());
}

/*************************************************************
* Function: & operator=()
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: Sets an ExercisePlan object to be equivalent to another ExercisePlan object
* Input parameters: ExercisePlan
* Returns: *this
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
ExercisePlan & ExercisePlan::operator=(ExercisePlan &rhs)
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
* Function: &operator<<(ostream &lhs, ExercisePlan &rhs);
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: overloaded operator for the << symbol, prints ExercisePlans to stream
* Input parameters: ostream &lhs, ExercisePlan &rhs
* Returns: lhs
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
ostream & operator<<(ostream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}

/*************************************************************
* Function: &operator>>(ofstream &lhs, ExercisePlan &rhs);
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: overloaded operator for the >> symbol, reads ExercisePlans from a file stream
* Input parameters: istream &lhs, ExercisePlan &rhs
* Returns: lhs
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
istream & operator>>(istream &lhs, ExercisePlan &rhs)
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
* Function: ~ExercisePlan()
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: A destructor for the ExercisePlan class
* Input parameters: N/A
* Returns: N/A
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
ExercisePlan::~ExercisePlan()
{

}

/*************************************************************
* Function: &operator>>(ifstream &lhs, ExercisePlan &rhs);
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: overloaded operator for the >> symbol, scans ExercisePlans from a file
* Input parameters: ifstream &lhs, ExercisePlan &rhs
* Returns: lhs
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
ifstream & operator>>(ifstream &lhs, ExercisePlan &rhs)
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
* Function: &operator>>(ofstream &lhs, ExercisePlan &rhs);
* Date Created: 10/08/2016
* Date Last Modified: 10/08/2016
* Description: overloaded operator for the << symbol, prints ExercisePlans to a file
* Input parameters: ofstream &lhs, ExercisePlan &rhs
* Returns: lhs
* Preconditions: ExercisePlan.h
* Postconditions: N/A
*************************************************************/
ofstream & operator<<(ofstream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getName() << endl;
	lhs << rhs.getCalories() << endl;
	lhs << rhs.getDate() << endl << endl;
	return lhs;
}
