#pragma once
#include<iostream>
using namespace std;

//利用容器进行适配转换
namespace Zeker
{
	template<class T, class Container>
	class queue
	{
	public:
		void push(const T& x)
		{
			_con.push_back(x);
		}

		void pop()
		{
			_con.pop_front();
		}

		size_t size()
		{
			return _con.size();
		}

		bool empty()
		{
			return _con.empty();
		}

		T& front()
		{
			return _con.front();
		}

		T& back()
		{
			return _con.back();
		}
	private:
		Container _con;
	};
}