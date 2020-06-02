/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall 2016; Lab Section 4

* Programming Assignment: #1

* Date: August September 4th, 2016

* Description: This program prints out a maze and figures out if it can be solved.

* Sources: Last years' lab was of great use to solve the problem for this assignment.

*******************************************************************************************/


#include "header.h"


/*************************************************************
* Function: doMaze()
* Date Created: 09/04/2016
* Date Last Modified: 09/04/2016
* Description: This function goes through all possible areas of the maze and returns numbers if it is solvable or not.
* Input parameters: char maze[][7], int col, int row
* Returns: An int 0 or 1 based on if it can get to the end.
* Preconditions: An array that is 7x7 and appropriate row_size and col_size according to the size.
* Postconditions: N/A
*************************************************************/
int doMaze(char maze[][7], int col, int row)
{
	int value = 0;
	maze[row][col] = '~';
	if (col == 6 && row == 6)
	{
		return 1;
	}
	if (value != 1 && row > 0 && maze[row - 1][col] == '-')//Up
	{
		value = doMaze(maze, col, row - 1);
	}
	if (value != 1 && row < 6 && maze[row + 1][col] == '-')//Down
	{
		value = doMaze(maze, col, row + 1);
	}
	if (value != 1 && col < 6 && maze[row][col + 1] == '-')//Right
	{
		value = doMaze(maze, col + 1, row);
	}
	if (value != 1 && col > 0 && maze[row][col - 1] == '-')//Left
	{
		value = doMaze(maze, col - 1, row);
	}
	return value;
}


/*************************************************************
* Function: print_maze()
* Date Created: 09/04/2016
* Date Last Modified: 09/04/2016
* Description: This function prints the array to look like a maze.
* Input parameters: char maze[][7], int row_size, int col_size
* Returns: A print out of the array.
* Preconditions: An array that is 7x7 and appropriate row_size and col_size according to the size.
* Postconditions: N/A
*************************************************************/
void print_maze(char maze[][7], int row_size, int col_size)
{
	int row_index = 0, col_index = 0;

	for (row_index = 0; row_index < row_size; row_index++)
	{
		for (col_index = 0; col_index < col_size; col_index++)
		{
			printf(" %c ", maze[row_index][col_index]);
		}
		putchar('\n');
	}
}