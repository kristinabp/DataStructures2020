#include<iostream>
#include<list>

struct node
{
	int data;
	node* left, * right;
};

int positiveSum(node* root)
{
	if (root == nullptr)
		return 0;

	if (root->data >= 0)
	{
		return root->data + positiveSum(root->left) + positiveSum(root->right);
	}
	else
	{
		return positiveSum(root->left) + positiveSum(root->right);
	}

}

int main()
{
	node* tree = new node{ 8,nullptr, nullptr };
	tree->left = new node{ 10, nullptr, nullptr };
	tree->right = new node{ -20, nullptr, nullptr };
	tree->left->left = new node{ -1, nullptr, nullptr };
	tree->right->left = new node{ 2, nullptr, nullptr };
	tree->right->right = new node{ 15, nullptr, nullptr };
	std::cout << positiveSum(tree);
	return system("pause");
}
