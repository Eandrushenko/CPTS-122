#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
	int num;

}Data;

typedef struct node
{
	Data info;
	struct node *pNext;
}Node;

Node *makeNode(Data newData);

void insertFront(Node** pList, Data newData);

void printList(Node *pHead);

Node *mergeList(Node **pHead1, Node **pHead2);
