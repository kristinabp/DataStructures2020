#include<iostream>
#include<vector>
#include<queue>

template<typename T>
struct node
{
	T data;
	node* next;
};

node<int>* insert(node<int>* l, int elem)
{
	if (l == nullptr)
		return nullptr;

	node<int>* first;
	node<int>* saver;
	if (l->data > elem)
	{
		saver = l;
		l = new node<int>({ elem, saver });
		first = l;
	}
	else {
		first = l;

		while (l->next->next != nullptr)
		{
			if (l->data <= elem && l->next->data >= elem)
			{
				saver = l->next;
				l->next = new node<int>({ elem, saver });
				break;
			}
			else l = l->next;
		}
	}
	if (l->next->data < elem)
	{
		l->next->next = new node<int>({ elem, nullptr });
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
	l->next = new node<int>({ 2, nullptr });
	l-> next->next = new node<int>({ 3, nullptr });
	l->next->next->next = new node<int>({ 7, nullptr });
	l->next->next->next->next = new node<int>({ 10, nullptr });
	print(l);
	node<int>* p = insert(l, 0);
	print(p);
	node<int>* c = insert(l, 5);
	print(c);
	node<int>* v = insert(l, 7);
	print(v);
	node<int>* k =insert(l, 11);
	print(k);

	return system("pause");
}
