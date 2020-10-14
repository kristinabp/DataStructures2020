#include<iostream>
#include<stack>
#include<string>

template<typename T>
void printStack(std::stack<T> s)
{
	if (!s.empty())
	{
		T curr = s.top();
		std::cout << " " << curr;
		s.pop();
		printStack(s);
	}
	else
	{
		return;
	}
}

class MaxElement
{
private :
	std::stack<int> mainStack;
	std::stack<int> maxStack;

public:
	void push(int elem)
	{
		mainStack.push(elem);
		if (mainStack.size() == 1)
		{
			maxStack.push(elem);
		}
		else if (elem > maxStack.top())
		{
			maxStack.push(elem);
		}
		else
		{
			maxStack.push(maxStack.top());
		}
	}

	void pop()
	{
		mainStack.pop();
		maxStack.pop();
	}

	int getMax()const
	{
		return maxStack.top();
	}

	void print()const
	{
		std::cout << "Main stack: ";
		printStack(mainStack);
		std::cout << std::endl;

		std::cout << "Max stack: ";
		printStack(maxStack);
		std::cout << std::endl;
	}

};
int main()
{
	MaxElement s;
	s.push(20);
	s.print();
	s.push(10);
	s.print();
	s.push(50);
	s.print();
	return system("pause");
}