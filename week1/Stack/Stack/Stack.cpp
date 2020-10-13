#include "Stack.h"

template<typename T>
void Stack<T>::copy(const Stack& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = new T[this->capacity];
	for (int i = 0; i < size; i++)
	{
		this->data[i] = other.data[i];
	}
}

template<typename T>
void Stack<T>::resize(int size)
{
	T* curr=new T[size];
	for (int i = 0; i < this->size; i++)
	{
		curr[i] = this->data[i];
	}

	erase();
	this->capacity = size;
	this->data = curr;
}

template<typename T>
void Stack<T>::erase()
{
	delete[] this->data;
}

template<typename T>
Stack<T>::Stack(int size)
{
	if (size <= 0)
	{
		this->capacity = INITIAL_SIZE;
	}
	else
	{
		this->capacity = size;
	}

	this->size = 0;
	this->data = new T[capacity];
}

template<typename T>
Stack<T>::Stack(const Stack& other)
{
	copy(other);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this != &other)
	{
		erase();
		copy(other);
	}

	return *this;
}

template<typename T>
void Stack<T>::push(const T& elem)
{
	if (this->size == this->capacity)
	{
		resize(this->capacity*2);
	}

	this->data[this->size++] = elem;
}

template<typename T>
T Stack<T>::pop()
{
	if (isEmpty())
	{
		std::cout << "Stack is empty.\n";
		exit(1);
	}

	T temp = this->data[--this->size];
	
	if (this->size <= this->capacity / 4)
	{
		resize(this->capacity / 2);
	}

	return temp;
}

template<typename T>
T Stack<T>::peek() const
{
	if (isEmpty())
	{
		std::cout << "Stack is empty.\n";
		exit(1);
	}

	return this->data[size-1];
}

template<typename T>
bool Stack<T>::isEmpty() const
{
	return this->size == 0;
}

template<typename T>
Stack<T>::~Stack()
{
	erase();
}

template <typename T>
void Stack<T>::print() const {
	for (size_t i = 0; i < size; i++)
	{
		std::cout << data[i] << " ";
	}
	std::cout << std::endl;
}
