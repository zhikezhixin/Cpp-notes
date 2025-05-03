#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char DataType;

typedef struct Stack
{
	DataType* s;   // ջ����
	int top;       // ջ��ָ��
	int capacity;  // ջ����
} Stack;

void InitStack(Stack* sp) // ��ʼ��ջ
{
	sp->s = (DataType*)malloc(sizeof(DataType) * 4);
	if (sp->s == NULL)
	{
		printf("malloc fail\n");
		exit(-1);
	}
	sp->capacity = 4;
	sp->top = 0;
}

void DestroyStack(Stack* sp) // ����ջ
{
	free(sp->s);
	sp->s = NULL;
	sp->capacity = sp->top = 0;
}

void EnterStack(Stack* sp, DataType x) // ��ջ
{
	assert(sp);
	if (sp->capacity == sp->top) // �ж�ջ��
	{
		DataType* tem = (DataType*)realloc(sp->s, sizeof(DataType) * sp->capacity * 2); // ����
		if (tem == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		sp->s = tem;
		sp->capacity *= 2;
	}
	sp->s[sp->top] = x; // ��Ԫ����ջ
	sp->top++;
}

DataType ExitStack(Stack* sp) // ��ջ
{
	assert(sp);
	assert(sp->top > 0); // ȷ��ջ��Ϊ��
	sp->top--;           // ջ��ָ���һ
	return sp->s[sp->top]; // ����ջ��Ԫ��
}

int Empty(Stack* sp) // �ж�ջ�Ƿ�Ϊ��
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
			EnterStack(sp, *x); // ��������ջ
			break;
		case ']':
		case '}':
		case ')':
			if (Empty(sp)) // �ж�ջ�Ƿ�Ϊ��
			{
				return 0; // ջΪ�գ�������û��ƥ���������
			}
			DataType tem = ExitStack(sp); // ��ջ��ȡ��ջ��Ԫ��
			if ((*x == ']' && tem != '[') ||
				(*x == '}' && tem != '{') ||
				(*x == ')' && tem != '('))
			{
				return 0; // �������Ų�ƥ��
			}
			break;
		}
		x++; // ������һ���ַ�
	}
	return Empty(sp); // �����ж�ջ�Ƿ�Ϊ��
}


int main()
{
	Stack s;
	InitStack(&s);

	DataType x[100];
	printf("Please input the brackets: ");
	fgets(x, 100, stdin); // ʹ�� fgets ��ȡ����

	int tem = BracketMatch(&s, x);
	if (tem)
	{
		printf("Match success\n");
	}
	else
	{
		printf("Match fail\n");
	}

	DestroyStack(&s);
	return 0;
}


