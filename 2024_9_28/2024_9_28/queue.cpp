#define _CRT_SECURE_NO_WARNINGS
#include "queue.h">

void InitQueue(Queue* pq)
{
	assert(pq);
	pq->head = pq->tail = NULL;
}

void DestoryQueue(Queue* pq)
{
	assert(pq);
	Qnode* cur = pq->head;
	while (cur)
	{
		Qnode* next = cur->next;
		free(cur);
		cur = next;
	}
	pq->head = pq->tail = NULL;
}

void Push(Queue* pq, DataType x)
{
	assert(pq);
	Qnode* newnode = (Qnode*)malloc(sizeof(Qnode));
	if (newnode == NULL)
	{
		cout << "malloc fail" << endl;
		exit(-1);
	}
	newnode->x = x;
	newnode->next = NULL;
	if (pq->tail == NULL)
	{
		pq->head = pq->tail = newnode;
	}
	else
	{
		pq->tail->next = newnode;
		pq->tail = newnode;
	}
}

void Pop(Queue* pq)
{
	assert(pq);
	assert(pq->head);
	if (pq->head->next == NULL)
	{
		free(pq->head);
		pq->head = pq->tail = NULL;
	}
	else
	{
		Qnode* next = pq->head->next;
		free(pq->head);
		pq->head = next;
	}
}

DataType QueueFront(Queue* pq)
{
	assert(pq);
	return pq->head->x;
}
