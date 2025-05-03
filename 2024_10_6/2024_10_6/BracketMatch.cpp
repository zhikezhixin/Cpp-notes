#define _CRT_SECURE_NO_WARNINGS
#include "BracketMatch.h"

void InitStack(Stack* sp)//  ��ʼ��ջ
{
	sp->s = (DataType*)malloc(sizeof(DataType) * 4);
	if (sp->s == NULL)
	{
		cout << "malloc fail" << endl;
		exit(-1);
	}
	sp->capacity = 4;
	sp->top = 0;
}

void DestroyStack(Stack* sp)
{
	free(sp->s);
	sp->s = NULL;
	sp->capacity = sp->top = 0;
}

void EnterStack(Stack* sp, DataType x)//  ��ջ
{
	assert(sp);
	if (sp->capacity == sp->top)//  �ж�ջ��
	{
		DataType* tem = (DataType*)realloc(sp->s, sizeof(DataType) * sp->capacity * 2);//  ����
		if (tem == NULL)
		{
			cout << "realloc fail" << endl;
			exit(-1);
		}
		else
		{
			sp->s = tem;
			sp->capacity *= 2;
		}
		
	}
	sp->s[sp->top] = x;// ���ݺ���Ԫ����ջ
	sp->top++;
}

DataType ExitStack(Stack* sp)//  ��ջ
{
	assert(sp);
	assert(sp->top > 0);
	return sp->s[--sp->top];//  ջ��ָ���һͬʱ����ջ��Ԫ��
}

int Empty(Stack* sp)// �ж�ջ�Ƿ�Ϊ��
{
		return sp->top == 0;
}


int BracketMatch(Stack* sp, DataType* x) 
{
	assert(sp);
	while (*x) 
	{
		switch (*x) 
		{
		case '[':
		case '{':
		case '(':
			EnterStack(sp, *x);
			x++;
			break;
		case ']':
		case '}':
		case ')':
			if (Empty(sp)) 
			{
				return false;
			}
			DataType tem = ExitStack(sp);
			if ((*x == ']' && tem != '[')
				|| (*x == '}' && tem != '{')
				|| (*x == ')' && tem != '(')) 
			{
				return false;
			}
			else 
			{
				x++;
			}
			break;
		}
	}
	return Empty(sp);
}
