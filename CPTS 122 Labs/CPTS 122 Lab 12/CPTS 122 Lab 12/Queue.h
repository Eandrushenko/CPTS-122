#include "List.h"

template <class NODETYPE>
class Queue : private List<NODETYPE>
{
	public:
		void enqueue(const NODETYPE &newData);
		bool dequeue(NODETYPE &removedData);

};

template<class NODETYPE>
void Queue<NODETYPE>::enqueue(const NODETYPE &newData)
{
	insertAtBack(newData);
}

template<class NODETYPE>
bool Queue<NODETYPE>::dequeue(NODETYPE &removedData)
{
	return removeFromFront(removedData);
}


#pragma once
