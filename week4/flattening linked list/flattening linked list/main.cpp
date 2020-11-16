#include<iostream>
#include <vector>
#include <algorithm>

template<typename T>
struct Node
{
	Node<T>* right;
	Node<T>* down;
	T data;
};

template<typename T>
struct LListNode
{
	LListNode<T>* next;
	T data;
};

Node<int>* init() {
	Node<int>* first = new Node<int>({ nullptr, nullptr, 5 });
	first->down = new Node<int>({ nullptr, nullptr, 7 });
	first->down->down = new Node<int>({ nullptr, nullptr, 8 });
	first->down->down->down = new Node<int>({ nullptr, nullptr, 30 });
	first->right = new Node<int>({ nullptr, nullptr, 10 });
	first->right->down = new Node<int>({ nullptr, nullptr, 20 });
	first->right->right = new Node<int>({ nullptr, nullptr, 19 });
	first->right->right->down = new Node<int>({ nullptr, nullptr, 22 });
	first->right->right->down->down = new Node<int>({ nullptr, nullptr, 50 });
	first->right->right->right = new Node<int>({ nullptr, nullptr, 28 });
	first->right->right->right->down = new Node<int>({ nullptr, nullptr, 35 });
	first->right->right->right->down->down = new Node<int>({ nullptr, nullptr, 40 });
	first->right->right->right->down->down->down = new Node<int>({ nullptr, nullptr, 45 });
	return first;
}

template<typename T>
LListNode<T>* flatten(Node<T>* list)
{
	if (list == nullptr)
		return nullptr;
	LListNode<T>* result;
	std::vector<T> elements;

	while (list != nullptr)
	{
		Node<T>* elem = list;
		while (elem != nullptr)
		{
			elements.push_back(elem->data);
			elem = elem->down;
		}

		list = list->right;
	}

	std::sort(elements.begin(), elements.end());
	LListNode<T>* first;
	first = new LListNode<T>{ nullptr, elements[0] };
	result = first;
	result = result->next;
	for (int i = 1; i < elements.size(); i++)
	{
		result = new LListNode<T>({ nullptr, elements[i] });
		result = result->next;
	}

	return first;
}

template<typename T>
void print(LListNode<T>* head) {
	while (head != nullptr) {
		std::cout << head->data;
		if (head->next != nullptr) {
			std::cout << " -> ";
		}
		head = head->next;
	}
	std::cout << '\n';
}

template<typename T>
void clearMemory(Node<T>* head)
{
	while (head != nullptr) {
		Node<T>* temp = head->down;
		while (temp != nullptr) {
			Node<T>* save = temp;
			temp = temp->down;
			delete save;
		}
		temp = head;
		head = head->right;
		delete temp;
	}
}

template<typename T>
void clearMemory(LListNode<T>* head)
{
	while (head != nullptr) {
		LListNode<T>* save = head;
		head = head->next;
		delete save;
	}
}

int main()
{
	Node<int>* first = init();
	LListNode<int>* flattenList = flatten(first);
	print(flattenList);
	clearMemory(first);
	clearMemory(flattenList);
	return system("pause");
}