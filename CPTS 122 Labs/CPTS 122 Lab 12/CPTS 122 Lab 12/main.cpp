#include "Stack.h"
#include "Queue.h"

int main(void)
{
	Queue<int> q;
	int check = 0;

	q.enqueue(5);
	q.enqueue(10);
	q.enqueue(15);

	q.dequeue(check);
	cout << check << endl;

	q.dequeue(check);
	cout << check << endl;

	q.dequeue(check);
	cout << check << endl;

	q.dequeue(check);
	cout << check << endl;


	return 0;
}

