#include<iostream>
#include<vector>
#include<queue>

template<typename T>
struct node
{
	T data;
	node* next, *prev;
};

void findPairs(node<int>* l, int x)
{
	node<int>* head = l;
	node<int>* end = l;
	while (end->next != nullptr)
	{
		end = end->next;
	}

	while (head->next != nullptr && end->prev!=nullptr)
	{
		if (head->data + end->data > x)
		{
			end = end->prev;
		}
		else if (head->data + end->data < x)
		{
			head = head->next;
		}
		else if (head->data + end->data == x)
		{
			std::cout << "(" << head->data << "," << end->data << ") ";
			head = head->next;
			end = end->prev;
		}
	}
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
	node<int>* list = new node<int>({ 1, nullptr, nullptr });
	list->next = new node<int>({ 3, nullptr, list });
	list->next->next = new node<int>({ 4, nullptr, list->next });
	list->next->next->next = new node<int>({ 5, nullptr, list->next->next });
	list->next->next->next->next = new node<int>({ 6, nullptr, list->next->next->next });
	print(list);
	findPairs(list, 9);

	return system("pause");
}
