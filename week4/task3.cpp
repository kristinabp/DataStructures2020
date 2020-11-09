#include <iostream>
#include <queue>

template<typename T>
void printQ(std::queue<T> q)
{
	std::queue<T> temp = q;
	for (size_t i = 0; i < q.size(); i++)
	{
		std::cout << temp.front() << ' ';
		temp.pop();
	}
}

template<typename T>
std::queue<T> rotate(std::queue<T>& q, int pos)
{
	std::queue<T> temp = q;
	T curr;
	for (int i=0; i<pos; i++)
	{
		curr = temp.front();
		temp.pop();
		temp.push(curr);
	}

	return temp;
}

int main()
{
	std::queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);
	q.push(40);
	q.push(50);
	q.push(60);
	printQ(q);
	std::cout << "\n";
	std::queue<int> newQ=rotate(q, 4);
	printQ(newQ);
	return system("pause");
}