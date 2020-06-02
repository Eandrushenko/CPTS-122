/*******************************************************************************************

* Programmer: Elijah Andrushenko

* Class: CptS 122, Fall 2016; Lab Section 04

* Programming Assignment: PA5

* Date: October 21st, 2016

* Description: This program creates a weekly diet and exercise plan for the user.

* History: 10/21/2016 Created the project. I believe I successfully made a lot of features it went downhill when i tried to
to implement it into main and there was a struggle trying to enter my object as a parameter ina function.
so I had to take an alternate route.

*******************************************************************************************/

#pragma once

#include "ListNode.h"

class List
{
	public:
		//Constructors
		List();

		//Destructors
		~List();

		//Getters
		Node *& getHead();

		//Setters
		void setHead(Node * const newHead);

		//App functions
		void insert(const int num, const int ID, const string &name, const string &email, const int units, const string &program, const string &level, const int missed, const string date[]);
		void printfile();
		void mark();
		void print();

	private:
		Node* mpHead = nullptr;

		//Node(int num, int ID, string name, string email, int units, string program, string level, int missed, string date[]);
		void insert(Node *& pList, const int num, const int ID, const string &name, const string &email, const int units, const string &program, const string &level, const int missed, const string date[]);

		void printfile(Node *& pList);

		void mark(Node *& pList);

		void print(Node *& pList);
};


