#include "priority_queue.h"

void test_priority_queue()
{
	Zeker::priority_queue<int, vector<int>> pq_1;  //默认less是大队
	Zeker::priority_queue<int, vector<int>,greater<int>> pq_2; //给greater是小堆

}

int main()
{
	test_priority_queue();
	system("pause");
	return 0;
}