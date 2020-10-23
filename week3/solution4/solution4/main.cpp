#include "PriorityQueue.h"
#include "PriorityQueue.cpp"


int main()
{
	PriorityQueue<int> queue;
	queue.enqueue(1, HIGH);
	queue.enqueue(10, NORMAL);
	queue.print();

	return system("pause");
}
