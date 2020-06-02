#include "List.h"
#pragma once

template<class NODETYPE>
class Stack : private List<NODETYPE>
{
	public:
		void push(const NODETYPE &newData);
		void pop(NODETYPE &removedData);
		bool isFull();
		bool isEmpty();
};

template<class NODETYPE>
void Stack<NODETYPE>::push(const NODETYPE &newData)
{
	insertAtFront(newData);
}

template<class NODETYPE>
void Stack<NODETYPE>::pop(NODETYPE &removedData)
{
	removeFromFront(removedData);
}

template<class NODETYPE>
bool Stack<NODETYPE>::isFull()
{
	return (!(List<NODETYPE>::isEmpty()));
}

template<class NODETYPE>
bool Stack<NODETYPE>::isEmpty()
{
	return (List<NODETYPE>::isEmpty());
}
