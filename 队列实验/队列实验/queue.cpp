#define _CRT_SECURE_NO_WARNINGS
#include "queue.h"

void InitQueue(Queue* pq) // �ÿն�
{
	QueueNode* head = (QueueNode*)malloc(sizeof(QueueNode));
	head->next = head;
	pq->rear = head;
}

void Inqueue(Queue* pq, DataType a) // ���
{
	QueueNode* newnode = (QueueNode*)malloc(sizeof(QueueNode));
	newnode->x = a;
	newnode->next = pq->rear->next;
	pq->rear->next = newnode;
	pq->rear = newnode;
}

DataType Dequeue(Queue* pq) // ����
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
		if (pq->rear == first) // ������ӵ������һ���ڵ㣬����βָ��
		{
			pq->rear = head;  // ���б�գ�βָ������ָ��ͷ���
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
        free(temp);  // �ͷ�ÿ���ڵ�
    }
    free(head);  // �ͷ�ͷ���
    pq->rear = NULL;  // �������ÿ�
}

bool IsEmpty(Queue* pq) // �жӿ�
{
	return pq->rear == pq->rear->next;
}
