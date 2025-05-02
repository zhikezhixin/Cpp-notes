#include <iostream>
#include <queue>
#include <deque>
#include <ctime>  
#include <algorithm>
#include <functional>
using namespace std;

void test_deque()
{
	deque<int> d;  //  双端队列：既支持随机访问，也支持头插头删
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

	srand(time(0));  //time获取当前时间并赋给传入的指针，若传空指针，返回当前时间
	for (size_t i = 0; i < 100000;i++)
	{
		int x = rand();
		d.push_back(x);
	}
	size_t begin = clock();
	sort(d.begin(), d.end());
	size_t end = clock();

	cout <<"排序所用时间:" << (end - begin) << endl;
	cout << endl;
}

void test_priority_queue()
{
	priority_queue<int> pq_max; //优先级队列：默认大的优先级高
	priority_queue<int,vector<int>,greater<int>> pq_min; // 小的优先级高

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

void test_Solution_1() //在未排序数据中找到第K个最大的元素
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