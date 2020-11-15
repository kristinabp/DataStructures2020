#include<iostream>
#include<vector>
#include<queue>

template<typename T>
struct node
{
	T data;
	node* next;
};

node<int>* removedup(node<int>* l)
{
	if (l == nullptr)
		return nullptr;

	node<int>* first=l;
	node<int>* saver;
	while (l->next != nullptr)
	{
		if (l->data == l->next->data)
		{
			saver = l->next->next;
			delete l->next;
			l->next = saver;
		}
		else
		{
			l = l->next;
		}
	}

	return first;
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
	node<int>* l = new node<int>({ 1, nullptr });
	l->next = new node<int>({ 1, nullptr });
	l-> next->next = new node<int>({ 3, nullptr });
	l->next->next->next = new node<int>({ 10, nullptr });
	l->next->next->next->next = new node<int>({ 10, nullptr });
	l->next->next->next->next->next = new node<int>({ 10, nullptr });
	print(l);
	l = removedup(l);
	print(l);

	return system("pause");
}
