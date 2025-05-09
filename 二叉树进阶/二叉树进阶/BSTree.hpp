#pragma once
#include <iostream>
using namespace std;
template<class K>
struct BSTreeNode //Binary Search Tree
{
	BSTreeNode<K>* _left;
	BSTreeNode<K>* _right;
	K _key;

	BSTreeNode(const K& key)
		:_left(nullptr), _right(nullptr), _key(key)
	{}
};

template<class K>
class BSTree
{
	typedef BSTreeNode<K> Node;
public:
	bool Insert(const K& key)
	{
		if (_root == nullptr)
		{
			_root = new Node(key);
			return true;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_key)
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				parent = cur;
				cur = cur->_right;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(key);
		if (key > parent->_key)
		{
			parent->_right = cur;
		}
		else
		{
			parent->_left = cur;
		}
		return true;
	}

	bool Find(const K& key)
	{
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_key)
			{
				cur = cur->_left;
			}
			else if (key > cur->_key)
			{
				cur = cur->_right;
			}
			else
			{
				return true;
			}
		}
		return false;
	}

	bool Erase(const K& key)
	{
		if (_root == nullptr)
		{
			return false;
		}
		if (_root->_left == nullptr && _root->_right == nullptr && _root->_key == key)
		{
			delete _root;
			_root = nullptr;
			return true;
		}
		if (_root->_left == nullptr && _root->_right == nullptr && _root->_key != key)
		{
			return false;
		}

		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (key < cur->_key) //找被删除节点
			{
				parent = cur;
				cur = cur->_left;
			}
			else if (key > cur->_key) //找被删除节点
			{
				parent = cur;
				cur = cur->_right;
			}
			else //找到了进行删除操作
			{
				if (cur->_left == nullptr) //被删节点左孩子为空，右孩子直接连接到父节点
				{
					if (parent->_right == cur)
					{
						parent->_right = cur->_right;
					}
					else
					{
						parent->_left = cur->_right;
					}
					delete cur;
				}
				else if (cur->_right == nullptr)//被删节点右孩子为空，左孩子直接连接到父节点
				{
					if (parent->_right == cur)
					{
						parent->_right = cur->_left;
					}
					else
					{
						parent->_left = cur->_left;
					}
					delete cur;
				}
				else //被删节点左右孩子均存在不可直接删除，采用替换法，用 左子树最右边孩子 或者 右子树最左边孩子替换
				{
					Node* rightMin = cur->_right; //使用右子树最小孩子（最左边孩子）
					Node* rightMinParent = nullptr;
					while (rightMin->_left)
					{
						rightMinParent = rightMin;
						rightMin =  rightMin->_left;
					}
					cur->_key = rightMin->_key;
					rightMinParent->_left = rightMin->_right;
					delete rightMin;
				}
				return true;
			}
		}
	}
	void _InOrder(Node* root)
	{
		if (root == nullptr)
			return;
		_InOrder(root->_left);
		cout << root->_key << " ";
		_InOrder(root->_right);
	}
	void InOrder(Node* root)
	{
		_InOrder(root);
	}
private:

	Node* _root = nullptr;
	
};