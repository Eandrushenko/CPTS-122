#include "GuineaPig.h"

GuineaPig::GuineaPig(void)
{
	cout << "Guinea Pig constructor..." << endl;
}

GuineaPig::~GuineaPig(void)
{
	cout << "Guinea Pig Destructor..." << endl;
}

void GuineaPig::Move() const
{
	cout << "Guinea Pig moves a step!" << endl;
}

void GuineaPig::Speak() const
{
	cout << "What does a Guinea Pig speak? Weep! Weep!" << endl;
}