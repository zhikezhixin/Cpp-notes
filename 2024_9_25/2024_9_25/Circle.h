#pragma once
#include <iostream>
using namespace std;

#include <cassert>
#include <cstdlib>
typedef int DataType;

typedef struct CirclrList
{
	DataType data;
	struct CirclrList* prev;
	struct CirclrList* next;

}CL;

CL* InitList();

CL* CreatList(DataType x);

void PrintList(CL* phead);

void PushBack(CL* phead, DataType x);

void PushFront(CL* phead, DataType x);

void PopBack(CL* phead);

void PopFront(CL* phead);

CL* FindNode(CL* phead,DataType passion);

void InsertNode(CL* phead, DataType possion, DataType x);

void EraseNode(CL* phead, DataType possion);

void Distory(CL* phead);