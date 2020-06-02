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


#include "BST.h"
/*************************************************************
* Function: BST()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Constructor for BST
* Input parameters: N/A
* Returns: mUnits
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
BST::BST()
{
	mpRoot = nullptr;
}

/*************************************************************
* Function: ~BST()
* Date Created: 11/17/2016
* Date Last Modified: 11/18/2016
* Description: Destructor for BST, calls a postorderraversal function that deletes nodes
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
BST::~BST()
{
	destroy(this->mpRoot);
}

/*************************************************************
* Function: setRoot()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Setter for the pointer to the Root
* Input parameters: Node* newRoot
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::setRoot(Node* newRoot)
{
	mpRoot = newRoot;
}

/*************************************************************
* Function: getRoot()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Getter for the pointer to the Root
* Input parameters: N/A
* Returns: mpRoot
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
Node* BST::getRoot()
{
	return mpRoot;
}

/*************************************************************
* Function: insert()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Inserts Nodes into the BST, private function
* Input parameters: Node *& pTree, int newUnits, string newData
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::insert(Node *& pTree, int newUnits, string newData)
{
	if (pTree == nullptr)
	{
		TransactionNode *pMem = nullptr;
		pMem = new TransactionNode(newUnits, newData);
		pTree = pMem;
	}
	else if (newUnits > (dynamic_cast<TransactionNode*>(pTree))->getUnits())
	{
		insert(pTree->getRight(), newUnits, newData);
	}
	else if (newUnits < (dynamic_cast<TransactionNode*>(pTree))->getUnits())
	{
		insert(pTree->getLeft(), newUnits, newData);
	}
	else
	{
		cout << "Duplication Error" << endl;
	}
}

/*************************************************************
* Function: insert()
* Date Created: 11/17/2016
* Date Last Modified: 11/17/2016
* Description: Inserts Nodes into the BST, public function
* Input parameters: int newUnits, string newData
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::insert(int newUnits, string newData)
{
	insert(this->mpRoot, int (newUnits), string (newData));
}

/*************************************************************
* Function: inorderTraversal()
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
* Description: Prints the Nodes in order from smallest to largest based on the number of units, private function
* Input parameters: Node *& pTree
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::inorderTraversal(Node *& pTree)
{
	if (pTree != nullptr)
	{
		inorderTraversal(pTree->getLeft());

		cout << "Data: ";
		pTree->printData();
		cout << "Units: " << (dynamic_cast<TransactionNode*>(pTree))->getUnits() << endl;

		inorderTraversal(pTree->getRight());
	}
}

/*************************************************************
* Function: inorderTraversal()
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
* Description: Prints the Nodes in order from smallest to largest based on the number of units, public function
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::inorderTraversal()
{
	inorderTraversal(this->mpRoot);
}

/*************************************************************
* Function: findSmallest()
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
* Description: Sets a TransactionNode to the smallest node in the BST
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created
* Postconditions: N/A
* Source Code: http://stackoverflow.com/questions/21109677/node-with-minimum-value-in-a-binary-search-tree
*************************************************************/
TransactionNode* BST::findSmallest()
{
	Node* n = this->mpRoot;
	if (n == nullptr)
		return nullptr;

	if (n->getLeft() == nullptr)
		return (dynamic_cast<TransactionNode*>(n));

	while (n->getLeft() != nullptr)
	{
		n = n->getLeft();
	}

	return (dynamic_cast<TransactionNode*>(n));
}

/*************************************************************
* Function: findLargest()
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
* Description: Sets a TransactionNode to the largest node in the BST
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
TransactionNode* BST::findLargest()
{
	Node* n = this->mpRoot;
	if (n == nullptr)
		return nullptr;

	if (n->getRight() == nullptr)
		return (dynamic_cast<TransactionNode*>(n));

	while (n->getRight() != nullptr)
	{
		n = n->getRight();
	}

	return (dynamic_cast<TransactionNode*>(n));
}

/*************************************************************
* Function: destroy()
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
* Description: traverses the tree in postOrder and deletes the nodes in the process, private function
* Input parameters: Node *& pTree
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::destroy(Node *& pTree)
{
	if (pTree != nullptr)
	{

		destroy(pTree->getLeft());

		destroy(pTree->getRight());

		(dynamic_cast<TransactionNode*>(pTree));

		delete pTree;
	}
}

/*************************************************************
* Function: destroy()
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
* Description: traverses the tree in postOrder and deletes the nodes in the process, public function
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::destroy()
{
	destroy(this->mpRoot);
}
