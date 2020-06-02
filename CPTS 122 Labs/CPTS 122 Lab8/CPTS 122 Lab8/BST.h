#pragma once

#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

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
		void insert(const string &newData);

		//Traversal Functions
		void inorderTraversal();
		void preorderTraversal();
		void postorderTraversal();

	private:
		Node *mpRoot = nullptr;

		void insert(Node *& pTree, const string &newData);
		void inorderTraversal(Node *& pTree);
		void preorderTraversal(Node *& pTree);
		void postorderTraversal(Node *& pTree);
};
