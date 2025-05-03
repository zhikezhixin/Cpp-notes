#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"
void test()
{
	Queue pq;
	InitQueue(&pq);
	Push(&pq, 1);
	Push(&pq, 2);
	Push(&pq, 3);
	Push(&pq, 4);
	while (pq.head)
	{
		cout << QueueFront(&pq) << " ";
		Pop(&pq);
	}
	cout << endl;

}

int main()
{
	test();
	return 0;
}