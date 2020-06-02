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

#include <iostream>
#include <string>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ofstream;
using std::ifstream;
using std::istream;
using std::ostream;

class Node
{
public:
	//Constructor
	Node(string newMorse, char newCharacter);

	//Destructor
	~Node();

	//Getters
	string getMorse() const;
	char getCharacter() const;
	Node *& getRight();
	Node *& getLeft();

	//Setters
	void setMorse(const string newMorse);
	void setCharacter(const char newCharacter);
	void setRight(Node * const newRight);
	void setLeft(Node * const newLeft);

private:
	string mMorse;
	char mCharacter;
	Node* mpRight;
	Node* mpLeft;
};
