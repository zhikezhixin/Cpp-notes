#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"
//假设以带头结点的循环链表表示队列，并且只设一个指针指向队尾结点。
// 试编写相应的置空队、判队空、入队和出队等算法，并通过运行验证之。

int main()
{
	Queue q;
	InitQueue(&q);
	/*for (char i = 'a'; i <= 'h'; i++)
	{
		Inqueue(&q, i);
	}*/
	//Inqueue(&q, 'i');
	Print(&q);
	Dequeue(&q);

	Destroy(&q);
	return 0;
}