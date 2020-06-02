/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall 2016; Lab Section 4

* Programming Assignment: #1

* Date: August September 4th, 2016

* Description: This program encrypts and decrypts strings, using the caesar shift cypher.

* Sources: The wikipedia site linked on PA1 for the caesar shift cypher was used to create the shift equations.

*******************************************************************************************/



#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void upper_case(char string[], int length);

void right_shift(char string[], int length, int shift);

void left_shift(char string[], int length, int shift);