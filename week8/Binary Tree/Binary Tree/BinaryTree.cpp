#include"BinaryTree.h"

template<typename Key, typename Value>
typename BinaryTree<Key, Value>::Node* BinaryTree<Key, Value>::constructorHelper(std::pair<Key, Value>* values, int size)
{
	if (size == 0)
		return nullptr;
	else
	{
		int mid = size/ 2;
		Node* node = new Node{ values[mid],nullptr,nullptr };

		node->left = constructorHelper(values,size);
		node->right = constructorHelper(values + mid + 1,size-mid-1);

		return node;
	}
}

template<typename Key, typename Value>
void BinaryTree<Key, Value>::printHelper(Node* node, int spaces) const
{
	if (node != nullptr) {
		if (node->right) {
			printHelper(node->right, spaces + 4);
		}
		if (spaces) {
			std::cout << std::setw(spaces) << ' ';
		}
		if (node->right) std::cout << " /\n" << std::setw(spaces) << ' ';
		std::cout << node->data.first << ":" << node->data.second << "\n ";
		if (node->left) {
			std::cout << std::setw(spaces) << ' ' << " \\\n";
			printHelper(node->left, spaces + 4);
		}
	}
}

template<typename Key, typename Value>
BinaryTree<Key, Value>::BinaryTree(std::pair<Key, Value>* values, int size)
{
	root = constructorHelper(values, size);

}

template<typename Key, typename Value>
void BinaryTree<Key, Value>::prittyPrint() const
{
	printHelper(root,0);
}
