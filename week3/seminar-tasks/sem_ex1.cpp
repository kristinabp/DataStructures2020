#include <iostream>
#include <string>
#include <stack>

int toNum(char c)
{
	return (int)c - (int)'0';
}

int calculateNum(std::string input)
{
	std::stack<int> nums;
	for (char c : input)
	{
		if (toNum(c)<=9 && toNum(c)>=0)
		{
			nums.push(toNum(c));
		}
	}

	int res = 0;
	while (!nums.empty())
	{
		res = res * 10 + nums.top();
		nums.pop();
	}

	return res;
}

int main()
{
	std::string str = "yhr5mk98kf046ej";
	std::cout << calculateNum(str);
	return system("pause");
}