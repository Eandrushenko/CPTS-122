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

#include <iostream>
#include <string>
#include <ctime>
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
		//constructor
		Node::Node(const int num, const int ID, const string name, const string email, const int units, const string program, const string level, const int missed, const string date[]);

		//Destructor
		~Node();

		//Getters
		int getNum() const;
		int getID() const;
		string getName() const;
		string getEmail() const;
		int getUnits() const;
		string getProgram() const;
		string getLevel() const;
		Node *& getNext();
		int getMissed() const;
		string getDate() const;

		//Setters
		void setNum(int const newNum);
		void setID(int const newID);
		void setName(string const newName);
		void setEmail(string const newEmail);
		void setUnits(int const newUnits);
		void setProgram(string const newProgram);
		void setLevel(string const newLevel);
		void setNext(Node * const newNext);
		void setMissed(int const newMissed);
		void setDate(string const newDate[]);

	private:
		int mNum;
		int mID;
		string mName;
		string mEmail;
		int mUnits;
		string mProgram;
		string mLevel;
		Node* mpNext;
		int mMissed;
		string mDate[10];
};