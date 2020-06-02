#pragma once

#include "Mammal.h"

class GuineaPig : public Mammal
{
public:
	GuineaPig(void);
	~GuineaPig(void);

	virtual void Move() const;
	virtual void Speak() const;
};
