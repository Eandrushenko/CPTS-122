#pragma once

#include "Mammal.h"
#include <time.h>
#include <stdlib.h>

class Fox : public Mammal
{
public:
	Fox(void);
	~Fox(void);

	virtual void Move() const;
	virtual void Speak() const;
};

int random(void);
