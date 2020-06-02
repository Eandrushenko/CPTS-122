#pragma once

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

class Node
{
	public:
		//Constructor
		Node(string NewData);

		//Destructor
		~Node();

		//Getters
		string getData() const;
		Node *& getRight();
		Node *& getLeft();

		//Setters
		void setData(const string NewData);
		void setRight(Node * const newRight);
		void setLeft(Node * const newLeft);

	private:
		string mData;
		Node* mpRight;
		Node* mpLeft;
};