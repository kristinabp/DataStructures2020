#include <iostream>
#include <string>
#include <stack>
#include<queue>

int toNum(char c)
{
	return (int)c - (int)'0';
}

std::string toString(std::queue<char> input)
{
	std::string res;
	while (!input.empty())
	{
		res = res + input.front();
		input.pop();
	}

	return res;
}

std::string change(std::string input)
{
	std::stack<char> operations;
	std::queue<char> output;
	for (char c : input)
	{
		if (c>='a' && c<='z')
		{
			output.push(c);
		}
		else if (c == '(')
		{
			operations.push(c);
		}
		else if (c == '+')
		{
			if (!operations.empty())
			{
				if (operations.top() == '*' || operations.top() == '/' || operations.top() == '^')
				{
					output.push(operations.top());
					operations.pop();
					operations.push(c);
				}
				else
				{
					operations.push(c);
				}
			}
			else
			{
				operations.push(c);
			}
		}
		else if (c == '-')
		{
			if (!operations.empty())
			{
				if (operations.top() == '*' || operations.top() == '/' || operations.top() == '^')
				{
					output.push(operations.top());
					operations.pop();
					operations.push(c);
				}
				else
				{
					operations.push(c);
				}
			}
			else
			{
				operations.push(c);
			}
		}
		else if (c == '*' || c == '/' || c == '^' || c == '(')
		{
			operations.push(c);
		}
		else if (c == ')')
		{
			while (operations.top() != '(')
			{
				output.push(operations.top());
				operations.pop();
			}
			operations.pop();
		}
	}

	if (!operations.empty())
	{
		output.push(operations.top());
		operations.pop();
	}

	return toString(output);
}

int main()
{
	std::string input1 = "(a*b+c)+(a^2)";
	std::string input2 = "a - (b / c + (d - e) * f)";
	std::cout << change(input1)<< "\n";
	std::cout << change(input2) << "\n";
	return system("pause");
}