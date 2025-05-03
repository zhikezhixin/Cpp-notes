#define _CRT_SECURE_NO_WARNINGS
#include "doublelist.h"

DLNODE* CreatNode(DataType x)
{
	DLNODE* newnode = (DLNODE*)malloc(sizeof(DLNODE));
	newnode->data = x;
	newnode->next = NULL;
	newnode->prev = NULL;

	return newnode;
}

DLNODE* InitList()
{
	DLNODE* phead = CreatNode(0);
	phead->next = phead;
	phead->prev = phead;

	return phead;
}

void DListPushBack(DLNODE* phead, DataType x)
{
	DLNODE* tail = phead->prev;
	DLNODE* newnode = CreatNode(x);

	tail->next = newnode;
	newnode->prev = tail;
	newnode->next = phead;
	phead->prev = newnode;
}

void DListPushFront(DLNODE* phead, DataType x)
{
	DLNODE* first = phead->next;
	DLNODE* newnode = CreatNode(x);

	phead->next = newnode;
	newnode->next = first;
	newnode->prev = phead;
	first->prev = newnode;
}

void DlistPrint(DLNODE* phead)
{
	DLNODE* tem = phead->next;
	while (tem != phead)
	{
		cout << tem->data << " ";
		tem = tem->next;
	}
	cout << endl;
}


void ListPopFront(DLNODE* phead)
{
	assert(phead->next != phead);
	DLNODE* first = phead->next;
	DLNODE* second = first->next;
	phead->next = second;
	second->prev = phead;
	free(first);
	first = NULL;
}

void ListPopBack(DLNODE* phead)
{
	DLNODE* tail = phead->prev;
	DLNODE* tail_prev = tail->prev;

	tail_prev->next = phead;
	phead->prev = tail_prev;
	free(tail);
	tail = NULL;
}

DLNODE* FindNode(DLNODE* phead, DataType posion)
{
	DLNODE* cur = phead->next;
	while (cur != phead)
	{
		if (cur->data == posion)
		{
			return cur;
		}
		cur = cur->next;
	}
	return NULL;
}


void DistoryList(DLNODE* phead)
{
	DLNODE* tem = phead->next;
	while (tem != phead)
	{
		DLNODE* next= tem->next;
		free(tem);
		tem = next;
	}
	free(phead);
	phead = NULL;
}

void InsertNode(DLNODE* phead, DataType posion, DataType x)
{
	DLNODE* pos = FindNode(phead, posion);
	assert(pos);
	DLNODE* prev = pos->prev;
	DLNODE* newnode = CreatNode(x);

	prev->next = newnode;
	newnode->prev = prev;
	newnode->next = pos;
	pos->prev = newnode;
}

void EraseNode(DLNODE* phead, DataType posion)
{
	DLNODE* pos = FindNode(phead, posion);
	assert(pos);
	DLNODE* prev = pos->prev;
	DLNODE* next = pos->next;

	prev->next = next;
	next->prev = prev;
	free(pos);
	pos = NULL;
}