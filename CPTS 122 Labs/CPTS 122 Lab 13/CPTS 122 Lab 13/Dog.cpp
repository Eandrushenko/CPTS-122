#include "Dog.h"

Dog::Dog(void)
{
	cout << "Dog constructor..." << endl;
}

Dog::~Dog(void)
{
	cout << "Dog Destructor..." << endl;
}

void Dog::Move() const
{
	cout << "Dog moves a step!" << endl;
}

void Dog::Speak() const
{
	cout << "What does a Dog speak? Bark! Bark! Bark!" << endl;
}