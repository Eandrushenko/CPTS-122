/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall  2016; Lab Section 04

* Programming Assignment: PA6

* Date: October 26th, 2016

* Description: This program converts english writing to morse code.

* History: 10/26/2016 Created the BSTNodes and the fundamental BST.
10/28/2016 Created the functions that apply to the PA, completed the PA

*******************************************************************************************/

#pragma once

#include "BSTNode.h"

class BST
{
public:
	//Constructor
	BST();

	//Destructor
	~BST();

	//Getters
	Node *getRoot();

	//Setters
	void setRoot(Node * const newRoot);

	//insert Functions
	void insert(const string &newMorse, const char &newCharacter);

	//Traversal Functions
	void inorderTraversal();
	void search(const char &item);
	void destroy();

private:
	Node *mpRoot = nullptr;

	void BST::insert(Node *& pTree, const string &newMorse, const char &newCharacter);
	void inorderTraversal(Node *& pTree);
	void search(Node *& pTree, const char &item);
	void destroy(Node *& pTree);
};

//Nonmember Functions
void printMorse(BST tree);

BST Populate(BST Tree);