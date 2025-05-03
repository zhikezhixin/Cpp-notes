#pragma once
#include <iostream>
#include <cstdlib>
using namespace std;

typedef int DataType;

typedef struct SingleListNode  //定义节点
{
	DataType data;
	struct SingleListNode* next;

}SLNODE;

SLNODE* CreatNode(DataType x);

void SListPushBack(SLNODE*& phead, DataType x);

void SListPushFront(SLNODE*& phead, DataType x);

void SListPopFront(SLNODE*& phead);

void SListPopBack(SLNODE*& phead);

SLNODE* SListFind(SLNODE* phead, DataType x);

void SListInsert(SLNODE*& phead, SLNODE* posion ,DataType x);

void SListErase(SLNODE*& phead, SLNODE* posion);

void SListPrint(SLNODE* phead);