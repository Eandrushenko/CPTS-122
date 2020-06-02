#include "Fox.h"

Fox::Fox(void)
{
	cout << "Fox constructor..." << endl;
}

Fox::~Fox(void)
{
	cout << "Cat Destructor..." << endl;
}

void Fox::Move() const
{
	cout << "fox moves a step!" << endl;
}

void Fox::Speak() const
{
	int number = 0;
	number = random();

	if (number == 1)
	{
		cout << "What does a Fox speak? Ring-ding-ding-ding-dingeringeding! Gering-ding - ding - ding - dingeringeding! Gering - ding - ding - ding - dingeringeding!" << endl;
	}
	else if (number == 2)
	{
		cout << "What does a Fox speak? Wa-pa-pa-pa-pa-pa-pow! Wa-pa - pa - pa - pa - pa - pow!Wa - pa - pa - pa - pa - pa - pow" << endl;
	}
	else if (number == 3)
	{
		cout << "What does a Fox speak? Hatee-hatee-hatee-ho! Hatee-hatee - hatee - ho! Hatee - hatee - hatee - ho" << endl;
	}
	else if (number == 4)
	{
		cout << "What does a Fox speak? Joff-tchoff-tchoffo-tchoffo-tchoff! Tchoff-tchoff - tchoffo - tchoffo - tchoff! Joff - tchoff - tchoffo - tchoffo - tchoff!" << endl;
	}
	else if (number == 5)
	{
		cout << "What does a Fox speak? Jacha-chacha-chacha-chow! Chacha-chacha - chacha - chow! Chacha - chacha - chacha - chow!" << endl;
	}
	else if (number == 6)
	{
		cout << "What does a Fox speak? Fraka-kaka-kaka-kaka-kow! Fraka-kaka - kaka - kaka - kow! Fraka - kaka - kaka - kaka - kow!" << endl;
	}
	else if (number == 7)
	{
		cout << "What does a Fox speak? A - hee - ahee ha - hee! A - hee - ahee ha - hee! A - hee - ahee ha - hee!" << endl;
	}
}

int random(void)
{
	unsigned int random = 0;
	random = (rand() % 7) + 1;
	return random;
}