#pragma once  
#include "../../位图/位图/bitset.h" 
#include <string>
namespace Zeker  
{  
	struct HashStr1
	{
		size_t operator()(const std::string& str)
		{
			size_t hash = 0;
			for (size_t i = 0;i < str.size();i++)
			{
				hash *= 131;
				hash += str[i];
			}
			return hash;
		}
	};

	struct HashStr2
	{
		size_t operator()(const std::string& str)
		{
			size_t hash = 0;
			size_t magic = 63689;
			for (size_t i = 0;i < str.size();i++)
			{
				hash *= magic;
				hash += str[i];
				magic *= 37855;
			}
			return hash;
		}
	};

	struct HashStr3
	{
		size_t operator()(const std::string& str)
		{
			size_t hash = 0;
			for (size_t i = 0;i < str.size();i++)
			{
				hash *= 65599;
				hash += str[i];
			}
			return hash;
		}
	};

	template <class K,class Hash1 = HashStr1,class Hash2 = HashStr2,class Hash3 = HashStr3>
	class bloomfilter  
	{  
	public:
		bloomfilter(size_t num)
			:_bs(5*num)
			,_N(5*num)
		{}

		void set(const K& key)
		{
			size_t index1 = Hash1()(key)%_N; //Hash()创建匿名对象
			size_t index2 = Hash2()(key) % _N; //Hash()(x)调用仿函数
			size_t index3 = Hash3()(key) % _N;

			_bs.set(index1);
			_bs.set(index2);
			_bs.set(index3);
		}

		bool test(const K& key)
		{
			size_t index1 = Hash1()(key) % _N;
			if (_bs.test(index1) == false)
				return false;

			size_t index2 = Hash2()(key) % _N;
			if (_bs.test(index2) == false)
				return false;

			size_t index3 = Hash3()(key) % _N;
			if (_bs.test(index3) == false)
				return false;

			return true;
		}
	private:  
		bitset _bs;  
		size_t _N;
	};  
}