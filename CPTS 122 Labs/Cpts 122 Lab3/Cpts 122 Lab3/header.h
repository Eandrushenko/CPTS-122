#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct practice
{
	int number;
	char word[10];
}Practice;

typedef struct node
{
	Practice data;
	struct node *pNext;
}Node;

Node *makeNode(Practice newData);

int insertFront(Node** pList, Practice newData);

int insertEnd(Node** pList, Practice newData);

void printList(Node *pList);