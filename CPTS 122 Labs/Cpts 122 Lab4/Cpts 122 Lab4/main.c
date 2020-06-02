#include "header.h"

int main(void)
{
	Queue q = { NULL, NULL };
	Data character1 = { "number1" }, character2 = { "number2" }, character3 = { "number3" };

	//enqueue(&q, character1);
	//enqueue(&q, character2);
	//enqueue(&q, character3);
	//enqueue(&q, character1);
	//enqueue(&q, character3);

	//printQueue(q);

	//printf("\n\n");

	dequeue(&q);

	printQueue(q);



	return 0;
}