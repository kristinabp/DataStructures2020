#ifndef COLA_H
#define COLA_H

#include "Item.h"
#include <iostream>

class Cola :
	public Item
{
public:
	enum flavour { CHERRY, ZERO, LEMON, VANILLA, RASBERRY, GINGER };
private:
	flavour colaFlavour;
public:
	Cola(const double&, const flavour&);

	Item* clone() const;
	void print() const;
};

#endif // !COLA_H

