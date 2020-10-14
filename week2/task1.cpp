#include <iostream>
#include <stack>

//�������� �������, ����� ������� ���� ����� �� ����� � �������� ���� �� �� ��������
//���������.�� ����� � �������� ��������� ����� �� ����� �����, � ����� �� �����
//�������� ����� ���������� ��������� ������.��������� �� �������� ������ ����� � �(�, �)�,
//�{ �, � }�, �[�, �]�.

bool isCorrect(std::string input)
{
	std::stack<char> stack;

	for (char c : input)
	{
		switch (c)
		{
		case '(':
		case '{':
		case '[':
			stack.push(c); break;
		case ')':
			if (stack.empty())
			{
				return false;
			}
			else if (stack.top() == '(' )
			{
				stack.pop();
			}
			else return false;
			break;
		case '}':
			if (stack.empty())
			{
				return false;
			}
			if (stack.top() == '{')
			{
				stack.pop();
			}
			else return false;
			break;
		case ']':
			if (stack.empty())
			{
				return false;
			}
			if (stack.top() == '[')
			{
				stack.pop();
			}
			else return false;
			break;
		}
	}

	if (stack.empty())
	{
		return true;
	}
	else return false;
}

int main()
{
	std::string input="({})[]({})";
	std::string input2 = "[]{";

	std::cout << std::boolalpha << isCorrect(input) << "\n";
	std::cout << std::boolalpha << isCorrect(input2) << "\n";

	return system("pause");
}