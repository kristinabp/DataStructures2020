#ifndef PRIORITYQUEUE_H
#define PRIORITYQUEUE_H

#include<queue>
#include<iostream>
#include<cassert>

enum priority { HIGH, NORMAL, LOW };

template<typename T>
class PriorityQueue
{
private:
	std::queue<T> high;
	std::queue<T> normal;
	std::queue<T> low;
public:
	void enqueue(const T&, const priority& p = NORMAL);
	void dequeue();
	void print();
	T front()const;
	bool isEmpty() const;
};
#endif // !PRIORITYQUEUE_H
