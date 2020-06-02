#include "BST.h"

int main(void)
{
	BST tree;

	tree.insert("Test");
	tree.insert("Pizza");
	tree.insert("Zebra");
	tree.insert("Alphabet");
	tree.insert("Water");

	tree.inorderTraversal();
	cout << endl;
	tree.preorderTraversal();
	cout << endl;
	tree.postorderTraversal();


	return 0;
}