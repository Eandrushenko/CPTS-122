#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct data
{
	char *pData;
}Data;

typedef struct Node
{
	Data item;
	struct node *pNext;
}Node;

typedef struct queuenode
{
	Node *pHead;
	Node *pTail;
}Queue;

Node *makeNode(Data newData);

int isEmpty(Queue *q);

int enqueue(Queue *q, Data newData);

void printQueue(Queue q);

void dequeue(Queue *q);

