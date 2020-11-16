#include "DoubleLinkedList.h"
#include "DoubleLinkedList.cpp"

#include<iostream>

int main()
{
	DLList<int> list;
	list.pushFront(5);
	list.pushFront(6);
	list.pushFront(7);
	list.pushFront(8);
	list.clear();
	list.print();

	return system("pause");
}