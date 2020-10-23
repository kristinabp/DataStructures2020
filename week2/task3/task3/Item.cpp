#include "Item.h"

Item::Item(): price(0)
{
}

Item::Item(const double& p):price(p)
{
}

double Item::getPrice() const
{
	return this->price;
}
