#pragma once

#include "Mammal.h"

class Dog : public Mammal
{
	public:
		Dog(void);
		~Dog(void);

		virtual void Move() const;
		virtual void Speak() const;
};
