#ifndef QUEUE_H
#define QUEUE_H

#include<iostream>
#include<stack>

template<typename T>
class Queue
{
private:
	std::stack<T> enqueue;
	std::stack<T> dequeue;

public:
	void push(const T&);
	void pop();
	bool isEmpty()const;
	T front();
};
#endif // !QUEUE_H
