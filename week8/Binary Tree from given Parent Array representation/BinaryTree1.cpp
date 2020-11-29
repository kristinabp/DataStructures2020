#include"BinaryTree1.h"

node* BinaryTree::constructorHelper(int* parents, int size)
{
    node** createdNodes=new node*[size];
    for (int i = 0; i < size; i++)
        createdNodes[i]=nullptr;

    node* root = nullptr;
    for (int i = 0; i < size; i++)
        createNode(parents, i, createdNodes, &root);
    return root;
}

node* BinaryTree::newNode(int value)
{
	node* newNode = new node{ value, nullptr, nullptr };
	return newNode;
}

void BinaryTree::createNode(int* parents, int pos, node** createdNodes, node** root)
{
    if (createdNodes[pos])
        return;

    createdNodes[pos] = newNode(pos);

    if (parents[pos] == -1)
    {
        *root = createdNodes[pos];
        return;
    }

    if (createdNodes[parents[pos]] == nullptr)
        createNode(parents, parents[pos], createdNodes, root);

    node* p = createdNodes[parents[pos]];

    if (p->left == nullptr)
        p->left = createdNodes[pos];
    else 
        p->right = createdNodes[pos];
}

void BinaryTree::printHelper(node* node, int spaces) const
{
    if (node != nullptr) {
        if (node->right) {
            printHelper(node->right, spaces + 4);
        }
        if (spaces) {
            std::cout << std::setw(spaces) << ' ';
        }
        if (node->right) std::cout << " /\n" << std::setw(spaces) << ' ';
        std::cout << node->data<< "\n ";
        if (node->left) {
            std::cout << std::setw(spaces) << ' ' << " \\\n";
            printHelper(node->left, spaces + 4);
        }
    }
}

void BinaryTree::LRRtraversalHelper(node* root)const
{
    if (root == nullptr)
        return;
    LRRtraversalHelper(root->left);
    std::cout << root->data << ' ';
    LRRtraversalHelper(root->right);
}

void BinaryTree::eraseHelper(node* root)
{
    if (root == nullptr)
        return;
    eraseHelper(root->left);
    eraseHelper(root->right);
    delete root;
}

BinaryTree::BinaryTree(int* parents, int size)
{
    root = constructorHelper(parents, size);
}

BinaryTree::~BinaryTree()
{
    eraseHelper(root);
}

void BinaryTree::prettyPrint() const
{
    printHelper(root, 0);
}

void BinaryTree::LRRtraversel() const
{
    LRRtraversalHelper(root);
}
