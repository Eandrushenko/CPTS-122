#include "header.h"

int main(void)
{
	Node *pHead1 = NULL, *pHead2 = NULL, *pHead3 = NULL;

	Data stuff1 = { 1 }, stuff2 = { 3 }, stuff3 = { 5 }, stuff4 = { 7 }, stuff5 = { 9 }, stuff6 = { 11 };

	insertFront(&pHead1, stuff6);
	insertFront(&pHead2, stuff5);
	insertFront(&pHead1, stuff4);
	insertFront(&pHead2, stuff3);
	insertFront(&pHead1, stuff2);
	insertFront(&pHead2, stuff1);

	printList(pHead1);
	printf("\n");
	printList(pHead2);
	printf("\n");

	pHead3 = mergeList(&pHead1, &pHead2);
	printList(pHead3);
	printf("\n");

	return 0;
}