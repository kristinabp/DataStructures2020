#include<iostream>
#include<list>
#include <iomanip>

template<typename T>
struct node
{
	T data;
	node<T>* left, * right;
};

template<typename T>
void printNthLevel(node<T>* root, int level)
{
	if (root == nullptr)
		return;

	if (level == 0)
		std::cout << root->data << " ";
	else
	{
		printNthLevel(root->left, level - 1);
		printNthLevel(root->right, level - 1);
	}
}

template<typename T>
void print(node<T>* root, int spaces)
{
	if (root != nullptr)
	{
		if (root->right)
			print(root->right, spaces + 4);
		if (spaces)
			std::cout << std::setw(spaces) << ' ';
		if (root->right) std::cout << " /\n" << std::setw(spaces) << ' ';
		std::cout << root->data << "\n ";
		if (root->left) {
			std::cout << std::setw(spaces) << ' ' << " \\\n";
			print(root->left, spaces + 4);
		}
	}
}

int main()
{
	node<int>* tree = new node<int>{ 8,nullptr, nullptr };
	tree->left = new node<int>{ 10, nullptr, nullptr };
	tree->right = new node<int>{ -20, nullptr, nullptr };
	tree->left->left = new node<int>{ -1, nullptr, nullptr };
	tree->right->left = new node<int>{ 2, nullptr, nullptr };
	tree->right->right = new node<int>{ 15, nullptr, nullptr };
	print(tree, 0);
	printNthLevel (tree,2);
	return system("pause");
}
