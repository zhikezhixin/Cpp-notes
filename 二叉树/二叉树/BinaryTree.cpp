#define _CRT_SECURE_NO_WARNINGS
#include "BinaryTree.h"

void Init(BTNode* root)
{
	root->left = root->right = NULL;
}

void Destroy(BTNode* root)
{
	if (root == NULL)
		return;
	Destroy(root->left);
	Destroy(root->right);
	free(root);
}

BTNode* CreatNewnode(DataType x)
{
	BTNode* newnode = (BTNode*)malloc(sizeof(BTNode));
	if (newnode == NULL)
	{
		cout << "malloc fail" << endl;
		exit(-1);
	}
	newnode->x = x;
	newnode->left = newnode->right = NULL;
	return newnode;
}

void PrevOrder(BTNode* root)
{
	if (root == NULL)
	{
		cout << "NULL ";
		return;
	}

	cout << root->x << " ";
	PrevOrder(root->left);
	PrevOrder(root->right);

}

void InOrder(BTNode* root)
{
	if (root == NULL)
	{
		cout << "NULL ";
		return;
	}

	PrevOrder(root->left);
	cout << root->x << " ";
	PrevOrder(root->right);

}

void PostOrder(BTNode* root) 
{
	if (root == NULL)
	{
		cout << "NULL ";
		return;
	}

	PrevOrder(root->left);
	PrevOrder(root->right);
	cout << root->x << " ";
}

int TreeSize(BTNode* root)
{
	return root == NULL ? 0 : TreeSize(root->left) + TreeSize(root->right) + 1;
}

int TreeLeafSize(BTNode* root)
{
	if (root == NULL)
	{
		return 0;
	}
	if (root->left == NULL && root->right == NULL)
	{
		return 1;
	}
	return TreeLeafSize(root->left) + TreeLeafSize(root->right);
}