#include "priority_queue.h"

void test_priority_queue()
{
	Zeker::priority_queue<int, vector<int>> pq_1;  //Ĭ��less�Ǵ��
	Zeker::priority_queue<int, vector<int>,greater<int>> pq_2; //��greater��С��

}

int main()
{
	test_priority_queue();
	system("pause");
	return 0;
}