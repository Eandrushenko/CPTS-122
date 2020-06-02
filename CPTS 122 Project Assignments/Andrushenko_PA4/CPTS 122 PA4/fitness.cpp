/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 121, Spring  2016; Lab Section 08

* Programming Assignment: PA4

* Date: February 26th, 2016

* Description: This program creates a weekly diet and exercise plan for the user.

* History: 10/08/2016 Created the DietPlan and ExercisePlan classes.
10/09/2016 Created the fitness functions and completed the program.

*******************************************************************************************/
#include "fitness.h"

/*************************************************************
* Function: runApp()
* Date Created: 10/09/2016
* Date Last Modified: 10/09/2016
* Description: Connects all the functions together and ultimately runs the program
* Input parameters: N/A
* Returns: N/A
* Preconditions: ExercisePlan and DietPlan classes
* Postconditions: N/A
*************************************************************/
void runApp(void)
{
	DietPlan DP[7];
	ExercisePlan EP[7];
	ofstream output;
	ifstream input;
	int i = 0;
	while (i != 9)
	{
		i = displayMenu();
		if (i == 1)
		{
			loadDiet(DP, input);
		}
		else if (i == 2)
		{
			loadExercise(EP, input);
		}
		else if (i == 3)
		{
			storeDiet(DP, output);
		}
		else if (i == 4)
		{
			storeExercise(EP, output);
		}
		else if (i == 5)
		{
			displayDiet(DP);
		}
		else if (i == 6)
		{
			displayExercise(EP);
		}
		else if (i == 7)
		{
			editDiet(DP);
		}
		else if (i == 8)
		{
			editExercise(EP);
		}
		else if (i == 9)
		{
			exitApp(DP, EP, output);
		}
		else
		{
			cout << "ERROR" << endl;
		}

	}
}

/*************************************************************
* Function: displayMenu()
* Date Created: 10/09/2016
* Date Last Modified: 10/09/2016
* Description: Prints the menu to the stream and returns an integer based on the menu choice
* Input parameters: N/A
* Returns: int option
* Preconditions: ExercisePlan and DietPlan classes
* Postconditions: N/A
*************************************************************/
int displayMenu()
{
	int option = 0;

	while ((option > 9) || (option < 1))
	{
		cout << "1.   Load weekly diet plan from file." << endl << endl;
		cout << "2.   Load weekly exercise plan from file." << endl << endl;
		cout << "3.   Store weekly diet plan to file." << endl << endl;
		cout << "4.   Store weekly exercise plan to file." << endl << endl;
		cout << "5.   Display weekly diet plan to screen." << endl << endl;
		cout << "6.   Display weekly exercise plan to screen." << endl << endl;
		cout << "7.   Edit daily diet plan." << endl << endl;
		cout << "8.   Edit daily exercise plan." << endl << endl;
		cout << "9.   Exit." << endl << endl;
		cout << "Please Select an option: ";
		cin >> option;
		system("cls");
	}

	return option;

}

/*************************************************************
* Function: loadDiet()
* Date Created: 10/09/2016
* Date Last Modified: 10/09/2016
* Description: Reads information from a text file and puts it into the DietPlan array
* Input parameters: DietPlan D1[], ifstream &input
* Returns: N/A
* Preconditions: ExercisePlan and DietPlan classes
* Postconditions: N/A
*************************************************************/
void loadDiet(DietPlan D1[], ifstream &input)
{
	input.open("dietplan.txt");
	cout << "1.   Load weekly diet plan to screen." << endl << endl;

	int i = 0;

	while (i < 7)
	{
		input >> D1[i];
		i += 1;
	}
	input.close();
	system("pause");
	system("cls");
}

/*************************************************************
* Function: loadExercise()
* Date Created: 10/09/2016
* Date Last Modified: 10/09/2016
* Description: Reads information from a text file and puts it into the ExercisePlan array
* Input parameters: ExercisePlan E1[], ifstream &input
* Returns: N/A
* Preconditions: ExercisePlan and DietPlan classes
* Postconditions: N/A
*************************************************************/
void loadExercise(ExercisePlan E1[], ifstream &input)
{
	input.open("exerciseplan.txt");
	cout << "2.   Load weekly exercise plan to screen." << endl << endl;

	int i = 0;

	while (i < 7)
	{
		input >> E1[i];
		i += 1;
	}
	input.close();
	system("pause");
	system("cls");
}

/*************************************************************
* Function: storeDiet()
* Date Created: 10/09/2016
* Date Last Modified: 10/09/2016
* Description: Prints the DietPlan to a text file
* Input parameters: DietPlan D1[], ofstream &output
* Returns: N/A
* Preconditions: ExercisePlan and DietPlan classes
* Postconditions: N/A
*************************************************************/
void storeDiet(DietPlan D1[], ofstream &output)
{
	output.open("dietplan.txt");
	cout << "3.   Store weekly diet plan to screen." << endl << endl;

	int i = 0;

	while (i < 7)
	{
		output << D1[i];
		i += 1;
	}
	output.close();
	system("pause");
	system("cls");
}

/*************************************************************
* Function: storeExercise()
* Date Created: 10/09/2016
* Date Last Modified: 10/09/2016
* Description: Prints the ExercisePlan to a text file
* Input parameters: ExercisePlan E1[], ofstream &output
* Returns: N/A
* Preconditions: ExercisePlan and DietPlan classes
* Postconditions: N/A
*************************************************************/
void storeExercise(ExercisePlan E1[], ofstream &output)
{
	output.open("exerciseplan.txt");
	cout << "4.   Store weekly exercise plan to screen." << endl << endl;

	int i = 0;

	while (i < 7)
	{
		output << E1[i];
		i += 1;
	}
	output.close();
	system("pause");
	system("cls");
}

/*************************************************************
* Function: displayDiet()
* Date Created: 10/09/2016
* Date Last Modified: 10/09/2016
* Description: prints the DietPlan array to the stream
* Input parameters: DietPlan D1[]
* Returns: N/A
* Preconditions: ExercisePlan and DietPlan classes
* Postconditions: N/A
*************************************************************/
void displayDiet(DietPlan D1[])
{
	cout << "5.   Display weekly diet plan to screen." << endl << endl;
	
	int i = 0;

	while (i < 7)
	{
		cout << D1[i];
		i += 1;
	}
	system("pause");
	system("cls");
}

/*************************************************************
* Function: displayExercise()
* Date Created: 10/09/2016
* Date Last Modified: 10/09/2016
* Description: prints the ExercisePlan array to the stream
* Input parameters: ExercisePlan E1[]
* Returns: N/A
* Preconditions: ExercisePlan and DietPlan classes
* Postconditions: N/A
*************************************************************/
void displayExercise(ExercisePlan E1[])
{
	cout << "6.   Display weekly exercise plan to screen." << endl << endl;

	int i = 0;

	while (i < 7)
	{
		cout << E1[i];
		i += 1;
	}
	system("pause");
	system("cls");
}

/*************************************************************
* Function: editDiet()
* Date Created: 10/09/2016
* Date Last Modified: 10/09/2016
* Description: Allows the user to modify a DietPlan object in an array of DietPlans
* Input parameters: DietPlan D1[]
* Returns: N/A
* Preconditions: ExercisePlan and DietPlan classes
* Postconditions: N/A
*************************************************************/
void editDiet(DietPlan D1[])
{
	cout << "7.   Edit daily diet plan." << endl << endl;

	int i = 0;
	while ((i > 7) || (i < 1))
	{
		cout << "Please select a day to edit (1-7): ";
		cin >> i;
		system("cls");
	}
	i -= 1;
	cin >> D1[i];
	system("pause");
	system("cls");
}

/*************************************************************
* Function: editExercise()
* Date Created: 10/09/2016
* Date Last Modified: 10/09/2016
* Description: Allows the user to modify an ExercisePlan object in an array of ExercisePlans
* Input parameters: ExercisePlan E1[]
* Returns: N/A
* Preconditions: ExercisePlan and DietPlan classes
* Postconditions: N/A
*************************************************************/
void editExercise(ExercisePlan E1[])
{
	cout << "8.   Edit daily exercise plan." << endl << endl;

	int i = 0;
	while ((i > 7) || (i < 1))
	{
		cout << "Please select a day to edit (1-7): ";
		cin >> i;
		system("cls");
	}
	i -= 1;
	cin >> E1[i];
	system("pause");
	system("cls");
}

/*************************************************************
* Function: exitApp()
* Date Created: 10/09/2016
* Date Last Modified: 10/09/2016
* Description: prints Dietplan and Exerciseplan to their respective files.
* Input parameters: Dietplan D1[], ExercisePlan E1[], ofstream &output
* Returns: N/A
* Preconditions: ExercisePlan and DietPlan classes
* Postconditions: N/A
*************************************************************/
void exitApp(DietPlan D1[], ExercisePlan E1[], ofstream &output)
{
	cout << "9.   Exit" << endl << endl;

	//store DietPlan
	output.open("dietplan.txt");
	int i = 0;
	while (i < 7)
	{
		output << D1[i];
		i += 1;
	}
	output.close();

	//store ExercisePlan
	output.open("exerciseplan.txt");
	i = 0;
	while (i < 7)
	{
		output << E1[i];
		i += 1;
	}
	output.close();
	system("pause");
	system("cls");
	i = 0;
}