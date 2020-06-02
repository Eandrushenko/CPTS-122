#include "header.h"

Node *makeNode(Data newData)
{
	Node *pMem = NULL;

	pMem = (Node*)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		pMem->pNext = NULL;
		pMem->info = newData;
	}
	return pMem;
}

void insertFront(Node** pList, Data newData)
{
	Node *pMem = makeNode(newData);

	if (pMem != NULL)
	{
		pMem->pNext = *pList;
		*pList = pMem;
	}

}

void printList(Node *pHead)
{
	while (pHead != NULL)
	{
		printf("%d, ", pHead->info.num);
		pHead = pHead->pNext;
	}
}

Node *mergeList(Node **pHead1, Node **pHead2)
{
	Node *pHead3 = NULL;
	Data newData;

	newData.num = (*pHead1)->info.num;

	insertFront(&pHead3, newData);
	return pHead3;
}

