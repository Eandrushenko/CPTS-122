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

#pragma once

class TransactionNode : public Node
{
	public:
		//Constructor
		TransactionNode(int newUnits = 0, string newData = "");

		//Destructor
		~TransactionNode();

		//Setters
		void setUnits(int newUnits);

		//Getters
		int getUnits();

		//Other functions
		void printData();


	private:
		int mUnits;
};
