#pragma once
#include <iostream>
#include <cstring>
#include <cstdlib>
#include <cassert>
using namespace std;
typedef char DataType;

typedef struct SepList
{
	DataType* arr;
	int ArrSize;
	int Capacity;
}SL;

void InitSepList(SL* s);

void CheckSepList(SL* s);

void SepListPushBack(SL* s, DataType x);

void PrintSepList(SL* s);

void SepListPushFront(SL* s, DataType x);

void SepListPopback(SL* s);

void SepListPopFront(SL* s);  
