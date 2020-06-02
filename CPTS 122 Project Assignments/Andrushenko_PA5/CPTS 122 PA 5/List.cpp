/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall 2016; Lab Section 04

* Programming Assignment: PA5

* Date: October 21st, 2016

* Description: This program creates a weekly diet and exercise plan for the user.

* History: 10/21/2016 Created the project. I believe I successfully made a lot of features it went downhill when i tried to
to implement it into main and there was a struggle trying to enter my object as a parameter ina function.
so I had to take an alternate route.

*******************************************************************************************/

#include "List.h"

/*************************************************************
* Function: List()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: Constructor for the List
* Input parameters: N/A
* Returns: N/A
* Preconditions: List.h
* Postconditions: N/A
*************************************************************/
List:: List()
{
	mpHead = nullptr;
}

/*************************************************************
* Function: List()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: Destructor for the List
* Input parameters: N/A
* Returns: N/A
* Preconditions: List.h
* Postconditions: N/A
*************************************************************/
List::~List()
{

}

/*************************************************************
* Function: getHead()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: returns mpHead
* Input parameters: N/A
* Returns: mpHead
* Preconditions: List.h
* Postconditions: N/A
*************************************************************/
Node *& List::getHead()
{
	return mpHead;
}

/*************************************************************
* Function: setHead()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: makes mpHead equal to newHead
* Input parameters: Node * const newHead
* Returns: N/A
* Preconditions: List.h
* Postconditions: N/A
*************************************************************/
void List::setHead(Node * const newHead)
{
	mpHead = newHead;
}

/*************************************************************
* Function: insert()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: inserts data into a node
* Input parameters: Node *& pList, const int num, const int ID, const string &name, const string &email, const int units, const string &program, const string &level, const int missed, const string date[]
* Returns: N/A
* Preconditions: List.h
* Postconditions: N/A
*************************************************************/
void List::insert(Node *& pList, const int num, const int ID, const string &name, const string &email, const int units, const string &program, const string &level, const int missed, const string date[])
{
	if (pList == nullptr)
	{
		Node *pMem = nullptr;
		pMem = new Node(num, ID, name, email, units, program, level, missed, date);
		pList = pMem;
	}
	else if (pList != nullptr)
	{
		insert(pList->getNext(), num, ID, name, email, units, program, level, missed, date);
	}
	else
	{
		cout << "Error!" << endl;
	}
}

/*************************************************************
* Function: insert()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: inserts data based on the mpHead
* Input parameters: N/A
* Returns: N/A
* Preconditions: List.h
* Postconditions: N/A
*************************************************************/
void List::insert(const int num, const int ID, const string &name, const string &email, const int units, const string &program, const string &level, const int missed, const string date[])
{
	insert(this->mpHead, num, ID, name, email, units, program, level, missed, date);
}

/*************************************************************
* Function: printfile()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: prints the data of all the nodes into a file
* Input parameters: Node *& pList
* Returns: N/A
* Preconditions: List.h
* Postconditions: N/A
*************************************************************/
void List::printfile(Node *& pList)
{
	ofstream output;
	output.open("master.txt");
	
	while (pList != nullptr)
	{
		output << pList->getNum() << ',' << pList->getID() << ',' << pList->getName() << ',' << pList->getEmail() << ',' << pList->getUnits() << ',' << pList->getProgram() << ',' << pList->getLevel() << ',' << pList->getMissed() << endl;
		pList = pList->getNext();
	}
	output.close();

}

/*************************************************************
* Function: printfile()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: Sets the printfile function to the private data member mpHead
* Input parameters: N/A
* Returns: N/A
* Preconditions: List.h
* Postconditions: N/A
*************************************************************/
void List::printfile()
{
	printfile(this->mpHead);
}

/*************************************************************
* Function: mark()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: edits the number of missed days variable within each nodes
* Input parameters: Node *& pList
* Returns: N/A
* Preconditions: List.h
* Postconditions: N/A
*************************************************************/
void List::mark(Node *& pList)
{
	int marker = 0;
	int current = 0;
	while (pList != nullptr)
	{
		cout << "Was " << pList->getName() << " Absent today?" << endl << "1 = Yes" << endl << "0 = No" << endl;
		cin >> marker;
		current = pList->getMissed();
		current += marker;
		pList->setMissed(current);
		current = 0;
		marker = 0;
		pList = pList->getNext();

	}
}

/*************************************************************
* Function: mark()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: Sets the mark function to the private data member mpHead
* Input parameters: N/A
* Returns: N/A
* Preconditions: List.h
* Postconditions: N/A
*************************************************************/
void List::mark()
{
	mark(this->mpHead);
}

/*************************************************************
* Function: print()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: prints the data of all the nodes into the output stream
* Input parameters: Node *& pList
* Returns: N/A
* Preconditions: List.h
* Postconditions: N/A
*************************************************************/
void List::print(Node *& pList)
{
	while (pList != nullptr)
	{
		cout << pList->getNum() << ',' << pList->getID() << ',' << pList->getName() << ',' << pList->getEmail() << ',' << pList->getUnits() << ',' << pList->getProgram() << ',' << pList->getLevel() << ',' << pList->getMissed() << endl;
		pList = pList->getNext();
	}

}

/*************************************************************
* Function: print()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: Sets the print function to the private data member mpHead
* Input parameters: N/A
* Returns: N/A
* Preconditions: List.h
* Postconditions: N/A
*************************************************************/
void List::print()
{
	print(this->mpHead);
}

