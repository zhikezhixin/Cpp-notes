#pragma once
#include <iostream>
using namespace std;

//红黑树特点：1.根节点为黑 2.没有连续红节点 3.每条路径上黑节点数量相同

enum Color
{
	BLACK,
	RED,
};

template <class K, class V>
struct RBTreeNode
{
	RBTreeNode<K, V>* _left;
	RBTreeNode<K, V>* _right;
	RBTreeNode<K, V>* _parent;

	pair<K, V> _kv;

	Color _col;

	RBTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_col(BLACK)
	{ }
};

template <class K,class V>
class RBTree
{
	typedef RBTreeNode<K, V> Node;
pubilc:
	bool Insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			_root->_col = BLACK;
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;
		while (cur)
		{
			if (cur->_kv.first < kv.first)
			{
				cur = cur->_right;
			}
			else if (cur->_kv.first > kv.first)
			{
				parent = cur;
				cur = cur->_left;
			}
			else
			{
				return false;
			}
		}
		cur = new Node(kv);
		if (parent->_kv.first > kv.first)
		{
			parent->_left = cur;
			cur->_parent = parent;
		}
		else
		{
			parent->_right = cur;
			cur->_parent = parent;
		}

		cur->_col = RED;
		while (parent->_col == RED)
		{
			//红黑色关键看叔叔
			Node* grandfather = parent->_parent;
			if (grandfather->_left == parent) //父亲是祖父的左孩子
			{
				Node* uncle = grandfather->_right;
				//情况1->叔叔存在且为红：父亲和叔叔变为黑,祖父变为红;继续向上递归
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else //情况2或情况3->叔叔不存在或叔叔为黑:
				{
					if(cur == parent->_right) //情况3：折线型-双旋
					{						  //（父亲是祖父的左孩子，cur是父亲的右孩子）
						RotateL(parent);
						swap(parent, cur);
					}

					//情况2：单旋（可能为第三种情况转变而来）
					 //（父亲是祖父的左孩子，cur是父亲的左孩子孩子）
					RotateR(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
			else //父亲是祖父的右孩子
			{
				Node* uncle = grandfather->_left;
				if (uncle && uncle->_col == RED)
				{
					parent->_col = uncle->_col = BLACK;
					grandfather->_col = RED;

					cur = grandfather;
					parent = cur->_parent;
				}
				else
				{
					if (cur == parent->_left)
					{
						RotateR(parent);
						swap(parent, cur);
					}

					RotateL(grandfather);
					grandfather->_col = RED;
					parent->_col = BLACK;

					break;
				}
			}
		}
		_root = BLACK;
		return true;
	}

	void RotateL(Node* parent) //左单旋
	{
		Node* subR = parent->_right; //记录失衡节点的右孩子
		Node* subRL = subR->_left; //失衡节点右孩子的左孩子
		Node* PPNode* = parent->_parent;//记录失衡节点的父节点
		parent->_right = subRL;
		if (subRL)
			subRL->_parent = parent;

		subR->_left = parent;
		parent->_parent = subR;

		if (_root == parent)
		{
			subR->_parent = nullptr;
			_root = subR;
		}
		else
		{
			if (PPNode->_left = parent)
				PPNode->_left = subR;
			else
				PPNode->_right = subR;
			subR->_parent = PPNode;

		}
	}

	void RotateR(Node* parent)//右单旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		Node* PPNode* = parent->_parent;

		parent->_left = subLR;
		if (subLR)
			subLR->_parent = parent;

		subL->_right = parent;
		parent->_parent = subL;

		if (_root == parent)
		{
			_root = subL;
			subL->_parent = nullptr;
		}
		else
		{
			if (PPNode->_left = parent)
				PPNode->_left = subL;
			else
				PPNode->_right = subL;
			subL->_parent = PPNode;
		}

	}

private:
	Node* _root = nullptr;
};