#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTree.h"

int main()
{
	BTNode* A = CreatNewnode('A');
	BTNode* B = CreatNewnode('B');
	BTNode* C = CreatNewnode('C');
	BTNode* D = CreatNewnode('D');
	BTNode* E = CreatNewnode('E');

	A->left = B;
	A->right = C;
	B->left = D;
	B->right = E;

	PrevOrder(A);
	cout << endl;
	InOrder(A);
	cout << endl;
	PostOrder(A);
	cout << endl;

	cout << "TreeSize:" << TreeSize(A) << " " <<endl;
	cout << "TreeLeafSize:" << TreeLeafSize(A) << "" << endl;
	Destroy(A);
	return 0;
}