#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef char DataType;

typedef struct Stack
{
	DataType* s;   // 栈数组
	int top;       // 栈顶指针
	int capacity;  // 栈容量
} Stack;

void InitStack(Stack* sp) // 初始化栈
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

void DestroyStack(Stack* sp) // 销毁栈
{
	free(sp->s);
	sp->s = NULL;
	sp->capacity = sp->top = 0;
}

void EnterStack(Stack* sp, DataType x) // 入栈
{
	assert(sp);
	if (sp->capacity == sp->top) // 判断栈满
	{
		DataType* tem = (DataType*)realloc(sp->s, sizeof(DataType) * sp->capacity * 2); // 扩容
		if (tem == NULL)
		{
			printf("realloc fail\n");
			exit(-1);
		}
		sp->s = tem;
		sp->capacity *= 2;
	}
	sp->s[sp->top] = x; // 新元素入栈
	sp->top++;
}

DataType ExitStack(Stack* sp) // 出栈
{
	assert(sp);
	assert(sp->top > 0); // 确保栈不为空
	sp->top--;           // 栈顶指针减一
	return sp->s[sp->top]; // 返回栈顶元素
}

int Empty(Stack* sp) // 判断栈是否为空
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
			EnterStack(sp, *x); // 左括号入栈
			break;
		case ']':
		case '}':
		case ')':
			if (Empty(sp)) // 判断栈是否为空
			{
				return 0; // 栈为空，右括号没有匹配的左括号
			}
			DataType tem = ExitStack(sp); // 出栈，取出栈顶元素
			if ((*x == ']' && tem != '[') ||
				(*x == '}' && tem != '{') ||
				(*x == ')' && tem != '('))
			{
				return 0; // 左右括号不匹配
			}
			break;
		}
		x++; // 处理下一个字符
	}
	return Empty(sp); // 最终判断栈是否为空
}


int main()
{
	Stack s;
	InitStack(&s);

	DataType x[100];
	printf("Please input the brackets: ");
	fgets(x, 100, stdin); // 使用 fgets 读取输入

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


