#ifndef BINARYTREE_H
#define BINARYTREE_H

#include<iostream>
#include<vector>
#include<iomanip>

template<typename Key, typename Value>
class BinaryTree
{
private:
	struct Node
	{
		std::pair<Key, Value> data;
		Node* left, * right;
	};

	Node* root;

	Node* constructorHelper(std::pair<Key, Value>* values, int size);
	void printHelper(Node* node,int spaces)const;

public:
	BinaryTree(std::pair<Key, Value>* values, int size);

	void prittyPrint()const;
	bool contains(const Key& key)const;
	int height()const;
	int sumLeaves()const;
	int countLeaves()const;
	void remove(const Key& key);
	void reduce(Key(*operation)(Key, Key), Key accumulator)const;
};
#endif // !BINARYTREE_H
