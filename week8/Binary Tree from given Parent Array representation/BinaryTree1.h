#ifndef BINARY_TREE_H
#define BINARY_TREE_H

#include<iostream>
#include<iomanip>

// реализация чрез списък на бащите

struct node
{
	int data;
	node* left, *right;
};

class BinaryTree
{
private:
	node* root;

	node* constructorHelper(int* parents, int size);
	node* newNode(int value);
	void createNode(int *parents, int pos, node** createdNodes, node** root);
	void printHelper(node* node, int spaces)const;
	void LRRtraversalHelper(node* root)const;
	void eraseHelper(node* root);

public:
	BinaryTree(int *parents, int size);
	~BinaryTree();

	void prettyPrint()const;
	void LRRtraversel()const;
};
#endif // !BINARY_TREE_H
