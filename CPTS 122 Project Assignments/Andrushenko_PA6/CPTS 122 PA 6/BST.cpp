/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall  2016; Lab Section 04

* Programming Assignment: PA6

* Date: October 26th, 2016

* Description: This program converts english writing to morse code.

* History: 10/26/2016 Created the BSTNodes and the fundamental BST.
10/28/2016 Created the functions that apply to the PA, completed the PA

*******************************************************************************************/


#include "BST.h"

/*************************************************************
* Function: BST()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: Constructor for the BST object
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
BST::BST()
{
	mpRoot = nullptr;
}

/*************************************************************
* Function: ~BST()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: Destructor for the BST object
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
BST::~BST()
{

}

/*************************************************************
* Function: getRoot()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: Getter for the pointer to the root node
* Input parameters: N/A
* Returns: mpRoot
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
Node * BST::getRoot()
{
	return mpRoot;
}

/*************************************************************
* Function: setRoot()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: Setter for the pointer to the root node
* Input parameters: Node * const newRoot
* Returns: N/A
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::setRoot(Node * const newRoot)
{
	mpRoot = newRoot;
}

/*************************************************************
* Function: getRoot()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: Private function to insert data into the BST
* Input parameters: Node *& pTree, const string &newMorse, const char &newCharacter
* Returns: N/A
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::insert(Node *& pTree, const string &newMorse, const char &newCharacter)
{
	if (pTree == nullptr)
	{
		Node *pMem = nullptr;
		pMem = new Node(newMorse, newCharacter);
		pTree = pMem;
	}
	else if (newCharacter > pTree->getCharacter())
	{
		insert(pTree->getRight(), newMorse, newCharacter);
	}
	else if (newCharacter < pTree->getCharacter())
	{
		insert(pTree->getLeft(), newMorse, newCharacter);
	}
	else
	{
		cout << "Duplication Error" << endl;
	}
}

/*************************************************************
* Function: insert()
* Date Created: 10/26/2016
* Date Last Modified: 10/26/2016
* Description: Public function to insert data into the BST
* Input parameters: const string &newMorse, const char &newCharacter
* Returns: N/A
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::insert(const string &newMorse, const char &newCharacter)
{
	insert(this->mpRoot, newMorse, newCharacter);
}

/*************************************************************
* Function: Populate()
* Date Created: 10/28/2016
* Date Last Modified: 10/28/2016
* Description: Nonmember function that fills the BST with the contents of MorseTable.txt
* Input parameters: BST Tree
* Returns: Tree
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
BST Populate(BST Tree)
{
	ifstream input;
	char item[100];
	char character = '\0';
	string morse;
	int i = 0;

	input.open("MorseTable.txt");

	while (i < 39)
	{
		input.getline(item, 10, ' ');
		character = item[0];
		input.getline(item, 10, '\n');
		morse = item;
		Tree.insert(morse, character);
		i += 1;
	}
	input.close();

	return Tree;
}

/*************************************************************
* Function: inorderTraversal()
* Date Created: 10/28/2016
* Date Last Modified: 10/28/2016
* Description: Private function that traverses the tree in order and prints the contents of all the nodes in the process
* Input parameters: BST Tree
* Returns: N/A
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::inorderTraversal(Node *& pTree)
{
	if (pTree != nullptr)
	{
		inorderTraversal(pTree->getLeft());

		cout << pTree->getCharacter() << ' ' << pTree->getMorse() << endl;

		inorderTraversal(pTree->getRight());
	}
}

/*************************************************************
* Function: inorderTraversal()
* Date Created: 10/28/2016
* Date Last Modified: 10/28/2016
* Description: Public function that traverses the tree in order and prints the contents of all the nodes in the process
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::inorderTraversal()
{
	inorderTraversal(this->mpRoot);
}

/*************************************************************
* Function: search()
* Date Created: 10/28/2016
* Date Last Modified: 10/28/2016
* Description: Private function that searches for a character in the tree and returns the morse code equivalent.
* Input parameters: Node *& pTree, const char &item
* Returns: N/A
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::search(Node *& pTree, const char &item)
{
	string result;
	if (item == ' ')
	{
		cout << "   ";
	}
	else if (item == '\n')
	{
		cout << endl;
	}
	else if (pTree == nullptr)
	{
		cout << "Item can not be found" << endl;
	}
	else if (item == pTree->getCharacter())
	{
		result = pTree->getMorse();
		cout << result << ' ';
	}
	else if (item > pTree->getCharacter())
	{
		search(pTree->getRight(), item);
	}
	else if (item < pTree->getCharacter())
	{
		search(pTree->getLeft(), item);
	}
}

/*************************************************************
* Function: search()
* Date Created: 10/28/2016
* Date Last Modified: 10/28/2016
* Description: Public function that searches for a character in the tree and returns the morse code equivalent.
* Input parameters: const char &item
* Returns: N/A
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::search(const char &item)
{
	search(this->mpRoot, item);
}

/*************************************************************
* Function: printMorse()
* Date Created: 10/28/2016
* Date Last Modified: 10/28/2016
* Description: Nonmember Function that obtains every character in the Convert.txt file and translates it to morse code and prints it
* Input parameters: BST tree
* Returns: N/A
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void printMorse(BST tree)
{
	ifstream input;
	char character = '\0';
	input.open("Convert.txt");

	while (!(input.eof()))
	{
		input.get(character);
		if ((character >= 97) && (character <= 122))
		{
			character = character - 32;
		}
		tree.search(character);
	}
	cout << endl << endl;

	input.close();
}

/*************************************************************
* Function: destroy()
* Date Created: 10/28/2016
* Date Last Modified: 10/28/2016
* Description: Private function that performs a post order traversal and deletes the nodes in the process
* Input parameters: Node *& pTree
* Returns: N/A
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::destroy(Node *& pTree)
{
	if (pTree != nullptr)
	{

		destroy(pTree->getLeft());

		destroy(pTree->getRight());

		delete pTree;
	}
}

/*************************************************************
* Function: destroy()
* Date Created: 10/28/2016
* Date Last Modified: 10/28/2016
* Description: Public function that performs a post order traversal and deletes the nodes in the process
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, BST object must be created
* Postconditions: N/A
*************************************************************/
void BST::destroy()
{
	destroy(this->mpRoot);
}

