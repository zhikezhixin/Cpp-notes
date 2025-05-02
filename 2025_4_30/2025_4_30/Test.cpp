#include <iostream>
#include <queue>
#include <deque>
#include <ctime>  
#include <algorithm>
#include <functional>
using namespace std;

void test_deque()
{
	deque<int> d;  //  ˫�˶��У���֧��������ʣ�Ҳ֧��ͷ��ͷɾ
	int n = 10;

	for (size_t i = 0;i < n;i++)
	{
		d.push_back(i);
	}

	for (auto& de : d)
	{
		cout << de << " ";
	}
	cout << endl;
	d.pop_front();

	for (auto& de : d)
	{
		cout << de << " ";
	}
	cout << endl;
	d.clear();

	srand(time(0));  //time��ȡ��ǰʱ�䲢���������ָ�룬������ָ�룬���ص�ǰʱ��
	for (size_t i = 0; i < 100000;i++)
	{
		int x = rand();
		d.push_back(x);
	}
	size_t begin = clock();
	sort(d.begin(), d.end());
	size_t end = clock();

	cout <<"��������ʱ��:" << (end - begin) << endl;
	cout << endl;
}

void test_priority_queue()
{
	priority_queue<int> pq_max; //���ȼ����У�Ĭ�ϴ�����ȼ���
	priority_queue<int,vector<int>,greater<int>> pq_min; // С�����ȼ���

	srand(time(nullptr));
	for (int i = 0; i < 10; i++)
	{
		int x = rand()%11;
		pq_max.push(x);
		pq_min.push(x);
		cout << x << " ";
	}
	cout << endl;
	while (!pq_max.empty())
	{
		cout << pq_max.top() << " ";
		pq_max.pop();
	}
	cout << endl;
	while (!pq_min.empty())
	{
		cout << pq_min.top() << " ";
		pq_min.pop();
	}
}

void test_Solution_1() //��δ�����������ҵ���K������Ԫ��
{
	class Solution
	{
	public:
		int findKthLargest(vector<int>& nums, int k)
		{

		}
	};
}


int main()
{
	//test_deque();
	//test_priority_queue(); 
	test_Solution_1();
	return 0;
}