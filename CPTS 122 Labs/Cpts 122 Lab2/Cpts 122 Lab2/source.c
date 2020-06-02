#include "header.h"

Node* makenode(Contact new_contact)
{
	Node*pMem = NULL;

	pMem = (Node*)malloc(sizeof(Node));
	
	if (pMem != NULL)
	{
		pMem->pNext = NULL;
		pMem->info = new_contact;
	}
	return pMem;
}

int insertorder(Node **pHead, Contact newcontact)
{
	int flag = 0;
	Node *pCur = NULL, *pPrev = NULL, *pMem = NULL;
	pMem = (Node*)makenode(newcontact);

	if (pMem != NULL)
	{
		flag = 1;
		if (*pHead == NULL)
		{
			*pHead = pMem;
		}
		else
		{
			pCur = *pHead;
			while ((pCur != NULL) && (strcmp(pCur->info.name, newcontact.name) < 0))
			{
				pPrev = pCur;
				pCur = pCur-> pNext;
			}
			if (pCur == *pHead)
			{
				pMem->pNext = pCur;
				*pHead = pMem;
			}
			else
			{
				pMem->pNext = pCur;
				pPrev->pNext = pMem;
			}
		}
	}
	return flag;
}
