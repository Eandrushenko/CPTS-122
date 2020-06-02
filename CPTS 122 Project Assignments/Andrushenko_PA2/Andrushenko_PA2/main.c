/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall 2016; Lab Section 4

* Programming Assignment: #2/3

* Date: August September 18th, 2016

* Description: This program moves records into nodes and edits them in various ways.

* Sources: Help from Hunter and Andy to get the strings into nodes.

*******************************************************************************************/




#include "header.h"

int main(void)
{
	Node *pHead = NULL;

	FILE *infile = NULL;

	Record song = { '\0' };

	char line[100] = { '\0' }, line2[100] = { '\0' };
	char *music[10];
	int num_record = 0, i = 0;

	int option = 0, result = 0;

	infile = fopen("music.csv", "r");

	while (result != 9)
	{
		option = display();

		if (option == 1)
		{
			result = option;
		}
		else if (option == 2)
		{
			result = option;
		}
		else if (option == 3)
		{
			result = option;
		}
		else if (option == 4)
		{
			result = option;
		}
		else if (option == 5)
		{
			result = option;
		}
		else if (option == 6)
		{
			result = option;
		}
		else if (option == 7)
		{
			result = option;
		}
		else if (option == 8)
		{
			result = option;
		}
		else if (option == 9)
		{
			result = option;
			printf("Exit\n");
		}
		else if (option > 9)
		{
			result = 9;
			printf("An Error Occurred\n");
		}

		if (result == 1)
		{
			//obtain how many records there are in the file
			read_line(infile, line);
			num_record = counter(line);

			//Populate the Record Struct
			while (i < num_record)
			{
				read_line(infile, line);
				get_line(line, music);
				concat(music);
				song = makeRecord(music);
				insertFront(&pHead, song);
				i += 1;
			}
		}

		else if (result == 2 || result == 9)
		{
			store_print(pHead);
		}
		else if (result == 3)
		{
			display_print(pHead);
		}
		else if (result == 4)
		{
			song = insertRecord();
			insertFront(&pHead, song);
		}
		else if (result == 5)
		{
			removeNode(pHead);
		}
		else if (result == 7)
		{
			sortArtist(pHead);
		}
		system("pause");
		system("cls");
	}
	fclose(infile);

	return 0;
}