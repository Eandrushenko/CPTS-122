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
#include "ListNode.h"


/*************************************************************
* Function: Node(const int num, const int ID, const string name, const string email, const int units, const string program, const string level, const int missed, const string date[])
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: This is the constructor for the node
* Input parameters: const int num, const int ID, const string name, const string email, const int units, const string program, const string level, const int missed, const string date[]
* Returns: N/A
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
Node::Node(const int num, const int ID, const string name, const string email, const int units, const string program, const string level, const int missed, const string date[])
{
	mNum = num;
	mID = ID;
	mName = name;
	mEmail = email;
	mUnits = units;
	mProgram = program;
	mLevel = level;
	mpNext = nullptr;
	mMissed = missed;
	//array
	mDate[0] = date[0];
	mDate[1] = date[1];
	mDate[2] = date[2];
	mDate[3] = date[3];
	mDate[4] = date[4];
	mDate[5] = date[5];
	mDate[6] = date[6];
	mDate[7] = date[7];
	mDate[8] = date[8];
	mDate[9] = date[9];

}

/*************************************************************
* Function: ~Node()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: This is the destrucotr for the node
* Input parameters: N/A
* Returns: N/A
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
Node::~Node()
{

}

/*************************************************************
* Function: getNum()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: returns mNum
* Input parameters: N/A
* Returns: mNum
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
int Node::getNum() const
{
	return mNum;
}

/*************************************************************
* Function: getID()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: returns mID
* Input parameters: N/A
* Returns: mID
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
int Node::getID() const
{
	return mID;
}

/*************************************************************
* Function: getName()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: returns mName
* Input parameters: N/A
* Returns: mName
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
string Node::getName() const
{
	return mName;
}

/*************************************************************
* Function: getEmail()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: returns mEmail
* Input parameters: N/A
* Returns: mEmail
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
string Node::getEmail() const
{
	return mEmail;
}

/*************************************************************
* Function: getUnits()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: returns mUnits
* Input parameters: N/A
* Returns: mUnits
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
int Node::getUnits() const
{
	return mUnits;
}

/*************************************************************
* Function: getProgram()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: returns mProgram
* Input parameters: N/A
* Returns: mProgram
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
string Node::getProgram() const
{
	return mProgram;
}

/*************************************************************
* Function: getLevel()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: returns mLevel
* Input parameters: N/A
* Returns: mLevel
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
string Node::getLevel() const
{
	return mLevel;
}

/*************************************************************
* Function: getNext()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: returns mpNext
* Input parameters: N/A
* Returns: mpNext
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
Node *& Node::getNext()
{
	return mpNext;
}

/*************************************************************
* Function: getMissed()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: returns mMissed
* Input parameters: N/A
* Returns: mMissed
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
int Node::getMissed() const
{
	return mMissed;
}

/*************************************************************
* Function: getDate()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: returns mDate
* Input parameters: N/A
* Returns: mDate
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
string Node::getDate() const
{
	return *mDate;
}

/*************************************************************
* Function: setNum()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: sets mNum equal to newNum
* Input parameters: int const newNum
* Returns: N/A
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
void Node::setNum(int const newNum)
{
	mNum = newNum;
}

/*************************************************************
* Function: setID()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: sets mID equal to newID
* Input parameters: int const newID
* Returns: N/A
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
void Node::setID(int const newID)
{
	mID = newID;
}

/*************************************************************
* Function: setName()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: sets mName equal to newName
* Input parameters: string const newNum
* Returns: N/A
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
void Node::setName(string const newName)
{
	mName = newName;
}

/*************************************************************
* Function: setEmail()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: sets mEmail equal to newEmail
* Input parameters: string const newEmail
* Returns: N/A
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
void Node::setEmail(string const newEmail)
{
	mEmail = newEmail;
}

/*************************************************************
* Function: setUnits()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: sets mUnits equal to newUnits
* Input parameters: string const newNum
* Returns: N/A
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
void Node::setUnits(int const newUnits)
{
	mUnits = newUnits;
}

/*************************************************************
* Function: setProgram()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: sets mProgram equal to newProgram
* Input parameters: string const newProgram
* Returns: N/A
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
void Node::setProgram(string const newProgram)
{
	mProgram = newProgram;
}

/*************************************************************
* Function: setLevel()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: sets mLevel equal to newLevel
* Input parameters: string const newLevel
* Returns: N/A
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
void Node::setLevel(string const newLevel)
{
	mLevel = newLevel;
}

/*************************************************************
* Function: setNext()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: sets mNext equal to newNext
* Input parameters: Node * const newNext
* Returns: N/A
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
void Node::setNext(Node * const newNext)
{
	mpNext = newNext;
}

/*************************************************************
* Function: setMissed()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: sets mMissed equal to newMissed
* Input parameters: int const newMissed
* Returns: N/A
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
void Node::setMissed(int const newMissed)
{
	mMissed = newMissed;
}

/*************************************************************
* Function: setDate()
* Date Created: 10/21/2016
* Date Last Modified: 10/21/2016
* Description: sets mDate equal to newDate
* Input parameters: in const newDate
* Returns: N/A
* Preconditions: ListNode.h
* Postconditions: N/A
*************************************************************/
void Node::setDate(string const newDate[])
{
	mDate[0] = newDate[0];
	mDate[1] = newDate[1];
	mDate[2] = newDate[2];
	mDate[3] = newDate[3];
	mDate[4] = newDate[4];
	mDate[5] = newDate[5];
	mDate[6] = newDate[6];
	mDate[7] = newDate[7];
	mDate[8] = newDate[8];
	mDate[9] = newDate[9];
}
