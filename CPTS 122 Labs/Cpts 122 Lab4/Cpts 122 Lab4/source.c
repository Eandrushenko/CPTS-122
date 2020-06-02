#include "header.h"

Node *makeNode(Data newData)
{
	Node *pMem = (Node*)malloc(sizeof(Node));

	if (pMem != NULL)
	{
		pMem->item.pData = (char *)malloc(sizeof(char) * (strlen(newData.pData) + 1));
		if (pMem->item.pData != NULL)
		{
			strcpy(pMem->item.pData, newData.pData);
		}

		pMem->pNext = NULL;
	}

	return pMem;
}

int isEmpty(Queue *q)
{
	int flag = 0;
	if ((q->pHead == NULL) && (q->pTail == NULL))
	{
		flag = 1;
	}
	else
	{
		flag = 0;
	}
	return flag;

}

void printQueue(Queue q)
{
	Node *pCur = q.pHead;

	while (pCur != NULL)
	{
		printf("%s\n", pCur->item.pData);
		pCur = pCur->pNext;
	}
}

void dequeue(Queue *q)
{
	Node *pTemp = NULL;

	pTemp = q->pHead;

	if (q->pHead == q->pTail)
	{
		q->pHead = q->pTail = NULL;
	}
	else
	{
		q->pHead = q->pHead->pNext;
	}

	free(pTemp->item.pData);
	free(pTemp);

}

