#define _CRT_SECURE_NO_WARNINGS
#include "singlelist.h"

SLNODE* CreatNode(DataType x)
{

	SLNODE* newnode = (SLNODE*)malloc(sizeof(SLNODE));
	newnode->data = x;  // ��ʼ���½ڵ������
	newnode->next = NULL;  // �½ڵ��nextָ��NULL
	return newnode;
}


void SListPushBack(SLNODE*& phead, DataType x)
{
	SLNODE* newnode = CreatNode(x);
	if (phead == NULL)
	{
		phead = newnode;  // �������Ϊ�գ�pheadֱ��ָ���½ڵ�
		return;
	}

	SLNODE* tail = phead;  // ��ͷָ�븳ֵ��tail���Ա���������β�ڵ�ָ��
	while (tail->next != NULL)
	{
		tail = tail->next;
	}
	tail->next = newnode;  // β�ڵ������½ڵ�
}

void SListPrint(SLNODE* phead)
{
	SLNODE* cur = phead; //��ͷָ�븳ֵ��cur���Ա�������

	while (cur != NULL)
	{
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl; 
}

void SListPushFront(SLNODE*& phead, DataType x)
{
	SLNODE* newnode = CreatNode(x);
	newnode->next = phead;
	phead = newnode;
}

void SListPopFront(SLNODE*& phead)
{
	SLNODE* tem = phead;
	phead = phead->next;
	free(tem);
}

void SListPopBack(SLNODE*& phead)
{
	if (phead == NULL)
	{
		return;
	}
	else if (phead->next == NULL)
	{
		free(phead);
		phead = NULL;
	}
	else
	{
		SLNODE* pre = NULL;
		SLNODE* tail = phead;
		while (tail->next != NULL)
		{
			pre = tail;
			tail = tail->next;
		}
		free(tail);
		pre->next = NULL;
	}

}

SLNODE* SListFind(SLNODE* phead, DataType x)
{
	SLNODE* cur = phead;
	while (cur)
	{
		if (cur->data == x)
		{
			return cur;
		}
		else
		{
			cur = cur->next;
		}
	}
	return NULL;
}

void SListInsert(SLNODE*& phead, SLNODE* posion, DataType x)
{
	if (phead == posion)
	{
		SListPushFront(phead, x);
	}
	else
	{
		SLNODE* newnode = CreatNode(x);
		SLNODE* pre = phead;
		while (pre->next != posion)
		{
			pre = pre->next;
		}
		pre->next = newnode;
		newnode->next = posion;
	}
}

void SListErase(SLNODE*& phead, SLNODE* posion)
{

	if (phead == posion)
	{
		SListPopFront(phead);
	}
	else
	{
		SLNODE* pre = phead;
		while (pre->next != posion)
		{
			pre = pre->next;
		}
		pre->next = posion->next;
		free(posion);
	}
}
