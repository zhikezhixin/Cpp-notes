 #define _CRT_SECURE_NO_WARNINGS
#include "seplist.h"

void InitSepList(SL* s)
{
	s->arr = (DataType*)malloc(sizeof(DataType));
	s->ArrSize = 0;
	s->Capacity = 1;
}

void CheckSepList(SL* s)
{
	if (s->ArrSize == s->Capacity)
	{
		DataType* tem = (DataType*)realloc(s->arr, s->Capacity*sizeof(DataType) * 4);
		if (tem == NULL)
		{
			cout<< "realloc fail" << endl;
			exit(-1);
		}
		else
		{
			s->arr = tem;
			s->Capacity *= 4;
		}
	}
}

void SepListPushBack(SL* s, DataType x)
{
	CheckSepList(s);
	s->arr[s->ArrSize] = x;
	s->ArrSize++;
}

void PrintSepList(SL* s)
{
	for (int i = 0; i < s->ArrSize; i++)
	{
		cout << s->arr[i] << " ";
	}
	cout << endl;
}

void SepListPushFront(SL* s, DataType x)
{
	CheckSepList(s);
	for (int i = s->ArrSize - 1; i >= 0; i--)
	{
		s->arr[i + 1] = s->arr[i];
	}
	s->ArrSize++;
	s->arr[0] = x;

}

void SepListPopback(SL* s)
{
	assert(s->ArrSize > 0);
	s->ArrSize--;
}

void SepListPopFront(SL* s)
{
	assert(s->ArrSize > 0);
	for (int i = 1; i < s->ArrSize; i++)
	{
		s->arr[i - 1] = s->arr[i];
	}
	s->ArrSize--;
}
