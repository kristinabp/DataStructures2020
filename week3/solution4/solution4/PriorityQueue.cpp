#include "PriorityQueue.h"

template<typename T>
void PriorityQueue<T>::enqueue(const T& elem, const priority& p)
{
	if (p == NORMAL)
	{
		normal.push(elem);
	}
	else if (p == HIGH)
	{
		high.push(elem);
	}
	else
	{
		low.push(elem);
	}
}

template<typename T>
void PriorityQueue<T>::dequeue()
{
	if (!high.empty())
	{
		high.pop();
	}
	else if (!normal.empty())
	{
		normal.pop();
	}
	else if (!low.empty())
	{
		low.pop();
	}
	else
	{
		assert(false);
	}
}

template<typename T>
void PriorityQueue<T>::print() 
{
	size_t size = high.size() ;
	T temp;
	if (!high.empty())
	{
		std::cout << "High priority: ";
		for (size_t i = 0; i < size-1; i++)
		{
			std::cout << high.front() << " ";
			temp = high.front();
			high.pop();
			high.push(temp);
		}
		std::cout << high.front() << " ";
		temp = high.front();
		high.pop();
		high.push(temp);
		std::cout << "\n";
	}
	else
	{
		std::cout << "High priority: empty\n";
	}
	size = normal.size();
	if (!normal.empty())
	{
		std::cout << "Normal priority: ";
		for (size_t i = 0; i < size-1; i++)
		{
			std::cout << normal.front() << " ";
			temp = normal.front();
			normal .pop();
			normal.push(temp);
		}
		std::cout << normal.front() << " ";
		temp = normal.front();
		normal.pop();
		normal.push(temp);
		std::cout << "\n";
	}
	else
	{
		std::cout << "Normal priority: empty";
		std::cout << "\n";
	}
	size = low.size();
	if (!low.empty())
	{
		std::cout << "Low priority: ";
		for (size_t i = 0; i < size-1; i++)
		{
			std::cout << low.front() << " ";
			temp = low.front();
			low.pop();
			low.push(temp);
		}
		std::cout << low.front() << " ";
		temp = low.front();
		low.pop();
		low.push(temp);
		std::cout << "\n";
	}
	else
	{
		std::cout << "Low priority: empty\n";
	}
}

template<typename T>
T PriorityQueue<T>::front() const
{
	if (!high.empty())
	{
		return high.front();
	}
	else if (!normal.empty())
	{
		return normal.front();
	}
	else if (!low.empty())
	{
		return low.front();
	}
	else
	{
		assert(false);
	}
}

template<typename T>
bool PriorityQueue<T>::isEmpty() const
{
	return high.empty() || low.empty() || normal.empty();
}
