/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall 2016; Lab Section 4

* Programming Assignment: #1

* Date: August September 4th, 2016

* Description: This program encrypts and decrypts strings, using the caesar shift cypher.

* Sources: The wikipedia site linked on PA1 for the caesar shift cypher was used to create the shift equations.

*******************************************************************************************/


#include "header.h"

/*************************************************************
* Function: upper_case()
* Date Created: 09/04/2016
* Date Last Modified: 09/04/2016
* Description: This function makes each letter uppercase in a string.
* Input parameters: char string[], int length
* Returns: An array of strings capitalized.
* Preconditions: A string consisting of letters.
* Postconditions: N/A
*************************************************************/
void upper_case(char string[], int length)
{
	int i = 0;

	while (i < length)
	{
		if (string[i] <= 90)
		{
			i = i;
		}
		else if (string[i] >= 91)
		{
			string[i] = string[i] - 32;
		}
		i += 1;
	}

}


/*************************************************************
* Function: right_shift()
* Date Created: 09/05/2016
* Date Last Modified: 09/05/2016
* Description: This function encrypts a string by moving character values to the right by "X" amount.
* Input parameters: char string[], int length, int shift
* Returns: An encrypted string.
* Preconditions: A string with all letters capitalized.
* Postconditions: N/A
*************************************************************/
void right_shift(char string[], int length, int shift)
{
	int i = 0, x = 0;

	while (i < length)
	{
		x = (((string[i] - 65) + shift) % 26);
		string[i] = x + 65;
		i += 1;
	}
}


/*************************************************************
* Function: left_shift()
* Date Created: 09/05/2016
* Date Last Modified: 09/05/2016
* Description: This function decrypts a string by moving character values to the left by "X" amount.
* Input parameters: char string[], int length, int shift
* Returns: A Decrypted string.
* Preconditions: A string with all letters capitalized.
* Postconditions: N/A
*************************************************************/
void left_shift(char string[], int length, int shift)
{
	int i = 0, x = 0;

	while (i < length)
	{
		if ((shift % 26) == 0)
		{
			i = i;
		}
		else if (shift <= 25)
		{
			x = (((string[i] - 65) - shift) % 26);
			string[i] = x + 65;
		}
		else if (shift >= 26)
		{
			x = (((string[i] - 65) - shift) % 26) + 26;
			string[i] = x + 65;
		}
		i += 1;
	}
}