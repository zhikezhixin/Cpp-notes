#pragma once
#include<iostream>
#include <vector>
using namespace std;

namespace Zeker
{
	//仿函数也称函数对象:重载括号，使得它的对象可以像函数一样去使用
	template<class T>
	struct less
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 < x2;
		}
	};

	template<class T>
	struct greator
	{
		bool operator()(const T& x1, const T& x2)
		{
			return x1 > x2;
		}
	};

	template<class T,class Container = vector<T>,class Compare = less<T>>
	class priority_queue
	{
	public:
		void AdjustUp(int child)
		{
			Compare com;
			int parent = (child - 1) / 2;
			while (child > 0)
			{
				//if (_con[child] > _con[parent])
				if(com(_con[parent],_con[child]))
				{
					swap(_con[parent], _con[parent]);
					child = parent;
					parent = (child - 1) / 2;
				}
				else
				{
					break;
				}
			}
		}

		void push(const T& x)
		{
			_con.push_back(x);
			AdjustUp(_con.size() - 1); //堆的插入用向上调整
		}


		void AdjustDown(int root)
		{
			Compare com;
			int parent = root;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				// 选出左右孩子中的大者
				if ((child + 1 < _con.size()) && com(_con[child],_con[child + 1]))
				{
					++child;
				}

				if (com(_con[parent],_con[child]))
				{
					swap(_con[child], _con[parent]);
					parent = child;
					child = parent * 2 + 1;
				}
				else
				{
					break;
				}
			}
		}

		void pop()
		{
			swap(_con[0], _con[_con.size() - 1]);
			_con.pop_back();
			AdjustDown(0);
		}

		T& top()
		{
			return _con[0]; 
		}

	private:
		Container _con;
	};
}