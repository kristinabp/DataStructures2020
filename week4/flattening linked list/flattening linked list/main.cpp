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
LListNode<T> flatten(Node<T>* node)
{
	LListNode<T>* result, *index;
	if (node == nullptr)
	{
		return nullptr;
	}
	std::vector<T> elements;
	
	result = new LListNode<T>({ nullptr, node->data });
	index = result;
	while (node != nullptr)
	{
		Node<T>* temp = node;
		while (temp != nullptr)
		{
			elements.push_back(temp->data);
			temp = temp->down;
		}
		node = node->right;
	}

	std::sort(elements.begin(), elements.end());
	for (int i = 1; i < elements.size(); i++) {
		index->next = new LListNode<T>({ nullptr, elements[i] });
		index = index->next;
	}
	return result;
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

int main()
{
	return system("pause");
}