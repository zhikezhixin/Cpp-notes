#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

void InitQueue(Queue* pq) // 置空队
{
	QueueNode* head = (QueueNode*)malloc(sizeof(QueueNode));
	head->next = head;
	pq->rear = head;
}

void Inqueue(Queue* pq, DataType a) // 入队
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->x = a;
	newnode->next = pq->rear->next;
	pq->rear->next = newnode;
	pq->rear = newnode;
}

DataType Dequeue(Queue* pq) // 出队
{
	if(pq->rear == pq->rear->next)
	{
		cout << "queue is empty, cannot dequeue" << endl;
		return '\0';
	}
	else
	{
		QueueNode* head = pq->rear->next;
		QueueNode* first = head->next;
		if (pq->rear == first) // 如果出队的是最后一个节点，更新尾指针
		{
			pq->rear = head;  // 队列变空，尾指针重新指向头结点
		}
		QueueNode* tem = first;
		head->next = first->next;
		DataType x = tem->x;
		free(tem);
		tem = NULL;

		return x;
	}
}

void Print(Queue* pq)
{
	
	if (IsEmpty(pq) == true)
	{
		cout << "queue is empty" << endl;
		return;
	}
	QueueNode* head= pq->rear->next;
	QueueNode* cur = head->next;
	while (cur != head)
	{
		cout << cur->x;
		cur = cur->next;
	}
	cout << endl;
	return;
}

void Destroy(Queue* pq)
{
	QueueNode* head = pq->rear->next;
    QueueNode* cur = head->next;
    while (cur != head) {
        QueueNode* temp = cur;
        cur = cur->next;
        free(temp);  // 释放每个节点
    }
    free(head);  // 释放头结点
    pq->rear = NULL;  // 将队列置空
}

bool IsEmpty(Queue* pq) // 判队空
{
	return pq->rear == pq->rear->next;
}
