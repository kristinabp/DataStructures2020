#include<iostream>
#include<vector>
#include<queue>

bool func(std::vector<std::vector<int>> matrix)
{
	std::queue<std::pair<int, int>> pairs;
	std::pair<int, int> pair;
	std::pair<int, int> newA;
	int counter = 0;
	for (int i = 0; i < matrix.size(); i++)
	{
		for (int j = 0; j < matrix[0].size(); j++)
		{
			if (matrix[i][j] == 2)
			{
				pair.first = i;
				pair.second = j;
				pairs.push(pair);
			}
			if (matrix[i][j] == 1)
			{
				counter++;
			}
		}
	}

	while (!pairs.empty())
	{
		pair = pairs.front();
		
		if (pair.first - 1  > 0 && matrix[pair.first - 1][pair.second] == 1)
		{
			matrix[pair.first - 1][pair.second] = 2;
			newA.first = pair.first - 1;
			newA.second = pair.second;
			pairs.push(newA);
			counter--;
		}
		if (pair.first + 1 < matrix.size() && matrix[pair.first + 1][pair.second] == 1)
		{
			matrix[pair.first + 1][pair.second] = 2;
			newA.first = pair.first + 1;
			newA.second = pair.second;
			pairs.push(newA);
			counter--;
		}
		if (pair.second - 1 > 0 && matrix[pair.first][pair.second - 1] == 1)
		{
			matrix[pair.first][pair.second - 1] = 2;
			newA.first = pair.first;
			newA.second = pair.second - 1;
			pairs.push(newA);
			counter--;
		}
		if (pair.second + 1 < matrix[0].size() && matrix[pair.first][pair.second + 1] == 1)
		{
			matrix[pair.first][pair.second + 1] = 2;
			newA.first = pair.first;
			newA.second = pair.second + 1;
			pairs.push(newA);
			counter--;
		}

		pairs.pop();
	}

	if (counter == 0)
		return true;
	else return false;
}

int main()
{
	std::vector<std::vector<int>> matrix = { {2, 1, 0, 1, 2},
											 {1, 1, 2, 1, 0},
											 {1, 0, 1, 0, 1},
											 {1, 0, 0, 1, 1} };

	std::cout << std::boolalpha << func(matrix);
	return system("pause");
}
