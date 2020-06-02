#include "ListNode.h"

#pragma once

template<class NODETYPE>
class List
{
	public:
		//Constructor
		List();

		//Destructor
		~List();

		//Operations
		void insertAtFront(const NODETYPE &newData);
		void insertAtBack(const NODETYPE &newData);
		bool removeFromFront(NODETYPE &removedData);
		bool removeFromBack(NODETYPE &removedData);
		bool isEmpty();
		void print();


	private:
		ListNode<NODETYPE> *firstptr;
		ListNode<NODETYPE> *lastptr;

		ListNode<NODETYPE> *getNewNode(const NODETYPE &newData);
};

template<class NODETYPE>
List<NODETYPE>::List()
{
	firstptr = nullptr;
	lastptr = nullptr;
}

template<class NODETYPE>
List<NODETYPE>::~List()
{

}

template<class NODETYPE>
ListNode<NODETYPE>* List<NODETYPE>::getNewNode(const NODETYPE &newData)
{
	ListNode<NODETYPE> *ptr = new ListNode<NODETYPE>(newData);
	return ptr;
}

template<class NODETYPE>
void List<NODETYPE>::insertAtFront(const NODETYPE &newData)
{
	ListNode<NODETYPE> *newNode = getNewNode(newData);

	if (firstptr == nullptr)
	{
		firstptr = newNode;
		lastptr = newNode;
		lastptr->nextptr = nullptr;
	}
	else
	{
		newNode->nextptr = firstptr;
		firstptr = newNode;
	}
}

template<class NODETYPE>
void List<NODETYPE>::insertAtBack(const NODETYPE &newData)
{
	ListNode<NODETYPE> *newNode = getNewNode(newData);
	newNode->nextptr = nullptr;

	if (firstptr == nullptr)
	{
		firstptr = newNode;
		lastptr = newNode;
	}
	else
	{
		lastptr->nextptr = newNode;
		lastptr = newNode;
	}
}

template<class NODETYPE>
bool List<NODETYPE>::removeFromFront(NODETYPE &removedData)
{
	bool result = false;
	if (firstptr == lastptr && firstptr != nullptr)//If only 1 Node in list
	{
		removedData = firstptr->mData;
		delete firstptr;
		lastptr = nullptr;
		firstptr = nullptr;
		result = true;
	}
	else if (firstptr != nullptr)//If >1 Node in list
	{
		ListNode<NODETYPE> *temp = firstptr;
		removedData = firstptr->mData;
		firstptr = firstptr->nextptr;
		delete temp;
		result = true;
	}
	return result;
}

template<class NODETYPE>
bool List<NODETYPE>::removeFromBack(NODETYPE &removedData)
{
	bool result = false;

	if (firstptr == lastptr && firstptr != nullptr)//If only 1 Node in list
	{
		removedData = firstptr->mData;
		delete firstptr;
		lastptr = nullptr;
		firstptr = nullptr;
		result = true;
	}
	else if (firstptr != nullptr)//If >1 Node in list
	{
		ListNode<NODETYPE> *temp = firstptr;
		while (temp->nextptr != lastptr)
		{
			temp = temp->nextptr;
		}
		removedData = lastptr->mData;
		delete lastptr;
		temp->nextptr = nullptr;
		lastptr = temp;
		result = true;
	}
	return result;
}

template<class NODETYPE>
bool List<NODETYPE>::isEmpty()
{
	result = false;

	if (firstptr == nullptr)
	{
		result = true;
	}
	return result;
}

template<class NODETYPE>
void List<NODETYPE>::print()
{
	if (firstptr != nullptr)
	{
		ListNode<NODETYPE> *temp = firstptr;
		while (temp != nullptr)
		{
			cout << temp->mData << " -> ";
			temp = temp->nextptr;
		}
		cout << "nullptr" << endl;
	}
}


