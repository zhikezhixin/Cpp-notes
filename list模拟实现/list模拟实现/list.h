#pragma once
#include <iostream>
using namespace std;

namespace Zeker
{
	template<class T>
	struct _list_node
	{
		_list_node<T>* _next;
		_list_node<T>* _prev;
		T _data;
	};

	template<class T>
	class list
	{
		typedef _list_node<T> node;
	public:
		list()
		{
			_head = new node;
			_head->_next = _head;
			_head->_prev = _head;
		}

		void push_back(const T& x)
		{
			node* tail = _head->_prev;
			node* newnode = new node(x);

			tail->_next = newnode;
			newnode->_next = _head;
			newnode->_prev = tail;
			_head->_prev = newnode;
		}

	private:
		node* _head;
	};
}