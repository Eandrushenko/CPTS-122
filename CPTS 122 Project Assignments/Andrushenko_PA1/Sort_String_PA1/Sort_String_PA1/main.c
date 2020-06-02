/*******************************************************************************************

* Programmer: Elijah Andrushenko                                                                      

* Class: CptS 122, Fall 2016; Lab Section 4                                             

* Programming Assignment: #1                                                    

* Date: August September 3rd, 2016                                                                          

* Description: This program sorts 5 strings into alphabetical order lower case only in an array.  

* Sources: Andy's example code helped me set up the parameter *string[].

*******************************************************************************************/



#include "header.h"

int main(void)
{
	char *string[5] = { "racecat", "racecar", "likes", "my", "code" };

	printf("The array before the sort:\n%s %s %s %s %s\n\n", string[0], string[1], string[2], string[3], string[4]);

	string_sort(string, 5);

	printf("The array after the sort:\n%s %s %s %s %s\n\n", string[0], string[1], string[2], string[3], string[4]);

}