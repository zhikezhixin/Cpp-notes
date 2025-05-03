#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"

void InitStack(Stack* ps)
{
	ps->a = (DataType*)malloc(sizeof(DataType) * 4);
	if (ps->a == NULL)
	{
		cout << "malloc fail!" << endl;
		exit(-1);
	}
	ps->capacity = 4;
	ps->top = 0;
}

void DistoryStack(Stack* ps)
{
	assert(ps);
	ps->a = NULL;
	ps->capacity = ps->top = 0;
}

void Push(Stack* ps, DataType x)
{
	assert(ps);
	if (ps->capacity == ps->top)
	{
		DataType* tem = (DataType*)realloc(ps->a,sizeof(DataType) * (ps->capacity) * 2);
		if (tem == NULL)
		{
			cout << "realloc fail!" << endl;
			exit(-1);
		}
		else
		{
			ps->a = tem;
			ps->capacity *= 2;
		}
	}
	ps->a[ps->top] = x;
	ps->top++;
}

DataType Pop(Stack* ps)
{
	assert(ps);
	return ps->a[--ps->top];
}