#include<iostream>
#include<stack>

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
bool isPalindrome(node<T>* list)
{
	node<T>* iter = list;
	std::stack<T> elem;
	while (iter)
	{
		elem.push(iter->data);
		iter = iter->next;
	}

	iter = list;
	while (iter)
	{
		if (iter->data != elem.top())
			return false;
		elem.pop();
		iter = iter->next;
	}

	return true;
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
	list->next->next = new node<int>{ 10, nullptr };
	print(list);
	std::cout << std::boolalpha << isPalindrome(list);
	clearMemory(list);
	return system("pause");
}
