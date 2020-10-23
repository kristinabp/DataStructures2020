#ifndef ITEM_H
#define ITEM_H

class Item
{
private:
	double price;
public:
	Item();
	Item(const double&);
	
	virtual Item* clone() = 0;
	virtual void print() = 0;

	double getPrice() const;

};
#endif // !ITEM_H

