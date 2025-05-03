#pragma once
#include <iostream>
#include <cassert>
using namespace std;
#include <cstdlib>
typedef int DataType;

typedef struct ListNode
{
	struct ListNode* next;
	struct ListNode* prev;
	DataType data;
}DLNODE;

DLNODE* InitList();
 
void DListPushBack(DLNODE* phead,DataType x);

void DListPushFront(DLNODE* phead, DataType x);

void DlistPrint(DLNODE* phead);

void ListPopFront(DLNODE* phead);

void ListPopBack(DLNODE* phead);

DLNODE* FindNode(DLNODE* phead, DataType posion);

void InsertNode(DLNODE* phead, DataType posion, DataType x);

void DistoryList(DLNODE* phead);

void InsertNode(DLNODE* phead, DataType posion, DataType x);

void EraseNode(DLNODE* phead, DataType posion);