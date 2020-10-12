#include "Stack.h"
#include "Stack.cpp"

int main()
{
	Stack<int> s(2);
	s.push(5);
	s.push(10);
	s.push(20);
	s.push(30);
	std::cout << "top is: " << s.peek() << "\n";
	return system("pause");
}