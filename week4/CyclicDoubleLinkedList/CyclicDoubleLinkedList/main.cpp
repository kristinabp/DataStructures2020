#include "CyclicDoubleLinkedList.h"
#include "CyclicDoubleLinkedList.cpp"

#include<iostream>

int main()
{
	CDLList<int> list;
	list.pushFront(5);
	list.pushFront(6);
	list.pushFront(7);
	list.pushFront(8);
	list.clear();
	list.print();

	return system("pause");
}