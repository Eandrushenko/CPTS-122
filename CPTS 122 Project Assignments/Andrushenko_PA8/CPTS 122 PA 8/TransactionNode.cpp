/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall  2016; Lab Section 04

* Programming Assignment: PA8

* Date: November 17th, 2016

* Description: This program sorts purchased and sold items and determines trends in the purchasing and selling of those items.

* History: 11/17/2016 Created the Node, TransactionNode, and half the BST.
11/18/2016 Finished the BST, and created the DataAnalysis, finishing the project.

* references:
http://stackoverflow.com/questions/21109677/node-with-minimum-value-in-a-binary-search-tree

Used for finding the smallest node in a BST, applied to void BST::findSmallest();

*******************************************************************************************/


#include "TransactionNode.h"

/*************************************************************
* Function: TransactionNode()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Constructor for TransactionNode
* Input parameters: int newUnits, string newData
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created
* Postconditions: N/A
*************************************************************/
TransactionNode::TransactionNode(int newUnits, string newData) : Node(newData)
{
	mUnits = newUnits;
}

/*************************************************************
* Function: ~TransactionNode()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Destructor for TransactionNode
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created
* Postconditions: N/A
*************************************************************/
TransactionNode::~TransactionNode()
{

}

/*************************************************************
* Function: setUnits()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: setter for mUnits
* Input parameters: int newUnits
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created
* Postconditions: N/A
*************************************************************/
void TransactionNode::setUnits(int newUnits)
{
	mUnits = newUnits;
}

/*************************************************************
* Function: getUnits()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Getter for mUnits
* Input parameters: N/A
* Returns: mUnits
* Preconditions: Node object must be created, TransactionNode object must be created
* Postconditions: N/A
*************************************************************/
int TransactionNode::getUnits()
{
	return mUnits;
}

/*************************************************************
* Function: printData()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Displays mData
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created
* Postconditions: N/A
*************************************************************/
void TransactionNode::printData()
{
	cout << getData() << endl;
}
