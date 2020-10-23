#include "Queue.h"
#include "Queue.cpp"

int main()
{
	Queue<int> q;
	q.push(1);
	q.push(2);
	q.push(3);
	q.pop();
	std::cout << q.front();
	return system("pause");
}
