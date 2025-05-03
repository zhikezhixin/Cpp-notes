#pragma once
#include <iostream>
using namespace std;
#include <cassert>
#include<cstdlib>

typedef char DataType;

typedef struct Stack
{
	DataType* a;
	int top;
	int capacity;
}Stack;

void InitStack(Stack* ps);

void DistoryStack(Stack* ps);

void Push(Stack* ps,DataType x);

DataType Pop(Stack* ps);