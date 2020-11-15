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
int findSize(node<int>* l)
{
	if (l == nullptr)
		return 0;

	int size = 0;
	while (l != nullptr)
	{
		l = l->next;
		size++;
	}

	return size;
}

template<typename T>
bool isPalindrome(node<T>* l)
{
	if (l == nullptr)
	{
		return true;
	}

	node<T>* head = l;
	node<T>* end = l;
	while (end->next != nullptr)
	{
		end = end->next;
	}

	while (head->next != nullptr)
	{
		if (head->data == end->data)
		{
			head = head->next;
			end = end->prev;
		}
		else
			return false;
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
	node<char>* list = new node<char>({ 'a', nullptr, nullptr });
	list->next = new node<char>({ 'a', nullptr, list });
	list->next->next = new node<char>({ 'a', nullptr, list->next });
	print(list);

	std::cout << std::boolalpha << isPalindrome(list);

	return system("pause");
}
