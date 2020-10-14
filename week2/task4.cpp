#include<iostream>
#include<stack>
#include<string>

int convertToInt(char n)
{
	return (int)n - (int)'0';
}

int calculate(std::string input)
{
	std::stack<int> nums;

	int curNum = 0;

	for (char c : input)
	{
		if (convertToInt(c) >= 0 && convertToInt(c) <= 9)
		{
			curNum = curNum * 10 + convertToInt(c);
		}
		else if (c == ' ')
		{
			if (curNum != 0)
			{
				nums.push(curNum);
				curNum = 0;
			}
		}
		else if (c == '+' || c == '-' || c == '*' || c == '/')
		{
			int temp2 = nums.top();
			nums.pop();
			int temp1 = nums.top();
			nums.pop();
			if (c == '+')
			{
				nums.push(temp1 + temp2);
			}
			else if (c == '-')
			{
				nums.push(temp1 - temp2);
			}
			else if (c == '*')
			{
				nums.push(temp1 * temp2);
			}
			else if (c == '/')
			{
				nums.push(temp1 / temp2);
			}
		}
	}

	return nums.top();
}

int main()
{
	std::string term = "40 20 3 * +";

	std::cout << calculate(term);
	return system("pause");
}