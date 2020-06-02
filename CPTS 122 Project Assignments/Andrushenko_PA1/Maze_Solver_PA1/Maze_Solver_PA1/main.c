/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall 2016; Lab Section 4

* Programming Assignment: #1

* Date: August September 4th, 2016

* Description: This program prints out a maze and figures out if it can be solved.

* Sources: Last years' lab was of great use to solve the problem for this assignment.

*******************************************************************************************/



#include "header.h"

int main(void)
{
	int val2 = 0;

	char maze[][7] = { 
	{ 'X', '-', '-', '-', '-', '-', 'X' },
	{ '-', '-', 'X', 'X', 'X', 'X', 'X' },
	{ 'X', '-', '-', '-', '-', 'X', '-' },
	{ 'X', '-', 'X', '-', 'X', 'X', 'X' },
	{ 'X', '-', 'X', 'X', '-', 'X', '-' },
	{ 'X', '-', '-', '-', '-', '-', '-' },
	{ 'X', 'X', 'X', 'X', 'X', 'X', '-' },
	{ 'X', 'X', 'X', 'X', 'X', 'X', '-' },
	};

	val2 = doMaze(maze, 0, 1);

	print_maze(maze, 7, 7);

	if (val2 == 0)
	{
		printf("The maze can not be completed.\n");
	}
	else
	{
		printf("The maze can be completed.\n");
	}




	return 0;
}