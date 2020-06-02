#include "Cat.h"

Cat::Cat(void)
{
	cout << "Cat constructor..." << endl;
}

Cat::~Cat(void)
{
	cout << "Cat Destructor..." << endl;
}

void Cat::Move() const
{
	cout << "Cat moves a step!" << endl;
}

void Cat::Speak() const
{
	cout << "What does a Cat speak? Meow!" << endl;
}