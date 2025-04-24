#pragma once
#include <iostream>
#include <cassert>  
using namespace std;

// list是带头双向循环链表，可以任意位置插入，但不支持随机访问

namespace Zeker
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _data;
	};

	template<class T, class Ref, class Ptr>  // 提供三个类型参数，分别是T，引用类型和指针类型
	struct _list_iterator
	{
		typedef _list_node<T> node;
		typedef _list_iterator<T, Ref, Ptr> self;
		node* _node;
		_list_iterator(node* n) :_node(n) 
		{}

		Ref operator*()
		{
			return _node->_data;
		}

		Ptr operator->()
		{
			return &(_node->_data);
		}
		self operator++(int)
		{
			self tmp = *this;
			_node = _node->_next;
			return tmp;
		}

		self operator--(int)
		{
			self tmp = *this;
			_node = _node->_prev;
			return tmp;
		}


		self& operator++()
		{
			_node = _node->_next;
			return *this;
		}
		self& operator--()
		{
			_node = _node->_prev;
			return *this;
		}
		bool operator!=(const self& it)
		{
			return _node != it._node;
		}
		bool operator==(const self& it)
		{
			return _node == it._node;
		}

	};

	template<class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		typedef _list_iterator<T, T&, T*> iterator;  // 对三个类型参数进行实例化
		typedef _list_iterator<T, const T&, const T*> const_iterator;
		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		list(const list& l)
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
			for (auto e:l)
			{
				push_back(e);
			}
		}

		~list()
		{
			clear();
			delete _head;
		}

		list<T>& operator=(list<T> l)
		{
			swap(_head, l._head);
			return *this;
		}

		iterator begin()
		{
			return iterator(_head->_next);
		}

		iterator begin() const
		{
			return const_iterator(_head->_next);
		}

		iterator end()
		{
			return iterator(_head);
		}	

		iterator end() const
		{
			return const_iterator(_head);
		}

		void insert(iterator pos, const T& x)
		{
			node* newnode = new node(x);
			node* cur = pos._node;
			node* prev = cur->_prev;
			 
			prev->_next = newnode;
			newnode->_prev = prev;
			newnode->_next = cur;
			cur->_prev = newnode;
		}

		void push_back(const T& x)
		{
			insert(end(), x);
		}

		void push_front(const T& x)
		{
			insert(begin(), x);
		}

		void erase(iterator pos)
		{
			assert(pos != end());
			node* cur = pos._node;
			node* prev = cur->_prev;
			node* next = cur->_next;
			prev->_next = next;
			next->_prev = prev;
			delete cur;
		}

		void pop_back()
		{
			erase(--end());
		}

		void pop_front()
		{
			erase(begin());
		}

		void clear()
		{
			node* cur = _head->_next;
			while (cur != _head)
			{
				node* next = cur->_next;
				delete cur;
				cur = next;
			}
			_head->_next = _head;
			_head->_prev = _head;
		}
	private:
		node* _head;
	};
}