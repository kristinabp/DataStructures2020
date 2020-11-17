#include<iostream>

template<typename T>
struct node
{
	T data;
	node<T>* next;
};

void removedups(node<int>* list)
{
	if (list == nullptr)
		return;

	while (list != nullptr)
	{
		while (list->next != nullptr && list->data == list->next->data)
		{
			node<int>* saver = list->next->next;
			delete list->next;
			list->next = saver;
		}

		list = list->next;
	}
}

template<typename T>
void print(node<T>* list)
{
	node<T>* iter = list;
	while (iter != nullptr)
	{
		std::cout << iter->data << " ";
		iter= iter->next;
	}
	std::cout << "\n";
}

template<typename T>
void deleteMemory(node<T>* list)
{
	while (list != nullptr)
	{
		node<T>* saver = list->next;
		delete list;
		list = saver;
	}
}


int main()
{
	node<int>* list = new node<int>{ 10, nullptr };
	list->next = new node<int>{ 10, nullptr };
	list->next->next = new node<int>{ 10, nullptr };
	print(list);
	removedups(list);
	print(list);
	deleteMemory(list);
	return system("pause");
}
