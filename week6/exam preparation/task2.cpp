#include<iostream>
#include<stack>

//Даден е двусвързан списък с четен брой елементи. Всеки елемент представлява едносвързан списък от числа в 
//интервала [0,9]. Всеки едносвързан списък сам по себе си интерпретира число, чиито цифри са елементите на 
//списъка в същия ред. ( 3->4->5 е числото 345). Напишете функция, която получава като параметър двусвързан 
//списък от този вид и проверява дали първите n/2 (където n е дължината на списъка) числа образуват растяща 
//редица и вторите n/2 числа - намаляваща.

template<typename T>
struct slnode
{
	T data;
	slnode* next;

	slnode(T elem, slnode<T>* next) : data(elem), next(next) {}
};

template<typename T>
struct dlnode
{
	slnode<T>* data;
	dlnode* next, *prev;

	dlnode(slnode<T>* l) : data(l) {}
};

int createNum(slnode<int>* list)
{
	slnode<int>* curr = list;
	int result = 0;
	while (curr != nullptr)
	{
		result = result * 10 + curr->data;
		curr = curr->next;
	}

	return result;
}

template<typename T>
dlnode<T>* findMiddle(dlnode<T>* list)
{
	dlnode<T>* slow = list;
	dlnode<T>* fast = list;
	while (fast!= nullptr)
	{
		slow = slow->next;
		fast = fast->next->next;
	}

	return slow;
}

bool isIncreasingOrDecreasing(dlnode<int>* start, dlnode<int>* end, bool increasing)
{
	dlnode<int>* temp = start;
	while (temp != end && temp->next != nullptr)
	{
		if (increasing && createNum(temp->data) >= createNum(temp->next->data))
			return false;
		if (!increasing && createNum(temp->data) <= createNum(temp->next->data))
			return false;
		temp = temp->next;
	}

	return true;
}

bool func(dlnode<int>* list)
{
	if (list == nullptr)
		return true;

	dlnode<int>* middle = findMiddle(list);

	return isIncreasingOrDecreasing(list, middle->prev, true)
		&& isIncreasingOrDecreasing(middle, nullptr, false);
}

template<typename T>
void print(slnode<T>* l)
{
	while (l)
	{
		std::cout << l->data << " ";
		l = l->next;
	}
	std::cout << "\n";
}

template<typename T>
void erase(slnode<T>* list)
{
	if (list == nullptr)
		return;

	slnode<T>* temp = list;
	while (temp != nullptr)
	{
		slnode<T>* saver = temp;
		temp = temp->next;
		delete saver;
	}
}

template<typename T>
void erase(dlnode<T>* list)
{
	if (list == nullptr)
		return;

	dlnode<T>* temp = list;
	while (temp != nullptr)
	{
		erase(temp->data);
		dlnode<T>* saver = temp;
		temp = temp->next;
		delete saver;
	}
}

int main()
{
	slnode<int>* l1 = new slnode<int>(3, new slnode<int>(4, new slnode<int>(1, nullptr)));


	slnode<int>* l2 = new slnode<int>(5, new slnode<int>(5, new slnode<int>(1, new slnode<int>(4, nullptr))));
	slnode<int>* l3 = new slnode<int>(9, new slnode<int>(9, new slnode<int>(9, new slnode<int>(9, nullptr))));

	slnode<int>* l4 = new slnode<int>(9, new slnode<int>(5, new slnode<int>(2, new slnode<int>(9, nullptr))));
	slnode<int>* l5 = new slnode<int>(9, new slnode<int>(5, new slnode<int>(2, new slnode<int>(1, nullptr))));
	slnode<int>* l6 = new slnode<int>(3, new slnode<int>(4, nullptr));

	dlnode<int>* d1 = new dlnode<int>(l1);
	dlnode<int>* d2 = new dlnode<int>(l2);
	dlnode<int>* d3 = new dlnode<int>(l3);//s
	dlnode<int>* d4 = new dlnode<int>(l4);
	dlnode<int>*  d5 = new dlnode<int>(l5);//f
	dlnode<int>* d6 = new dlnode<int>(l6);
	d1->prev = nullptr;
	d1->next = d2;
	d2->prev = d1;
	d2->next = d3;
	d3->prev = d2;
	d3->next = d4;
	d4->next = d5;
	d4->prev = d3;
	d5->next = d6;
	d5->prev = d4;
	d6->prev = d5;
	d6->next = nullptr;

	std::cout << func(d1);

	erase(d1);

	return system("pause");
}
