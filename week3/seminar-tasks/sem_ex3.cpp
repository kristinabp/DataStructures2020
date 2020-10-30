#include <iostream>
#include <string>
#include <stack>
#include <functional>

int toNum(char c)
{
	return (int)c - (int)'0';
}

int calculate(std::string input, std::function<int(int)> s, std::function<int(int)> p)
{
	std::stack<char> operations;
	int num=0;
	for (char c : input)
	{
		if (c == 's')
		{
			operations.push(c);
		}
		else if (c == 'p')
		{
			operations.push(c);
		}
		else if (toNum(c) >= 0 && toNum(c) <= 9)
		{
			num = toNum(c);
		}
	}

	while (!operations.empty())
	{
		if (operations.top() == 's')
		{
			num=s(num);
			operations.pop();
		}
		else
		{
			num=p(num);
			operations.pop();
		}
	}

	return num;
}

int main()
{
	std::string input1 = " s(s(p(5)))";
	std::cout << calculate(input1, [](int x) {return x + 1; }, [](int x) {return x - 1; } )<< "\n";
	return system("pause");
}