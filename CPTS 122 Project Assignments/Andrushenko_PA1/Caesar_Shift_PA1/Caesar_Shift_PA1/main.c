/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall 2016; Lab Section 4

* Programming Assignment: #1

* Date: August September 4th, 2016

* Description: This program encrypts and decrypts strings, using the caesar shift cypher.

* Sources: The wikipedia site linked on PA1 for the caesar shift cypher was used to create the shift equations.

*******************************************************************************************/


#include "header.h"

int main(void)
{
	char string[7] = { 'h', 'u', 'n', 't', 'e', 'r' };
	printf("The string before any shifts: %s\n\n", string);
	
	int len = 0;

	len = strlen(string);

	//Enter shift values here
	int	shift_value = 3;

	upper_case(string, len);

	right_shift(string, len, shift_value);

	printf("The string after a right shift of %d: %s\n\n", shift_value, string);

	left_shift(string, len, shift_value);

	printf("The string after a left shift of %d: %s\n\n", shift_value, string);








	


	

	return 0;
}