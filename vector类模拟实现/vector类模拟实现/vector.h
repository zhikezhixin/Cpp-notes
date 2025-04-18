#pragma once
#include <iostream>
#include <cassert>
using namespace std;

	//vectorȱ�㣺1.ͷ�����в�Ч�ʵͣ���ҪŲ������
	//			  2.�ռ䲻������ʱ����Ҫ���¿ռ䣬�������ݣ�Ч�ʵ�
	// vector�ŵ㣺֧���±��������
	
namespace Zeker
{
	template<class T>  // ģ�嶨��������ͷ�ļ��б��������õ����� .cpp �ļ���
	class vector
	{
	public:
		typedef T* iterator; // ������iterator��ָ�� T ���͵�ָ��
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

		iterator end()  // typename ��ȷ����iterator��һ������
		{
			return _finish;
		}

		const_iterator begin()const
		{
			return _start;
		}

		const_iterator end()const  // typename ��ȷ����iterator��һ������
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
			{	// ���ݺ�ԭ��posʧЧ����Ҫ���¼���λ��
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
			::swap(_start, v._start);  // �á�::��������swap��ȫ�ֵģ����⺯���е�swap
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
		iterator _start; // ָ��̬�������ʼ��ַ
		iterator _finish;// ָ�����һ��Ԫ�ص���һ��λ�á�
		iterator _end_of_storage;// ָ����������ռ��ĩβ���������ı߽磩
	};
}