#pragma once

#include "Mammal.h"

class Cat : public Mammal
{
	public:
		Cat(void);
		~Cat(void);

		virtual void Move() const;
		virtual void Speak() const;
};
