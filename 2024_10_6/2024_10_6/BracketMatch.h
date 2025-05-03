#pragma once
#include <iostream>
using namespace std;
#include <cassert>
#include <cstdlib>

typedef char DataType;
typedef struct Stack
{
	DataType* s;
	int top;
	int capacity;
}Stack;

void InitStack(Stack* sp);

void DestroyStack(Stack* sp);

void EnterStack(Stack* sp, DataType x);

DataType ExitStack(Stack* sp);

int Empty(Stack* sp);

int BracketMatch(Stack* sp, DataType* x);
