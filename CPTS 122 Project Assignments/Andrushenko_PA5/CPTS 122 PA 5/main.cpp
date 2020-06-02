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

int main(void)
{
	ifstream input;
	ofstream output;
	List students;

	char i[100];
	int j = 0;

	int num;
	int ID;
	string name;
	string email;
	int units;
	string program;
	string level;
	int missed = 0;
	string date[10] = { "", "", "", "", "", "", "", "", "", "" };

	int option = 0;

	while (option != 7)
	{
		option = displayMenu();
		
		if (option == 1)
		{
			input.open("classList.csv");
			cout << "1.   Import course list" << endl << endl;

			while (j < 10)
			{

				input.getline(i, 100, ',');
				num = atoi(i);
				input.getline(i, 100, ',');
				ID = atoi(i);
				input.getline(i, 100, ',');
				name = i;
				input.getline(i, 100, ',');
				name = name + ',' + i;
				input.getline(i, 100, ',');
				email = i;
				input.getline(i, 100, ',');
				units = atoi(i);
				input.getline(i, 100, ',');
				program = i;
				input.getline(i, 100, '\n');
				level = i;
				students.insert(num, ID, name, email, units, program, level, missed, date);
				j += 1;
			}
			input.close();
			system("pause");
			system("cls");
		}
		if (option == 2)
		{
			input.open("master.txt");
			cout << "2.   Load master list" << endl << endl;

			while (j < 10)
			{

				input.getline(i, 100, ',');
				num = atoi(i);
				input.getline(i, 100, ',');
				ID = atoi(i);
				input.getline(i, 100, ',');
				name = i;
				input.getline(i, 100, ',');
				name = name + ',' + i;
				input.getline(i, 100, ',');
				email = i;
				input.getline(i, 100, ',');
				units = atoi(i);
				input.getline(i, 100, ',');
				program = i;
				input.getline(i, 100, '\n');
				level = i;
				input.getline(i, 100, '\n');
				missed = atoi(i);
				students.insert(num, ID, name, email, units, program, level, missed, date);
				j += 1;
			}
			input.close();
			system("pause");
			system("cls");
		}
		if (option == 3)
		{
			cout << "3.   Store master list" << endl << endl;
			students.printfile();
			system("pause");
			system("cls");
		}
		if (option == 4)
		{
			cout << "4.   Mark Absences" << endl << endl;
			students.mark();
			system("pause");
			system("cls");
		}
		if (option == 5)
		{
			cout << "5.   Edit Absences" << endl << endl;
			system("pause");
			system("cls");
			cout << "This feature is unavailable right now" << endl << endl;
			system("pause");
			system("cls");
		}
		if (option == 6)
		{
			cout << "6.   Generate Report" << endl << endl;
			system("pause");
			system("cls");
			int option2;
			option2 = report();
			if (option2 == 1)
			{
				students.print();
				system("pause");
				system("cls");
			}
			else if (option == 2)
			{
				students.print();
				system("pause");
				system("cls");
			}
			else if (option == 3)
			{
				students.print();
				system("pause");
				system("cls");
			}
		}

	}

	return 0;
}