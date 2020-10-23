#include "Queue.h"

template<typename T>
void Queue<T>::push(const T& elem)
{
	enqueue.push(elem);
}

template<typename T>
void Queue<T>::pop()
{
	size_t size = enqueue.size();
	for (size_t i = 0; i < size; i++)
	{
		dequeue.push(enqueue.top());
		enqueue.pop();
	}

	dequeue.pop();
	size = dequeue.size();
	for (size_t i = 0; i < size; i++)
	{
		enqueue.push(dequeue.top());
		dequeue.pop();
	}
}

template<typename T>
bool Queue<T>::isEmpty() const
{
	return enqueue.size() == 0;
}

template<typename T>
T Queue<T>::front() 
{
	T front;
	size_t size = enqueue.size();
	for (size_t i = 0; i < size-1; i++)
	{
		dequeue.push(enqueue.top());
		enqueue.pop();
	}
	dequeue.push(enqueue.top());
	enqueue.pop();
	front = dequeue.top();

	size = dequeue.size();
	for (size_t i = 0; i < size-1; i++)
	{
		enqueue.push(dequeue.top());
		dequeue.pop();
	}
	enqueue.push(dequeue.top());
	dequeue.pop();

	return front;
}
