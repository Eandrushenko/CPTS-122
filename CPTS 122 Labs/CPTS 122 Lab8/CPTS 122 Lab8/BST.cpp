#include "BST.h"

BST::BST()
{
	mpRoot = nullptr;
}

BST::~BST()
{

}

Node * BST::getRoot()
{
	return mpRoot;
}

void BST::setRoot(Node * const newRoot)
{
	mpRoot = newRoot;
}

void BST::insert(Node *& pTree, const string &newData)
{
	if (pTree == nullptr)
	{
		Node *pMem = nullptr;
		pMem = new Node(newData);
		pTree = pMem;
	}
	else if (newData > pTree->getData())
	{
		insert(pTree->getRight(), newData);
	}
	else if (newData < pTree->getData())
	{
		insert(pTree->getLeft(), newData);
	}
	else
	{
		cout << "Duplication Error" << endl;
	}
}

void BST::insert(const string &newData)
{
	insert(this->mpRoot, newData);
}

void BST::inorderTraversal(Node *& pTree)
{
	if (pTree != nullptr)
	{
		inorderTraversal(pTree->getLeft());

		cout << pTree->getData() << endl;

		inorderTraversal(pTree->getRight());
	}
}

void BST::inorderTraversal()
{
	inorderTraversal(this->mpRoot);
}

void BST::preorderTraversal(Node *& pTree)
{
	if (pTree != nullptr)
	{
		cout << pTree->getData() << endl;

		preorderTraversal(pTree->getLeft());

		preorderTraversal(pTree->getRight());
	}
}

void BST::preorderTraversal()
{
	preorderTraversal(this->mpRoot);
}


void BST::postorderTraversal(Node *& pTree)
{
	if (pTree != nullptr)
	{

		postorderTraversal(pTree->getLeft());

		postorderTraversal(pTree->getRight());

		cout << pTree->getData() << endl;
	}
}

void BST::postorderTraversal()
{
	postorderTraversal(this->mpRoot);
}
