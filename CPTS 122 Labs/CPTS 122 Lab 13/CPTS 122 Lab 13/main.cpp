#include "Dog.h"
#include "Cat.h"
#include "Horse.h"
#include "GuineaPig.h"
#include "fox.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
	srand(time(NULL));

	Mammal* theArray[6];
	Mammal* ptr;
	int choice, i;
	for (i = 0; i<6; i++)
	{
		cout << "(1)dog (2)cat (3)horse (4)guinea pig (5)fox: ";
		cin >> choice;
		switch (choice)
		{
		case 1: ptr = new Dog;
			break;
		case 2: ptr = new Cat;
			break;
		case 3: ptr = new Horse;
			break;
		case 4: ptr = new GuineaPig;
			break;
		case 5: ptr = new Fox;
			break;
		default: ptr = new Mammal;
			break;
		}
		theArray[i] = ptr;
	}
	for (i = 0; i<6; i++)
		theArray[i]->Speak();
	return 0;
}