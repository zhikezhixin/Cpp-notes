#include <iostream>
#include <vector>  // ������ʵ�ֵĴ�С�ɱ��˳��� 
using namespace std;


void test_1() // ������ʽ
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

void test_2() // �������͵ĵ�����
{
	vector<int> v2;
	v2.push_back(1);
	v2.push_back(2);
	v2.push_back(3);
	v2.push_back(4);

	// ��ͨ������������ɶ���д
	vector<int>::iterator it = v2.begin();
	while (it != v2.end())
	{
		cout << *it * 2 << " ";
		it++;
	}
	cout << endl;

	// const������ֻ�������ڶ���const�޶�ʱ
	vector<int>::const_iterator cit = v2.begin();
	while (cit != v2.end())
	{
		cout << *cit << " ";
		cit++;
	}
	cout << endl;

	//���������
	vector<int>::reverse_iterator rit = v2.rbegin();
	while (rit != v2.rend())
	{
		cout << *rit << " ";
		rit++;
	}
	cout << endl;
}

void test_3() // �����ɾ������
{
	vector<int> v3;
	vector<int> v4;
	v3.reserve(5); // ��ǰ���ÿռ�
	v4.resize(5,1); // ��ǰ���ÿռ䲢��ʼ��
	vector<int>::iterator v = v4.begin();
	while (v != v4.end())
	{
		cout << *v << " ";
		v++;
	}
	cout << endl;

	v4.insert(v4.begin(), 0); // ͨ��������ʵ��ͷ��
	for (auto x : v4)
	{
		cout << x << " ";
	}
	cout << endl;

	v4.erase(v4.begin()); // ͨ��������ʵ��ͷɾ
	for (auto x : v4)
	{
		cout << x << " ";
	}
	cout << endl;
}

void SingleNumber() // �ҳ�ֻ����һ�ε���
{
	class Solution_1  // ĳ����ֻ����һ�Σ��������������
	{
	public:
		int singleNumber(vector<int> nums)
		{
			int val = 0;  // 0���κ�����������Ǹ�������
			for (auto e : nums)
			{
				val ^= e;  // �����н����ɺͽ���ɣ�����˳������ν
			}              // ����a ^ b ^ a ^ c ^ b = a ^ a ^ b ^ b ^ c = 0 ^ 0 ^ c = c
			return val;
		}
	};


	class Solution_2  
	{
	public:
		int singleNumber(vector<int> nums)  // // ĳ����ֻ����һ�Σ�������������δ�
		{
			int bitArr[32] = { 0 };
			for (auto e : nums)  // ͳ��32λ��1�ĸ���
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
				if (bitArr[i] % 3 == 1)  // �õ�ֻ����һ�����ֵĶ�����
				{
					num |= (1 << i);  // ƴ�Ӷ�������
				}
			}
			return num;
		}

	};

	class Solution_3  // ĳ��������ֻ����һ�Σ��������������
	{
	public:
		vector<int> singleNumber(vector<int> nums)
		{
			// �����������,�ɶԵ����ֻụ����������0
			int val = 0;
			for (auto e : nums)
			{
				val ^= e;  
			}              
			
			// ����Ϊ0��˵��������������һλ��ͬ���ҳ���һ����ͬλ���±�
			size_t i = 0;
			for (; i < 32; ++i)
			{
				if (val & (1 << i))
					break;
			}


			// ���������ְ����������ͬ��λ���ֳ�����
			int num1 = 0, num2 = 0;
			for (auto e : nums)
			{
				if (e & (1 << i))  // ��鵱ǰ���ֵĵ� i λ�ǲ��� 1
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