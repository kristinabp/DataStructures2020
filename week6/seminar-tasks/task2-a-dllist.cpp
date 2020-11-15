#include<iostream>
#include<vector>
#include<queue>

template<typename T>
struct node
{
	T data;
	node* next, *prev;
};

template<typename T>
void insertSymmetric(node<T>* &l, T elem)
{
	if (l == nullptr)
	{
		node<T>* list = new node<T>({ elem, nullptr, nullptr });
		list->next = new node<T>({ elem, nullptr, list });
		return;
	}

	node<T>* end = l;
	while (end->next != nullptr)
	{
		end = end->next;
	}
	end->next = new node<T>({ elem, nullptr, end });
	node<T>* saver = new node<T>({ elem, l, nullptr });
	l->prev = saver;
	l = saver;
}


template<typename T>
void print(node<T>* l)
{
	while (l)
	{
		std::cout << l->data << " ";
		l = l->next;
	}
	std::cout << "\n";
}

int main()
{
	node<int>* list = new node<int>({ 6, nullptr, nullptr });
	list->next = new node<int>({ 3, nullptr, list });
	list->next->next = new node<int>({ 1, nullptr, list->next });
	list->next->next->next = new node<int>({ 9, nullptr, list->next->next });
	list->next->next->next->next = new node<int>({ 9, nullptr, list->next->next->next });
	list->next->next->next->next->next= new node<int>({ 1, nullptr, list->next->next->next->next });
	list->next->next->next->next->next->next = new node<int>({ 3, nullptr, list->next->next->next->next->next });
	list->next->next->next->next->next->next->next = new node<int>({ 6, nullptr, list->next->next->next->next->next->next });
	print(list);
	insertSymmetric(list, 100);
	print(list);

	return system("pause");
}
