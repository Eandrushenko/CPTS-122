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

#include "dietplan.h"
#include "exerciseplan.h"

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

void runApp();

int displayMenu();

void loadDiet(DietPlan D1[], ifstream &input);

void loadExercise(ExercisePlan E1[], ifstream &input);

void storeDiet(DietPlan D1[], ofstream &output);

void storeExercise(ExercisePlan E1[], ofstream &output);

void displayDiet(DietPlan D1[]);

void displayExercise(ExercisePlan E1[]);

void editDiet(DietPlan D1[]);

void editExercise(ExercisePlan E1[]);

void exitApp(DietPlan D1[], ExercisePlan E1[], ofstream &output);
