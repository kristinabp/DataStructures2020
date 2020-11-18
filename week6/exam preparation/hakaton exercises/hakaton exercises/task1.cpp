#include <iostream>

template<typename T>
struct node
{
	T data;
	node<T>* next;

	node(T d, node<T>* n = nullptr) : data(d), next(n) {}
};

bool isFib(node<int>* list)
{ // приемам, че празен списък и списък с най-много 2 елемента не е редица на Фибоначи, защото за да имаме свойството на
	if (list == nullptr) // Фибоначи ни трябват пове 3 елемента
		return false;
	if (list->next == nullptr)
		return false;
	if (list->next->next == nullptr)
		return false;

	node<int>* prev1 = list->next;
	node<int>* prev2 = list;
	node<int>* current = list->next->next;

	while (current != nullptr)
	{
		if (!(current->data == prev2->data + prev1->data))
			return false;
		else
		{
			prev2 = prev1;
			prev1 = current;
			current = current->next;
		}
	}

	return true;
}

node<int>* reverseFib(node<int>* list)
{
	if (!(isFib(list))) // още тук правим проверката за валидна редица на Фибоначи, за това надолу във ф-та няма да правим
		return nullptr;  // проверка

	node<int>* reversedList = nullptr;

	while (list)
	{
		reversedList = new node<int>(list->data, reversedList);
		list = list->next;
	}
	return reversedList;
}

template<typename T>
void print(node<T>* list)
{
	while (list)
	{
		std::cout << list->data << " ";
		list = list->next;
	}

	std::cout << std::endl;
}

node<int>* initCorrect()
{
	node<int>* fibonacci = new node<int>(0, nullptr);
	fibonacci->next = new node<int>(1, nullptr);
	fibonacci->next->next = new node<int>(1, nullptr);
	fibonacci->next->next->next = new node<int>(2, nullptr);
	fibonacci->next->next->next->next = new node<int>(3, nullptr);
	fibonacci->next->next->next->next->next = new node<int>(5, nullptr);
	fibonacci->next->next->next->next->next->next = new node<int>(8, nullptr);
	fibonacci->next->next->next->next->next->next->next = new node<int>(13, nullptr);
	fibonacci->next->next->next->next->next->next->next->next = new node<int>(21, nullptr);
	fibonacci->next->next->next->next->next->next->next->next->next = new node<int>(34, nullptr);

	return fibonacci;
}

node<int>* initNotCorrect()
{
	node<int>* notFibonacci = new node<int>(0, nullptr);
	notFibonacci->next = new node<int>(1, nullptr);
	notFibonacci->next->next = new node<int>(1, nullptr);
	notFibonacci->next->next->next = new node<int>(2, nullptr);
	notFibonacci->next->next->next->next = new node<int>(3, nullptr);
	notFibonacci->next->next->next->next->next = new node<int>(5, nullptr);
	notFibonacci->next->next->next->next->next->next = new node<int>(8, nullptr);
	notFibonacci->next->next->next->next->next->next->next = new node<int>(100, nullptr);
	notFibonacci->next->next->next->next->next->next->next->next = new node<int>(21, nullptr);
	notFibonacci->next->next->next->next->next->next->next->next->next = new node<int>(34, nullptr);

	return notFibonacci;
}

int main()
{
	//Test case when the Fibonacci numbers are correct
	node<int>* n1 = initCorrect();
	print(n1);
	node<int>* reversedFib = reverseFib(n1);
	print(reversedFib);

	// test case when the Fibonacci numbers are not correct
	node<int>* n2 = initNotCorrect();
	print(n2);
	node<int>* reversedFib2 = reverseFib(n2);
	print(reversedFib2);
	return system("pause");
}