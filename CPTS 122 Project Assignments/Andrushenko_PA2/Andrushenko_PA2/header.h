/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall 2016; Lab Section 4

* Programming Assignment: #2/3

* Date: August September 18th, 2016

* Description: This program moves records into nodes and edits them in various ways.

* Sources: Help from Hunter and Andy to get the strings into nodes.

*******************************************************************************************/



#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct duration
{
	int minutes;
	int seconds;
}Duration;


typedef struct record
{
	char artist[100];
	char album_title[100];
	char song_title[100];
	char genre[100];
	Duration song_length;
	int plays;
	int rating;

}Record;

typedef struct node
{
	Record data;
	struct node *pNext;

}Node;


//Functions
void read_line(FILE *infile, char line[]);

void get_line(char *line, char *music[]);

void concat(char *music[]);

Record makeRecord(char *music[]);

Node* makeNode(Record newData);

int counter(char line[]);

int insertFront(Node** pList, Record newData);

int store_count(Node *pList);

void store_print(Node *pList);

int display();

int sortArtist(Node *pHead);

void display_print(Node *pList);

Record insertRecord();

void removeNode(Node *pList);






