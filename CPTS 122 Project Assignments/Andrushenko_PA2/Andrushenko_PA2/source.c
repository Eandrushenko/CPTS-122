/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall 2016; Lab Section 4

* Programming Assignment: #2/3

* Date: August September 18th, 2016

* Description: This program moves records into nodes and edits them in various ways.

* Sources: Help from Hunter and Andy to get the strings into nodes.

*******************************************************************************************/



#include "header.h"

/*************************************************************
* Function: display()
* Date Created: 09/18/2016
* Date Last Modified: 09/23/2016
* Description: This function prompts the user what they would like to do
* Input parameters: N/A
* Returns: An integer
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
int display()
{
	int i = 0;
	printf("(1) load\n");
	printf("(2) store\n");
	printf("(3) display\n");
	printf("(4) insert\n");
	printf("(5) delete\n");
	printf("(6) edit\n");
	printf("(7) sort\n");
	printf("(8) rate\n");
	printf("(9) exit\n\n");
	printf("Choose an option: ");
	scanf("%d", &i);
	return i;

}


/*************************************************************
* Function: read_line()
* Date Created: 09/18/2016
* Date Last Modified: 09/18/2016
* Description: This function reads a line from a file
* Input parameters: FILE* infile, char line[]
* Returns: a string
* Preconditions: A file is opened for reading
* Postconditions: N/A
*************************************************************/
void read_line(FILE *infile, char line[])
{
	fgets(line, 200, infile);
}

/*************************************************************
* Function: get_line()
* Date Created: 09/18/2016
* Date Last Modified: 09/18/2016
* Description: This function breaks the line string into an array of strings
* Input parameters: char *line, char *muic[]
* Returns: an array of strings
* Preconditions: a string is needed
* Postconditions: N/A
*************************************************************/
void get_line(char *line, char *music[])
{
	int i = 0;
	char *token = NULL;

	token = strtok(line, ",");
	while (token != NULL)
	{
		music[i] = token;
		token = strtok(NULL, ",");
		i += 1;
	}

}

/*************************************************************
* Function: concat()
* Date Created: 09/18/2016
* Date Last Modified: 09/18/2016
* Description: This function concatonates the second string to the first string if it is first and last name and if shifts the rest of the string over one position
* Input parameters: char *music[]
* Returns: an array of strings
* Preconditions: an array of strings must have strings in it
* Postconditions: N/A
*************************************************************/
void concat(char *music[])
{
	char last[20];
	int i = 1;

	if (music[0][0] == '\"')
	{
		strcpy(last, music[0]);
		strcat(last, ",");
		strcat(last, music[1]);
		strcpy(music[0], last);
		while (i < 7)
		{
			music[i] = music[i + 1];
			i += 1;
		}
	}
		
}


/*************************************************************
* Function: makeRecord()
* Date Created: 09/18/2016
* Date Last Modified: 09/23/2016
* Description: This function remove the newline character from the last string and splits the time lengths into two strings and then adds all the data onto a Record struct
* Input parameters: char *music[]
* Returns: Record struct
* Preconditions: array must consist of strings
* Postconditions: N/A
*************************************************************/
Record makeRecord(char *music[])
{
	char split[20], m[20], s[20];
	char *token = NULL;

	strcpy(split, music[6]);
	token = strtok(split, "\n");
	strcpy(music[6], token);

	//minutes
	strcpy(split, music[4]);
	token = strtok(split, ":");
	strcpy(m, token);

	//seconds
	token = strtok(NULL, ":");
	strcpy(s, token);

	int minutes = 0, seconds = 0, plays = 0, rating = 0;

	minutes = atoi(m);
	seconds = atoi(s);
	plays = atoi(music[5]);
	rating = atoi(music[6]);

	Record info;
	strcpy(info.artist, music[0]);
	strcpy(info.album_title, music[1]);
	strcpy(info.song_title, music[2]);
	strcpy(info.genre, music[3]);
	info.song_length.minutes = minutes;
	info.song_length.seconds = seconds;
	info.plays = plays;
	info.rating = rating;

	return info;

}

/*************************************************************
* Function: makeNode()
* Date Created: 09/23/2016
* Date Last Modified: 09/23/2016
* Description: This function allocates memory for data from a Record struct
* Input parameters: Record newData
* Returns: A Node
* Preconditions: A Record
* Postconditions: N/A
*************************************************************/
Node* makeNode(Record newData)
{
	Node *pMem = NULL;

	pMem = (Node*)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		pMem->pNext = NULL;
		pMem->data = newData;
	}
	return pMem;
}

/*************************************************************
* Function: counter()
* Date Created: 09/23/2016
* Date Last Modified: 09/23/2016
* Description: This function reads the firt line of a file and returns it as an integer
* Input parameters: char line[]
* Returns: an integer
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
int counter(char line[])
{
	int count = 0;
	char split[5];
	char *token = NULL;
	strcpy(split, line);
	token = strtok(split, "\n");
	strcpy(split, token);
	count = atoi(split);
	return count;
}


/*************************************************************
* Function: insertFront()
* Date Created: 09/23/2016
* Date Last Modified: 09/23/2016
* Description: This function prompts the user what they would like to do
* Input parameters: Node** pList, Record newData
* Returns: an integer
* Preconditions: A node exits and the memory allocated is sufficient to make a node
* Postconditions: N/A
*************************************************************/
int insertFront(Node** pList, Record newData)
{
	Node *pMem = makeNode(newData);
	int flag = 0;

	if (pMem != NULL)
	{
		flag = 1;
		pMem->pNext = *pList;
		*pList = pMem;
	}
	return flag;
}

/*************************************************************
* Function: store_count()
* Date Created: 09/23/2016
* Date Last Modified: 09/23/2016
* Description: This function counts how many nodes are in a linked list
* Input parameters: Node *pList
* Returns: An integer
* Preconditions: A Node has a pointer to the next node
* Postconditions: N/A
*************************************************************/
int store_count(Node *pList)
{
	Node *pCur = pList;
	int i = 0;
	while (pCur != NULL)
	{
		pCur = pCur->pNext;
		i += 1;
	}

	return i;

}

/*************************************************************
* Function: store_print()
* Date Created: 09/23/2016
* Date Last Modified: 09/23/2016
* Description: This function prints all the nodes in a linked list into a file
* Input parameters: Node *pList
* Returns: N/A
* Preconditions: There is a linked list
* Postconditions: N/A
*************************************************************/
void store_print(Node *pList)
{
	Node *pCur = pList;

	FILE *outfile = NULL;

	int i = 0;
	i = store_count(pList);

	outfile = fopen("music.csv", "w");

	fprintf(outfile, "%d\n", i);

	while (pCur != NULL)
	{
		fprintf(outfile, "%s,%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.album_title, pCur->data.song_title, pCur->data.genre, pCur->data.song_length.minutes, pCur->data.song_length.seconds, pCur->data.plays, pCur->data.rating);
		pCur = pCur->pNext;
	}

	fclose(outfile);

}


/*************************************************************
* Function: sortArtist()
* Date Created: 09/23/2016
* Date Last Modified: 09/23/2016
* Description: This function sorts nodes based on a data type within a struct
* Input parameters: Node *pHead
* Returns: N/A
* Preconditions: The Node is a linked list
* Postconditions: N/A
*************************************************************/
int sortArtist(Node *pHead)
{
	int i = 0;
	Node *pCur = NULL;
	char temp[20] = { "\0" };
	int temp2 = 0;
			
	pCur = pHead;
			while (i < 10)
			{
				while (pCur->pNext != NULL)
				{
					if (pCur->data.rating <= pCur->pNext->data.rating)
					{
						i = i;
					}
					else
					{
						//artist (character)
						strcpy(temp, pCur->pNext->data.artist);
						strcpy(pCur->pNext->data.artist, pCur->data.artist);
						strcpy(pCur->data.artist, temp);

						//album (character)
						strcpy(temp, pCur->pNext->data.album_title);
						strcpy(pCur->pNext->data.album_title, pCur->data.album_title);
						strcpy(pCur->data.album_title, temp);

						//song (character)
						strcpy(temp, pCur->pNext->data.song_title);
						strcpy(pCur->pNext->data.song_title, pCur->data.song_title);
						strcpy(pCur->data.song_title, temp);

						//genre (character)
						strcpy(temp, pCur->pNext->data.genre);
						strcpy(pCur->pNext->data.genre, pCur->data.genre);
						strcpy(pCur->data.genre, temp);

						//minutes (integer)
						temp2 = pCur->pNext->data.song_length.minutes;
						pCur->pNext->data.song_length.minutes = pCur->data.song_length.minutes;
						pCur->data.song_length.minutes = temp2;

						//seconds (integer)
						temp2 = pCur->pNext->data.song_length.seconds;
						pCur->pNext->data.song_length.seconds = pCur->data.song_length.seconds;
						pCur->data.song_length.seconds = temp2;

						//plays (integer)
						temp2 = pCur->pNext->data.plays;
						pCur->pNext->data.plays = pCur->data.plays;
						pCur->data.plays = temp2;

						//rating (integer)
						temp2 = pCur->pNext->data.rating;
						pCur->pNext->data.rating = pCur->data.rating;
						pCur->data.rating = temp2;
					}
					pCur = pCur->pNext;
				}
				pCur = pHead;
				i += 1;
			}

}


/*************************************************************
* Function: display_print()
* Date Created: 09/23/2016
* Date Last Modified: 09/23/2016
* Description: This function prints all the nodes in a singly linked list to the user interface
* Input parameters: Node *pList
* Returns: N/A
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
void display_print(Node *pList)
{
	Node *pCur = pList;

	while (pCur != NULL)
	{
		printf("%s,%s,%s,%s,%d:%d,%d,%d\n", pCur->data.artist, pCur->data.album_title, pCur->data.song_title, pCur->data.genre, pCur->data.song_length.minutes, pCur->data.song_length.seconds, pCur->data.plays, pCur->data.rating);
		pCur = pCur->pNext;
	}


}

/*************************************************************
* Function: insertRecord()
* Date Created: 09/23/2016
* Date Last Modified: 09/23/2016
* Description: This function fills a Record struct with information given by the user
* Input parameters: N/A
* Returns: Record
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
Record insertRecord()
{
	char artist[50] = { "\0" }, album[50] = { "\0" }, song[50] = { "\0" }, genre[50] = { "\0" };
	int minute = 0, second = 0, plays = 0, rating = 0;
	printf("Please no spaces when entering information\n");
	printf("Enter the artist's name: ");
	scanf("%s", &artist);
	printf("Enter the album name: ");
	scanf("%s", &album);
	printf("Enter the song name: ");
	scanf("%s", &song);
	printf("Enter the genre: ");
	scanf("%s", &genre);
	printf("Enter the song length in minutes: ");
	scanf("%d", &minute);
	printf("Enter the remaining time of the song in seconds: ");
	scanf("%d", &second);
	printf("Enter the play count: ");
	scanf("%d", &plays);
	printf("Enter the rating of the song: ");
	scanf("%d", &rating);


	Record info;
	strcpy(info.artist, artist);
	strcpy(info.album_title, album);
	strcpy(info.song_title, song);
	strcpy(info.genre, genre);
	info.song_length.minutes = minute;
	info.song_length.seconds = second;
	info.plays = plays;
	info.rating = rating;

	return info;
}

/*************************************************************
* Function: removeNode()
* Date Created: 09/23/2016
* Date Last Modified: 09/23/2016
* Description: This function removes a Node based on what the user enters
* Input parameters: Node *pList
* Returns: N/A
* Preconditions: N/A
* Postconditions: N/A
*************************************************************/
void removeNode(Node *pList)
{
	char song[50] = { "\0" };
	printf("Please enter the name of the song you with to remove: ");
	scanf("%s", &song);

	Node *pCur = NULL,*pMem = NULL;
	pMem = pList;
	pCur = pList;
	pCur = pCur->pNext;

	if (pList == NULL)
	{
		printf("There are no records to delete.\n");
	}
	else
	{
		while ((strcmp(song, pCur->data.song_title) != 0) || (pCur == NULL))
		{
			pCur = pCur->pNext;
			pMem = pMem->pNext;
		}
		if (strcmp(song, pCur->data.song_title) == 0)
		{
			pMem->pNext = pCur->pNext;
			free(pCur->data.album_title);
			free(pCur->data.artist);
			free(pCur->data.genre);
			free(pCur->data.plays);
			free(pCur->data.rating);
			free(pCur->data.song_length.minutes);
			free(pCur->data.song_length.seconds);
			free(pCur->data.song_title);
		}
		else
		{
			printf("A song with that name can not be found\n");
		}
	}
}



