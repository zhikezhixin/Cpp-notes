#pragma once

template<class K , class V>
struct AVLTreeNode
{
	AVLTreeNode<K, V>* _left;
	AVLTreeNode<K, V>* _right;
	AVLTreeNode<K, V>* _parent;
	int _bf; //平衡因子
	pair<K, V> _kv;

	AVLTreeNode(const pair<K,V>& kv)
		:_left(nullptr)
		,_right(nullptr)
		,_parent(nullptr)
		,_kv(kv)
		,_bf(0)
	{ }
};

template<class K,class V>
class AVLTree
{
	typedef AVLTreeNode<K, V> Node;
public:
	bool insert(const pair<K, V>& kv)
	{
		if (_root == nullptr)
		{
			_root = new Node(kv);
			return true;
		}
		Node* parent = nullptr;
		Node* cur = _root;

		//找到插入节点位置
		while (cur) //找到后cur为空跳出循环
		{
			if (kv.first > cur->_kv.first)
			{
				parent = cur;
				cur = cur->_right;
			}
			else if (kv.first < cur->_kv.first)
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
		while (parent) //节点插入后更新平衡因子
		{
			if (parent->_left = cur)
				parent->_bf--;
			else
				parent->_bf++;

			if (parent->_bf == 0) //新插入节点不影响其他节点平衡因子
			{
				break;
			}
			else if (parent->_bf == 1 || parent->_bf == -1) //新插入节点导致其他节点平衡因子改变，继续
			{                                               //向上更新平衡因子
				cur = parent;
				parent = parent->_parent;
			}
			else if (parent->_bf == 2 || parent->_bf == -2) //失去平衡，开始旋转
			{
				if (parent->_bf == -2)
				{
					if (cur->_bf == -1)//右单旋
					{
						RotateR(parent);
					}
					else if(cur->_bf == 1)
					{

					}
				}
				else if (parent->_bf == 2)
				{
					if (cur->_bf = 1)//左单旋
					{
						RotateL(parent);
					}
					else if (cur->_bf = -1)
					{

					}
				}
				break;
			}
		}
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
		parent->_bf = subR->_bf = 0;
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
		parent->_bf = subL->_bf = 0;

	}

	void RotateRL(Node* parent) //右左双旋
	{
		Node* subR = parent->_left;
		Node* subRL = subR->_left;
		int bf = subRL->_bf;

		RotateR(parent->_right);
		RotateL(parent);

		if (bf == -1)
		{
			parent->_bf = 0;
			subR->_bf = 1;
			subRL->_bf = 0;
		}
		else if (bf == 1)
		{
			parent->_bf = -1;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subR->_bf = 0;
			subRL->_bf = 0;
		}
	}

	void RotateLR(Node* parent) //左右双旋
	{
		Node* subL = parent->_left;
		Node* subLR = subL->_right;
		int bf = subLR->_bf;

		RotateL(parent->_left);
		RotateR(parent);

		if (bf == 1)
		{
			parent->_bf = 0;
			subL->_bf = -1;
			subLR->_bf = 0;
		}
		else if (bf == -1)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 1;
		}
		else if (bf == 0)
		{
			parent->_bf = 0;
			subL->_bf = 0;
			subLR->_bf = 0 ;
		}
	}

	void _InOrder(Node* root) //中序遍历内部实现
	{
		if (root == nullptr)
			return;

		_InOrder(root->_left);
		cout << root->_kv.first << ":" << root->_kv.second << endl;
		_InOrder(root->_right);
	}

	void InOrder() //中序遍历接口
	{
		_InOrder(_root);
	}
	
	int Height(Node* root)
	{
		if (root == nullptr)
			return 0;
		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return leftHeight > rightHeight ? leftHeight + 1 : rightHeight + 1;
	}

	bool _IsBalance(Node* root) //判断平衡内部实现
	{
		if (root == nullptr)
			return true;
		int leftHeight = Height(root->_left);
		int rightHeight = Height(root->_right);

		return abs(leftHeight - rightHeight) < 2  //检查自己和左右孩子是否都平衡
				&& IsBalance(root->_left) 
				&& IsBalance(root->_right);
	}

	bool IsBalance() //判断平衡接口
	{
		return _IsBalance(_root);
	}

private:
	Node* _root = nullptr;
};