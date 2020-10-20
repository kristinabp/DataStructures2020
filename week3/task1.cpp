#include<iostream>
#include<queue>

template<typename T>
std::queue<T> merge(std::queue<T> q1, std::queue<T> q2)
{
	std::queue<T> temp;
	while (!q1.empty() && !q2.empty())
	{
		if (q1.front() <= q2.front())
		{
			temp.push(q1.front());
			q1.pop();
		}
		else
		{
			temp.push(q2.front());
			q2.pop();
		}
	}

	while (!q1.empty())
	{
		temp.push(q1.front());
		q1.pop();
	}

	while (!q2.empty())
	{
		temp.push(q2.front());
		q2.pop();
	}

	return temp;
}

int main()
{
	std::queue<int> q1;
	q1.push(1);
	q1.push(2);
	q1.push(10);
	std::queue<int> q2 ;
	q2.push(1);
	q2.push(2);
	q2.push(10);
	std::queue<int> q3 = merge(q1, q2);
	int size = q3.size();
	for (int i = 0; i < size; i++)
	{
		std::cout << q3.front() << " ";
		q3.pop();
	}
	return system("pause");
}