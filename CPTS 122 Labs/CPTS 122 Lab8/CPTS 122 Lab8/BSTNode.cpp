#include "BSTNode.h"

Node::Node(string NewData)
{
	mData = NewData;
	mpRight = nullptr;
	mpLeft = nullptr;
}

Node::~Node()
{

}

string Node::getData() const
{
	return mData;
}

Node *& Node::getRight()
{
	return mpRight;
}

Node *& Node::getLeft()
{
	return mpLeft;
}

void Node::setData(const string NewData)
{
	mData = NewData;
}

void Node::setRight(Node * const newRight)
{
	mpRight = newRight;
}

void Node::setLeft(Node * const newLeft)
{
	mpLeft = newLeft;
}

