#include<iostream>

template<typename T>
struct node
{
	T data;
	node<T>* next;
};

template<typename T>
void print(node<T>* l)
{
	node<T>* iter = l;
	while (iter)
	{
		if (iter->next != nullptr)
			std::cout << iter->data << "->";
		else
			std::cout << iter->data;
		iter = iter->next;
	}
	std::cout << "\n";
}

template<typename T>
node<T>* rotate(node<T>* list, size_t pos)
{
	if (list == nullptr)
		return list;

	node<T>* iter = list;
	node<T>* back = list;
	while (back->next != nullptr)
	{
		back = back->next;
	}
	int counter = 0;
	while (counter < pos)
	{
		counter++;
		back->next = new node<T>{ iter->data, nullptr };
		back = back->next;
		node<T>* saver = iter;
		iter = iter->next;
		delete saver;
	}
	return iter;
}

template<typename T>
void clearMemory(node<T>* list)
{
	if (list == nullptr)
		return;
	while (list != nullptr)
	{
		node<T>* saver = list;
		list = list->next;
		delete saver;
	}
}
int main()
{
	node<int>* list = new node<int>{ 10, nullptr };
	list->next = new node<int>{ 20, nullptr };
	list->next->next = new node<int>{ 30, nullptr };
	list->next->next->next = new node<int>{ 40, nullptr };
	list->next->next->next->next = new node<int>{ 50, nullptr };
	list->next->next->next->next->next = new node<int>{ 60, nullptr };
	print(list);
	list = rotate(list, 7);
	print(list);
	clearMemory(list);
	return system("pause");
}
