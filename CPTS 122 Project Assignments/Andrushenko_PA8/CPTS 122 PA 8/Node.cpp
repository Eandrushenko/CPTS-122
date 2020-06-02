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

used for finding the smallest node in a BST, applied to void BST::findSmallest();

*******************************************************************************************/


#include "Node.h"


/*************************************************************
* Function: Node()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Constructor for the Node class
* Input parameters: string newData
* Returns: N/A
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
Node::Node(string newData)
{
	mData = newData;
	mpRight = nullptr;
	mpLeft = nullptr;
}

/*************************************************************
* Function: ~Node()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Destructor for the Node class
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
Node::~Node()
{

}

/*************************************************************
* Function: setData()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Setter for mData
* Input parameters: string newData
* Returns: N/A
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
void Node::setData(string newData)
{
	mData = newData;
}

/*************************************************************
* Function: setRight()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Setter for the Right pointer
* Input parameters: Node *newRight
* Returns: N/A
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
void Node::setRight(Node *newRight)
{
	mpRight = newRight;
}

/*************************************************************
* Function: setLeft()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Setter for the left pointer
* Input parameters: Node *newLeft
* Returns: N/A
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
void Node::setLeft(Node *newLeft)
{
	mpLeft = newLeft;
}

/*************************************************************
* Function: getData()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Getter for mData
* Input parameters: N/A
* Returns: mData
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
string Node::getData()
{
	return mData;
}

/*************************************************************
* Function: getRight()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Getter for the right pointer
* Input parameters: N/A
* Returns: mpRight
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
Node *& Node::getRight()
{
	return mpRight;
}

/*************************************************************
* Function: getLeft()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Getter for the left pointer
* Input parameters: N/A
* Returns: mpLeft
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
Node *& Node::getLeft()
{
	return mpLeft;
}
