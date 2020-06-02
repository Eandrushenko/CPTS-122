/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall 2016; Lab Section 4

* Programming Assignment: #1

* Date: August September 3rd, 2016

* Description: This program sorts 5 strings into alphabetical order lower case only in an array.

* Sources: Andy's example code helped me set up the parameter *string[].

*******************************************************************************************/


#include "header.h"


/*************************************************************
* Function: string_sort()
* Date Created: 09/03/2016
* Date Last Modified: 09/03/2016
* Description: This function sorts the array of strings into alphabetical order
* Input parameters: char *string[], int length
* Returns: An array of strings in alphabetical order
* Preconditions: An array of strings consisting of only lower case letter or upper case letters only.
* Postconditions: N/A
*************************************************************/
void string_sort(char *string[], int length)
{
	char *temp = NULL;
	int i = 0, j = 0, k = 0;

	while (j < 5)
	{
		while (i < 4)
		{
			if ((string[i][0] < string[i + 1][0]) || (string[i] == string[i + 1]))
			{
				i = i;
			}
			else if (string[i][0] > string[i + 1][0])
			{
				temp = string[i];
				string[i] = string[i + 1];
				string[i + 1] = temp;
			}
			else if (string[i][0] == string[i+1][0])
			{
				while (string[i][k] == string[i + 1][k])
				{
					k += 1;
				}
				if (string[i][k] < string[i + 1][k])
				{
					i = i;
				}
				else if (string[i][k] > string[i + 1][k])
				{
					temp = string[i];
					string[i] = string[i + 1];
					string[i + 1] = temp;
				}
			}
			i += 1;
		}
		i = 0;
		k = 0;
		j += 1;
	}
}