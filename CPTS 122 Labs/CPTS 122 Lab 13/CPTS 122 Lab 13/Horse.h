#pragma once

#include "Mammal.h"

class Horse : public Mammal
{
public:
	Horse(void);
	~Horse(void);

	virtual void Move() const;
	virtual void Speak() const;
};
