#pragma once
#include <vector>

//位图：每一位代表一个数据，用0/1表示该数据存在与否

namespace Zeker
{
	class bitset
	{
	public:
		bitset(size_t N) //传入数据个数
		{
			_bits.resize(N/32 + 1,0); //每个整型有32位，计算该数据个数需要开辟多少位（几个整型）
			_num = 0;
		}

		void set(size_t x) //传入需要存储的数据
		{
			size_t index = x / 32; //算出映射的位置在第几个整形
			size_t pos = x % 32; //算出x在整形的第几个位

			_bits[index] |= (1 << pos);
		}

		void reset(size_t x)
		{
			size_t index = x / 32;
			size_t pos = x % 32;

			_bits[index] &= ~(1 << pos);
		}

		bool test(size_t x) //判断数据x是否在数据中
		{
			size_t index = x / 32;
			size_t pos = x % 32;

			return _bits[index] &(1 << pos);
		}

	private:
		std::vector<int> _bits;
		size_t _num;
	};

	void test()
	{
		bitset bs(50);
		bs.set(34);
		bs.set(30);
		bs.set(31);
		bs.set(32);

		for (int i = 0;i < 50;i++)
		{
			printf("[%d]:%d\n",i,bs.test(i));
		}
	}
}