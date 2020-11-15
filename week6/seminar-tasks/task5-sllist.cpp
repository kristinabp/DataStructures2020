#include<iostream>
#include<vector>
#include<queue>

template<typename T>
struct node
{
	T data;
	node* next;
};

bool isMonotonous(node<int>* l)
{
	if (l == nullptr)
		return true;

	int coef;
	while (l->data == l->next->data)
	{
		l = l->next;
	}

	if (l->data < l->next->data)
	{
		coef = 1;
	}
	else coef = -1;

	while (l->next != nullptr)
	{
		if (!(coef * (l->next->data - l->data) > 0))
		{
			return false;
		}
		l = l->next;
	}

	return true;
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
	node<int>* l = new node<int>({ 5, nullptr });
	l->next = new node<int>({ 4, nullptr });
	l-> next->next = new node<int>({ 3, nullptr });
	l->next->next->next = new node<int>({ 1, nullptr });
	print(l);

	std::cout << std::boolalpha << isMonotonous(l);

	

	return system("pause");
}
