#pragma once
#include<iostream>
#include <vector>
using namespace std;

namespace Zeker
{
	//�º���Ҳ�ƺ�������:�������ţ�ʹ�����Ķ����������һ��ȥʹ��
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
			AdjustUp(_con.size() - 1); //�ѵĲ��������ϵ���
		}


		void AdjustDown(int root)
		{
			Compare com;
			int parent = root;
			int child = parent * 2 + 1;
			while (child < _con.size())
			{
				// ѡ�����Һ����еĴ���
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