#include <iostream>
#include <string>
#include <stack>

bool isCorrectHtml(std::string input)
{
	if (input.empty()) { return true; }

	std::stack<std::string> tags;
	std::string currentTag = "";
	for (int i = 0; i < input.size(); i++)
	{
		currentTag = "";
		if (input[i] == '<')
		{
			if (input[i + 1] == '/')
			{
				if (input[i + 2] == 'f' || input[i + 2] == 'b' || input[i + 2] == 'm')
				{
					currentTag += input[i];
					currentTag += input[i + 2];
					currentTag += input[i + 3];
					if (currentTag == tags.top())
					{
						tags.pop();
						i += 4;
					}
					else return false;
				}
				else return false;
			}
			else if (input[i + 1] == 'f' || input[i + 1] == 'b' || input[i + 1] == 'm')
			{
				currentTag += input[i];
				currentTag += input[i + 1];
				currentTag += input[i + 2];
				tags.push(currentTag);
				i += 3;
			}
			else return false;
		}
	}

	if (tags.empty())
		return true;
	else return false;
}

int main()
{
	std::string input = "<f> <b> hello </b> </f>";
	std::cout << std::boolalpha << isCorrectHtml(input);
	return system("pause");
}