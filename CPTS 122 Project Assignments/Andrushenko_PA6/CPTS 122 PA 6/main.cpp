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

int main(void)
{
	BST tree;

	tree = Populate(tree);

	tree.inorderTraversal();
	
	system("pause");
	system("cls");

	printMorse(tree);

	tree.destroy();

	

	return 0;
}