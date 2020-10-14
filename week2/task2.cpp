#include <iostream>
#include <stack>

//Напишете програма, която пресмята стойността на инфиксни изрази.
//Напр.: (1 + ((2 + 3) * (4 * 5)))

int convertToInt(char n)
{
	return (int)n - (int)'0';
}

int calculate(std::string input)
{
	std::stack<int> nums;
	std::stack<char> operations;

	int curNum=0;

	for (char c : input)
	{
		if (convertToInt(c) >= 0 && convertToInt(c) <= 9)
		{
			curNum = curNum*10 + convertToInt(c);
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			nums.push(curNum);
			operations.push(c);
			curNum = 0; 
		}
		else if (c == ')')
		{
			if (curNum != 0)
			{
				nums.push(curNum);
				curNum = 0;
			}
			int temp2 = nums.top();
			nums.pop();
			int temp1 = nums.top();
			nums.pop();
			if (operations.top() == '+')
			{
				nums.push(temp1 + temp2);
			}
			else if (operations.top() == '-')
			{
				nums.push(temp1 - temp2);
			}
			else if (operations.top() == '*')
			{
				nums.push(temp1 * temp2);
			}
			else if (operations.top() == '/')
			{
				nums.push(temp1 / temp2);
			}
			operations.pop();
		}
	}

	return nums.top();
}

int main()
{
	std::string input = "(10+(120/10))";
	std::cout << calculate(input);
	return system("pause");
}

