#include "header.h"

int main(void)
{
	Node *pHead = NULL;

	Practice test = { 4 , "four" }, test2 = { 3, "three" }, test3 = { 5, "five" };

	insertEnd(&pHead, test);

	insertEnd(&pHead, test2);

	insertFront(&pHead, test3);

	printList(pHead);


	return 0;
}