/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall  2016; Lab Section 04

* Programming Assignment: PA6

* Date: October 26th, 2016

* Description: This program converts english writing to morse code.

* History: 10/26/2016 Created the BSTNodes and the fundamental BST.
10/28/2016 Created the functions that apply to the PA, completed the PA

*******************************************************************************************/


#include "BSTNode.h"

/*************************************************************
* Function: Node()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: Constructor for the BSTNode
* Input parameters: string newMorse, char newCharacter
* Returns: N/A
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
Node::Node(string newMorse, char newCharacter)
{
	mMorse = newMorse;
	mCharacter = newCharacter;
	mpRight = nullptr;
	mpLeft = nullptr;
}

/*************************************************************
* Function: ~Node()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: Destructor for the BSTNode
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
Node::~Node()
{

}

/*************************************************************
* Function: getMorse()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: getter for string morse code
* Input parameters: N/A
* Returns: mMorse
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
string Node::getMorse() const
{
	return mMorse;
}

/*************************************************************
* Function: getCharacter()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: getter for the character 
* Input parameters: N/A
* Returns: mCharacter
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
char Node::getCharacter() const
{
	return mCharacter;
}

/*************************************************************
* Function: getRight()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: getter for the right pointer
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
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: getter for the left pointer
* Input parameters: N/A
* Returns: mpLeft
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
Node *& Node::getLeft()
{
	return mpLeft;
}

/*************************************************************
* Function: setMorse()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: setter for string morse code
* Input parameters: const string newMorse
* Returns: N/A
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
void Node::setMorse(const string newMorse)
{
	mMorse = newMorse;
}

/*************************************************************
* Function: setCharacter()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: setter for character
* Input parameters: const char newCharacter
* Returns: N/A
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
void Node::setCharacter(const char newCharacter)
{
	mCharacter = newCharacter;
}

/*************************************************************
* Function: setRight()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: setter for the right pointer
* Input parameters: Node * const newRight
* Returns: N/A
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
void Node::setRight(Node * const newRight)
{
	mpRight = newRight;
}

/*************************************************************
* Function: setLeft()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: setter for the left pointer
* Input parameters: Node * const newLeft
* Returns: N/A
* Preconditions: Node object must be created
* Postconditions: N/A
*************************************************************/
void Node::setLeft(Node * const newLeft)
{
	mpLeft = newLeft;
}
