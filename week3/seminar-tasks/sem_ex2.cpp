#include <iostream>
#include <string>
#include <stack>

bool isCorrect(std::string input)
{
	std::stack<char> s;
	for (char c : input)
	{
		if (c == '(')
		{
			s.push('(');
		}
		else if (c == '{')
		{
			s.push('{');
		}
		else if (c == '[')
		{
			s.push('[');
		}
		if (c == ')' && !s.empty())
		{
			if (s.top() == '(')
				s.pop();
			else return false;
		}
		
		if (c == '}' && !s.empty())
		{
			if (s.top() == '{')
				s.pop();
			else return false;
		}
		if (c == ']' && !s.empty())
		{
			if (s.top() == ']')
				s.pop();
			else return false;
		}
	}

	if (!s.empty())
		return false;
	else { return true; }
}

int main()
{
	std::string input1 = "(a * 32 / (15 - r * (23-14))) / (3 - (12 * 2))";
	std::string input2 = "(a * 32 / (15 - r * (23-14)) / (3 - (12 * 2))";
	std::string input3 = "(a * 32 / (15 - r * (23-14)))) / ((3 - (12 * 2)) ";
	std::cout << std::boolalpha << isCorrect(input1) << "\n";
	std::cout << std::boolalpha << isCorrect(input2) << '\n';
	std::cout << std::boolalpha << isCorrect(input3) << '\n';
	return system("pause");
}