#pragma once
#include <iostream>
using namespace std;
#include <cstdlib>
#include <cassert>

typedef char DataType;

typedef struct QueueNode
{
	DataType x;
	struct QueueNode* next;
}QueueNode;

typedef struct Queue
{
	QueueNode* rear;
}Queue;

void InitQueue(Queue* pq);

void Inqueue(Queue* pq, DataType a);

DataType Dequeue(Queue* pq);

void Print(Queue* pq);

bool IsEmpty(Queue* pq);

void Destroy(Queue* pq);