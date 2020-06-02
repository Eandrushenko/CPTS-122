#include "Horse.h"

Horse::Horse(void)
{
	cout << "Horse constructor..." << endl;
}

Horse::~Horse(void)
{
	cout << "Horse Destructor..." << endl;
}

void Horse::Move() const
{
	cout << "Horse moves a step!" << endl;
}

void Horse::Speak() const
{
	cout << "What does a Horse speak? Neigh!" << endl;
}