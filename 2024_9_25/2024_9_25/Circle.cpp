#define _CRT_SECURE_NO_WARNINGS
#include "Circle.h"


CL* CreatList(DataType x)
{
	CL* newnode = (CL*)malloc(sizeof(CL));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}
CL* InitList()
{
	CL* phead = CreatList(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void PrintList(CL* phead)
{
	assert(phead);
	CL* cur = phead->next;
	while (phead != cur)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

void PushBack(CL* phead, DataType x)
{
		CL* newnode = CreatList(x);
		CL* tail = phead->prev;
		
		tail->next = newnode;
		newnode->prev = tail;
		newnode->next = phead;
		phead->prev = newnode;
}

void PushFront(CL* phead, DataType x)
{
	CL* newnode = CreatList(x);
	CL* first = phead->next;

	phead->next = newnode;
	newnode->prev = phead;
	newnode->next = first;
	first->prev = newnode;
}

void PopBack(CL* phead)
{
	CL* tail = phead->prev;
	CL* tail_second = tail->prev;

	tail_second->next = phead;
	phead->prev = tail_second;
	free(tail);
	tail = NULL;
}

void PopFront(CL* phead)
{
	CL* first = phead->next;
	CL* second = first->next;

	phead->next = second;
	second->prev = phead;
	free(first);
	first = NULL;
}

CL* FindNode(CL* phead, DataType possion)
{
	assert(phead);
	CL* tem = phead->next;

	while (tem != phead)
	{
		if (tem->data == possion)
			return tem;
		tem = tem->next;
	}
	return NULL;
}

void InsertNode(CL* phead, DataType possion, DataType x)
{
	CL* pos = FindNode(phead,possion);
	assert(pos);

	CL* prev = pos->prev;
	CL* newnode = CreatList(x);

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;

}

void EraseNode(CL* phead, DataType possion)
{

	CL* pos = FindNode(phead, possion);
	assert(pos);

	CL* prev = pos->prev;
	CL* next = pos->next;

	prev->next = next;
	next->prev = prev;

	free(pos);
	pos = NULL;
}

void Distory(CL* phead)
{
	CL* tem = phead->next;
	while (tem != phead)
	{
		CL* next = tem->next;
		free(tem);
		tem = NULL;
		tem = next;
	}
	free(phead);
	phead = NULL;
}