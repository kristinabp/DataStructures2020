#include "Stack.h"

template<typename T>
void Stack<T>::copy(const Stack& other)
{
	this->size = other.size;
	this->capacity = other.capacity;
	this->data = new T(capacity + 1);

}

template<typename T>
void Stack<T>::resize()
{
	this->capacity *= 2;
}

template<typename T>
void Stack<T>::decrease()
{
	this->capacity /= 2;
}

template<typename T>
Stack<T>::Stack(int size)
{
	this->size = size;
	this->capacity = size * 2;
	this->data = new T(capacity + 1);
}

template<typename T>
Stack<T>::Stack(const Stack& other)
{
	copy(other);
}

template<typename T>
Stack<T>& Stack<T>::operator=(const Stack& other)
{
	if (this != other)
	{
		copy(other);
	}

	return *this;
}

template<typename T>
void Stack<T>::push(const T& elem)
{
	this->size++;

	if (this->size == this->capacity)
	{
		resize();
	}

	this->data = new T(capacity + 1);
	this->data[size-1] = elem;
}

template<typename T>
T& Stack<T>::pop()
{
	if (isEmpty())
	{
		std::cout << "Stack is empty.\n";
	}

	this->size--;
	if (this->size<=this->capacity*0.4)
	{
		decrease();
	}

	delete this->data[size - 1];

	return this->data[size-1];
}

template<typename T>
bool Stack<T>::isEmpty()
{
	return this->size == 0;
}
