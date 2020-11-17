#include<iostream>
#include<list>
#include"DLL.cpp"

//1.  В двусвързан списък от тип DLList<int> е записана редицата от числа. Напишете функция, която модифицира списъка 
//по следния начин : всеки елемент без последния се заменя със средноаритме-тичното на себе си и следващия елемент.  
//Тези елементи, за които споменатото средноаритметично не може да се запише точно в число от тип int се изтриват.
struct node
{
	int data;
	node* next, * prev;
};

void change(node* list)
{
	if (list == nullptr)
		return;

	int sum = 0;

	while (list->next != nullptr)
	{
		sum = list->data + list->next->data;
		if (sum % 2 == 0)
		{
			list->data = sum / 2;
			list = list->next;
		}
		else
		{
			if (list->prev == nullptr)
			{
				node* toDelete = list;
				list = list->next;
				list->prev = nullptr;
				delete toDelete;
			}
			else
			{
				node* toDelete = list;
				list->prev->next = list->next;
				list->next->prev = list->prev;
				list = list->next;
				delete toDelete;
			}
		}

	}
}

void change2(DoubleLinkedList<int>& l)
{
	if (l.empty())
		return;

	DoubleLinkedListIterator<int> iter = l.begin();
	DoubleLinkedListIterator<int> end = l.end();
	int sum = 0;
	while (iter.next() != l.end())
	{
		sum = *iter + *iter.next();
		if (sum % 2 == 0)
		{
			*iter = sum / 2;
			iter = iter.next();
		}
		else
		{
			if (iter.prev() == nullptr)
			{
				l.deleteFirst();
			}
			else
			{
				DoubleLinkedListIterator<int> saver = iter;
				iter = iter.next();
				l.deleteAt(saver);
			}
		}
	}
}

void print(node* l)
{
	while (l)
	{
		std::cout << l->data << " ";
		l = l->next;
	}
	std::cout << "\n";
}

void deleteMemory(node* l)
{
	while (l->next != nullptr)
	{
		node* toDelete = l;
		l = l->next;
		delete toDelete;
		l->prev = nullptr;
	}

}
int main()
{
	node* list = new node{ 5, nullptr, nullptr };
	list->next = new node{ 3, nullptr, list };
	list->next->next = new node{ 2, nullptr, list->next };
	list->next->next->next = new node{ 6, nullptr, list->next->next };
	list->next->next->next->next = new node{ 8, nullptr, list->next->next->next };
	list->next->next->next->next->next = new node{ 2, nullptr, list->next->next->next->next };
	list->next->next->next->next->next->next = new node{ 1, nullptr, list->next->next->next->next->next };
	print(list);
	change(list);
	print(list);
	deleteMemory(list);
	//-------------------------------------------
	DoubleLinkedList<int> list2;
	list2.insertFirst(5);
	list2.insertLast(3);
	list2.insertLast(2);
	list2.insertLast(6);
	list2.insertLast(8);
	list2.insertLast(2);
	list2.insertLast(1);
	for (auto iter = list2.begin(); iter != list2.end(); ++iter)
	{
		std::cout << *iter << " ";
	}
	change2(list2);
	std::cout << "\n";
	for (auto iter = list2.begin(); iter != list2.end(); ++iter)
	{
		std::cout << *iter << " ";
	}

	return system("pause");
}