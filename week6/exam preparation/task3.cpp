#include<iostream>
#include<stack>

//Даден е едносвъран списък, чийто елементи са числа. Напишете функция rearange, която преподрежда елементите, така че 
//първо да бъдат четните числа, после нечетните. Относителната наредба между числата трябва да се запази. Решението ви 
//трябва да работи за O(n) по време

template<typename T>
struct slnode
{
	T data;
	slnode* next;

	slnode(T elem, slnode<T>* next) : data(elem), next(next) {}
};

slnode<int>* rearange(slnode<int>* list)
{
	if (list == nullptr)
		return nullptr;

	slnode<int>* firstEven;
	slnode<int>* lastEven;
	slnode<int>* firstOdd;
	slnode<int>* lastOdd;
	firstEven = lastEven = firstOdd = lastOdd = nullptr;

	slnode<int>* temp = list;
	while (temp != nullptr)
	{
		if (temp->data % 2 == 0)
		{
			if (firstEven == nullptr)
			{
				firstEven = lastEven = temp;
			}
			else
			{
				lastEven->next = temp;
				lastEven = temp;
			}
		}
		else
		{
			if (firstOdd == nullptr)
			{
				firstOdd = lastOdd = temp;
			}
			else
			{
				lastOdd->next = temp;
				lastOdd = temp;
			}
		}
		temp = temp->next;
	}

	if (lastEven)
		lastEven->next = firstOdd;
	if (lastOdd)
		lastOdd->next = nullptr;

	if (lastEven != nullptr)
	{
		return firstEven;
	}
	else
		return firstOdd;
}

template<typename T>
void print(slnode<T>* list)
{
	while (list)
	{
		std::cout << list->data << " ";
		list = list->next;
	}
}

int main()
{
	
	slnode<int>* list = new slnode<int>(1, new slnode<int>(8, nullptr));
	print(rearange(list));
	return system("pause");
}
