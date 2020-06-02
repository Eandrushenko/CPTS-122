#include <iostream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

#pragma once
template <class NODETYPE> class List;

template<class NODETYPE>
class ListNode
{
	friend class List<NODETYPE>;

	public:
		//Constructor
		ListNode(const NODETYPE &newData);

		//Getters
		NODETYPE getData();

	private:
		NODETYPE mData;
		ListNode<NODETYPE> *nextptr;
};

template<class NODETYPE>
ListNode<NODETYPE>::ListNode(const NODETYPE &newData)
{
	mData = newData;
}

template<class NODETYPE>
NODETYPE ListNode<NODETYPE>::getData()
{
	return mData;
}
