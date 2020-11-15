#include<iostream>
#include<vector>
#include<queue>

template<typename T>
struct node
{
	T data;
	node* next;
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

//Floyd’s Cycle-Finding Algorithm 
template<typename T>
bool isCyclicList(node<T>* l)
{
	if (l == nullptr)
		return 0;

	node<T>* slow = l;
	node<T>* fast = l;

	while (slow != nullptr && fast != nullptr && fast->next != nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
		if (slow == fast)
		{
			return true;
		}
	}

	return false;
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
	l->next->next->next = l->next;
	//print(l);
	std::cout << std::boolalpha << isCyclicList(l);


	

	return system("pause");
}
