/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall 2016; Lab Section 04

* Programming Assignment: PA5

* Date: October 21st, 2016

* Description: This program creates a weekly diet and exercise plan for the user.

* History: 10/21/2016 Created the project. I believe I successfully made a lot of features it went downhill when i tried to
to implement it into main and there was a struggle trying to enter my object as a parameter ina function.
so I had to take an alternate route.

*******************************************************************************************/

#include "AppWrapper.h"

/*************************************************************
* Function: displayMenu()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: Works as the main menu of the application
* Input parameters: N/A
* Returns: option
* Preconditions: AppWrapper.h
* Postconditions: N/A
*************************************************************/
int displayMenu()
{
	int option = 0;

	while ((option > 7) || (option < 1))
	{
		cout << "1.   Import course list" << endl << endl;
		cout << "2.   Load master list" << endl << endl;
		cout << "3.   Store master list" << endl << endl;
		cout << "4.   Mark Absences" << endl << endl;
		cout << "5.   Edit Absences" << endl << endl;
		cout << "6.   Generate Report" << endl << endl;
		cout << "7.   Exit" << endl << endl;
		cout << "Please Select an option: ";
		cin >> option;
		system("cls");
	}

	return option;
}

/*************************************************************
* Function: report()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: Works as a submenu when you enter the report option
* Input parameters: N/A
* Returns: option
* Preconditions: AppWrapper.h
* Postconditions: N/A
*************************************************************/
int report()
{
	int option = 0;

	while ((option > 3) || (option < 1))
	{
		cout << "1.   Generate Report For all Students" << endl << endl;
		cout << "2.   Generate Report for students with absences" << endl << endl;
		cout << "3.   Generate Date Report" << endl << endl;
		cout << "Please Select an option: ";
		cin >> option;
		system("cls");
	}

	return option;
}

