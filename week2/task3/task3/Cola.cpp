#include "Cola.h"

Cola::Cola(const double& p, const flavour& f):Item(p), colaFlavour(f)
{
}

Item* Cola::clone() const
{
	return new Cola(*this);
}

void Cola::print() const
{
	std::cout << "Cola price: " << this->getPrice() << ", flavour: " << this->colaFlavour << std::endl;
}
