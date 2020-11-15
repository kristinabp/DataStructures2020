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

node<int>* removedup(node<int>* l)
{
	if (l == nullptr)
		return nullptr;

	node<int>* first = l;
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

node<int>* unionn(node<int>* first, node<int>* second)
{
	if (first == nullptr)
		return second;
	if (second == nullptr)
		return first;
	while (second!= nullptr)
	{
		insert(first, second->data);
		second = second->next;
	}

	return removedup(first);
}

template<typename T>
node<T>* intersection(node<T>* first, node<T>* second)
{
	if (first == nullptr || second == nullptr)
		return nullptr;
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
	/*node<int>* l = new node<int>({ 1, nullptr });
	l->next = new node<int>({ 2, nullptr });
	l-> next->next = new node<int>({ 3, nullptr });
	l->next->next->next = new node<int>({ 10, nullptr });
	print(l);

	node<int>* k = new node<int>({ 1, nullptr });
	k->next = new node<int>({ 10,nullptr });
	k->next->next = new node<int>({ 12, nullptr });
	k->next->next->next = new node<int>({ 20, nullptr });
	print(k);

	node<int>* u = intersection(l, k);
	print(u);*/

	return system("pause");
}
