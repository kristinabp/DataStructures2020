#include<iostream>
#include<string>
#include<stack>


class Editor
{
private:
	std::stack<char> s;
	std::stack<char> prev;

public:
	Editor(): s(std::stack<char>()), prev(std::stack<char>())
	{

	}

	void append(std::string str)
	{
		prev = s;
		for (size_t i = 0; i < str.size(); i++)
		{
			s.push(str[i]);
		}
	}
	void erase(size_t k)
	{
		prev = s;
		for (size_t i = 0; i < k; i++)
		{
			s.pop();
		}
	}
	void print(size_t k) const
	{
		std::stack<char> curr = s;
		size_t elem = s.size() - k;
		for (size_t i = 0; i < s.size(); i++)
		{
			if (i == elem)
			{
				std::cout << curr.top() << std::endl;
			}
			else
			{
				curr.pop();
			}
		}
	}
	void undo()
	{
		s = prev;
	}

	void printAll() 
	{
		std::stack<char> temp;
		std::stack<char> curr = s;
		size_t size = s.size();
		for (size_t i = 0; i < size; i++)
		{
			temp.push(s.top());
			s.pop();
		}
		
		s = curr;

		for (size_t i = 0; i < size; i++)
		{
			std::cout << temp.top();
			temp.pop();
		}
	}
};

int main()
{
	Editor e1;
	e1.printAll();
	e1.append("1");
	e1.printAll();
	std::cout << std::endl;
	e1.append(" 2");
	e1.printAll();
	e1.append(" 3 4 5");
	std::cout << std::endl;
	e1.printAll();
	e1.undo();
	std::cout << std::endl;
	e1.printAll();
	std::cout << std::endl;
	e1.print(3);
	e1.erase(2);
	std::cout << std::endl;
	e1.printAll();
	return system("pause");
}
