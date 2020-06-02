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


#include "DataAnalysis.h"

/*************************************************************
* Function: openfile()
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
* Description: opens a file for reading
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created, DataAnalysis object must be created
* Postconditions: N/A
*************************************************************/
void DataAnalysis::openfile()
{
	mCSVstream.open("data.csv");
}

/*************************************************************
* Function: populate()
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
* Description: reads from a file and inserts the data into specific trees accordingly
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created, DataAnalysis object must be created
* Postconditions: N/A
*************************************************************/
void DataAnalysis::populate()
{
	char item[20];
	int number = 0;
	char type[20];

	while (!(mCSVstream.eof()))
	{
		mCSVstream.getline(item, 20, ',');
		number = atoi(item);
		mCSVstream.getline(item, 20, ',');
		mCSVstream.getline(type, 20, '\n');

		if (type[0] == 'P')
		{
			mTreePurchased.insert(number, item);
		}
		else if (type[0] == 'S')
		{
			mTreeSold.insert(number, item);
		}
	}
	mCSVstream.close();

}

/*************************************************************
* Function: printTrees()
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
* Description: Calls inorderTraversal for the two trees
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created, DataAnalysis object must be created
* Postconditions: N/A
*************************************************************/
void DataAnalysis::printTrees()
{
	cout << "Items Sold" << endl;
	mTreeSold.inorderTraversal();
	cout << endl;
	cout << "Items Purchased" << endl;
	mTreePurchased.inorderTraversal();
}

/*************************************************************
* Function: trends()
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
* Description: Calls findSmallest and findLargest for the two trees
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created, DataAnalysis object must be created
* Postconditions: N/A
*************************************************************/
void DataAnalysis::trends()
{
	TransactionNode* item;

	cout << "Most Sold item:" << endl;
	item = mTreeSold.findLargest();
	cout << "Item: " << item->getData() << ", Units: " << item->getUnits() << endl << endl;

	cout << "Least Sold item:" << endl;
	item = mTreeSold.findSmallest();
	cout << "Item: " << item->getData() << ", Units: " << item->getUnits() << endl << endl;

	cout << "Most Purchased item:" << endl;
	item = mTreePurchased.findLargest();
	cout << "Item: " << item->getData() << ", Units: " << item->getUnits() << endl << endl;

	cout << "Least Purchased item:" << endl;
	item = mTreePurchased.findSmallest();
	cout << "Item: " << item->getData() << ", Units: " << item->getUnits() << endl << endl;

}

/*************************************************************
* Function: runAnalysis()
* Date Created: 11/18/2016
* Date Last Modified: 11/18/2016
* Description: Calls the private functions in the class and is the app wrapper for this project
* Input parameters: N/A
* Returns: N/A
* Preconditions: Node object must be created, TransactionNode object must be created, BST object must be created, DataAnalysis object must be created
* Postconditions: N/A
*************************************************************/
void DataAnalysis::runAnalysis()
{
	openfile();
	populate();
	printTrees();
	system("pause");
	system("cls");
	trends();
}