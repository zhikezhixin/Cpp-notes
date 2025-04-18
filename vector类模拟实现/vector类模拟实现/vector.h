#pragma once
#include <iostream>
#include <cassert>
using namespace std;

	//vector缺点：1.头部和中部效率低，需要挪动数据
	//			  2.空间不够增容时，需要开新空间，拷贝数据，效率低
	// vector优点：支持下标随机访问
	
namespace Zeker
{
	template<class T>  // 模板定义必须放在头文件中被包含到用到它的 .cpp 文件中
	class vector
	{
	public:
		typedef T* iterator; // 重命名iterator是指向 T 类型的指针
		typedef const T* const_iterator;

		vector()
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
		}

		vector(const vector<T>& v)
			:_start(nullptr), _finish(nullptr), _end_of_storage(nullptr)
		{
			reserve(v.capacity());
			for (const auto& e : v)
			{
				push_back(e);
			}
		}

		~vector()
		{
			delete[] _start;
			_start = _finish = _end_of_storage = nullptr;
		}


		iterator begin()
		{
			return _start;
		}

		iterator end()  // typename 明确声明iterator是一个类型
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const  // typename 明确声明iterator是一个类型
		{
			return _finish;
		}


		size_t size()
		{
			return _finish - _start;
		}

		size_t capacity()
		{
			return _end_of_storage - _start;
		}
		
		void reserve(size_t n)
		{
			if (n > capacity())
			{
				size_t sz = size();
				T* tmp = new T[n];
				if (_start)
				{
					for (size_t i = 0;i < sz; ++i)
					{
						tmp[i] = _start[i];
					}
					delete[] _start;
				}
				_start = tmp;
				_finish = tmp + sz;
				_end_of_storage = tmp + n;
			}
		}

		void push_back(const T& x)
		{
			insert(_finish, x);
		}

		void pop_back()
		{
			erase(_finish - 1);
		}

		void insert(iterator pos, const T& x)
		{
			assert(pos <= _finish);
			if (_finish == _end_of_storage)
			{	// 增容后原来pos失效，需要重新计算位置
				size_t n = pos - _start;
				size_t newcapacity = capacity() == 0 ? 2 : capacity() * 2;
				reserve(newcapacity);
				pos = _start + n;
			}

			iterator end = _finish - 1;
			while (end >= pos)
			{
				*(end + 1) = *end;
				--end;
			}
			*pos = x;
			++_finish;
		}

		iterator erase(iterator pos)
		{
			assert(pos < _finish);
			iterator it = pos;
			while (it < _finish)
			{
				*it = *(it + 1);
				++it;
			}
			--_finish;
			return pos;
		}

		void resize(size_t n, const T& val = T())
		{
			if (n < size())
			{
				_finish = _start + n;
			}
			else
			{
				if (n > capacity)
				{
					reserve(n);
				}
				while (_finish < _strart + n)
				{
					*_finish = val;
					++_finish;
				}
			}
		}

		void swap(vector<T>& v)
		{
			::swap(_start, v._start);  // 用”::“声明该swap是全局的，即库函数中的swap
			::swap(_finish, v._finish);
			::swap(_end_of_storage, v._end_of_storage);
		}


		T& operator[](size_t i)
		{
			assert(i < size());
			return _start[i];
		}

		const T& operator[](size_t i)const
		{
			assert(i < size());
			return _start[i];
		}

		vector operator=(const vector<T> v)
		{
			swap(v);

			return *this;
		}

		 

	private:
		iterator _start; // 指向动态数组的起始地址
		iterator _finish;// 指向“最后一个元素的下一个位置”
		iterator _end_of_storage;// 指向“整个数组空间的末尾”（容量的边界）
	};
}