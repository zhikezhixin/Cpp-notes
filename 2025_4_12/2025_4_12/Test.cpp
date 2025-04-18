#include <iostream>
#include <vector>  // 用数组实现的大小可变的顺序表 
using namespace std;


void test_1() // 遍历方式
{
	vector<int> v1;
	v1.push_back(1);
	v1.push_back(2);
	v1.push_back(3);
	v1.push_back(4);

	for (size_t i = 0; i < v1.size();i++)
	{
		cout << v1[i] << " ";
	}
	cout << endl;

	vector<int>::iterator it = v1.begin();
	while (it != v1.end())
	{
		cout << *it << " ";
		++it;
	}
	cout << endl;

	for (auto v : v1)
	{
		cout << v << " ";
	}
	cout << endl;
}

void test_2() // 三种类型的迭代器
{
	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	// 普通正向迭代器，可读可写
	vector<int>::iterator it = v2.begin();
	while (it != v2.end())
	{
		cout << *it * 2 << " ";
		it++;
	}
	cout << endl;

	// const迭代器只读，用于对象被const限定时
	vector<int>::const_iterator cit = v2.begin();
	while (cit != v2.end())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;

	//反向迭代器
	vector<int>::reverse_iterator rit = v2.rbegin();
	while (rit != v2.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

void test_3() // 插入和删除操作
{
	vector<int> v3;
	vector<int> v4;
	v3.reserve(5); // 提前开好空间
	v4.resize(5,1); // 提前开好空间并初始化
	vector<int>::iterator v = v4.begin();
	while (v != v4.end())
	{
		cout << *v << " ";
		v++;
	}
	cout << endl;

	v4.insert(v4.begin(), 0); // 通过迭代器实现头插
	for (auto x : v4)
	{
		cout << x << " ";
	}
	cout << endl;

	v4.erase(v4.begin()); // 通过迭代器实现头删
	for (auto x : v4)
	{
		cout << x << " ";
	}
	cout << endl;
}

void SingleNumber() // 找出只出现一次的数
{
	class Solution_1  // 某数字只出现一次，其余均出现俩次
	{
	public:
		int singleNumber(vector<int> nums)
		{
			int val = 0;  // 0和任何数异或结果还是该数本身
			for (auto e : nums)
			{
				val ^= e;  // 异或具有交换律和结合律，所以顺序无所谓
			}              // 例：a ^ b ^ a ^ c ^ b = a ^ a ^ b ^ b ^ c = 0 ^ 0 ^ c = c
			return val;
		}
	};


	class Solution_2  
	{
	public:
		int singleNumber(vector<int> nums)  // // 某数字只出现一次，其余均出现三次次
		{
			int bitArr[32] = { 0 };
			for (auto e : nums)  // 统计32位中1的个数
			{
				for (size_t i = 0; i < 32; i++)
				{
					if (e & (1 << i))
					{
						bitArr[i]++;
					}
				}
			}

			int num = 0;
			for (size_t i = 0; i < 32; ++i)
			{
				if (bitArr[i] % 3 == 1)  // 得到只出现一次数字的二进制
				{
					num |= (1 << i);  // 拼接二进制数
				}
			}
			return num;
		}

	};

	class Solution_3  // 某两个数字只出现一次，其余均出现俩次
	{
	public:
		vector<int> singleNumber(vector<int> nums)
		{
			// 所有数字异或,成对的数字会互相抵消，变成0
			int val = 0;
			for (auto e : nums)
			{
				val ^= e;  
			}              
			
			// 异或后不为0，说明两个数至少有一位不同，找出第一个不同位的下标
			size_t i = 0;
			for (; i < 32; ++i)
			{
				if (val & (1 << i))
					break;
			}


			// 把所有数字按照这个“不同的位”分成两组
			int num1 = 0, num2 = 0;
			for (auto e : nums)
			{
				if (e & (1 << i))  // 检查当前数字的第 i 位是不是 1
					num1 ^= e;
				else
					num2 ^= e;
			}
			return { num1,num2 };
		}
	};
}

void YangHuiTriangle()
{
	class Solution
	{
	public:
		vector<vector<int>> generate(int numRows)
		{
			vector<vector<int>> vv;
			vv.resize(numRows);
			for (size_t i = 0; i < numRows; ++i)
			{
				vv[i].resize(i + 1);
				vv[i][0] = 1;
				vv[i][vv[i].size() - 1] = 1;
			}

			for (size_t i = 0; i < vv.size(); ++i)
			{
				for (size_t j = 0; j < vv[i].size(); ++j)
				{
					if (vv[i][j] != 1)
					{
						vv[i][j] = vv[i - 1][j] + vv[i - 1][j - 1];
					}
				}
			}
			return vv;
		}
	};
}

int main()
{
	//test_1();
	//test_2();
	//test_3(); 
	//SingleNumber();

	return 0;
}