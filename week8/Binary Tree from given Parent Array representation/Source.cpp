#include "BinaryTree1.h"

int main()
{
    int* parent = new int[7];
    parent[0] = -1;
    parent[1] = 0;
    parent[2] = 0;
    parent[3] = 1;
    parent[4] = 1;
    parent[5] = 3;
    parent[6] = 5;

    BinaryTree tree(parent, 7);
    tree.prettyPrint();
    tree.LRRtraversel();

    delete[] parent;
	return system("pause");
}