#include "header.h"

Node *makeNode(Practice newData)
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

int insertFront(Node** pList, Practice newData)
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

int insertEnd(Node** pList, Practice newData)
{
	Node *pMem = makeNode(newData), *pCur = *pList;
	int flag = 0;

	if (pMem != NULL)
	{
		flag = 1;
		// Two cases:

		if (*pList == NULL)// 1: ListEmpty
		{
			pMem->pNext = NULL;
			*pList = pMem;
		}
		else// 2: List Not Empty
		{
			while (pCur->pNext != NULL)
			{
				pCur = pCur->pNext;

			}
			pCur->pNext = pMem;
		}
	}
	return flag;
}

void printList(Node *pList)
{
	Node *pCur = pList;
	while (pCur != NULL)
	{
		printf("(%d, %s) -> ", pCur->data.number, pCur->data.word);
		pCur = pCur->pNext;
	}
	printf("NULL\n");
}
