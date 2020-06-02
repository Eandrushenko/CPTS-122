#include "header.h"

int main(void)
{
	Node *pHead = NULL;
	Contact test = { "Test" }, test2 = { "Apples" };
	int flag = 0;

	flag = insertorder(&pHead, test);
	printf("%d\n", flag);
	printf("%s\n", pHead->info.name);

	flag = insertorder(&pHead, test2);
	printf("%d\n", flag);
	printf("%s\n", pHead->info.name);

	return 0;
}