#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;

#define MaxLen 20

typedef char DataType;
typedef struct LinkNode
{
	DataType data;
	int next;
}LinkNode;

typedef struct StaticLinkList
{
	LinkNode a[MaxLen];
	int head = 0;
}SLL;

void Init(SLL* ps) 
{
	ps->head = 0;
	ps->a->next = 0;
}

void Push(SLL* ps,DataType x)
{
	if (ps->a->next == MaxLen)
	{
		cout << "full" << endl;
		return;
	}
	ps->a[ps->a->next] = x;
	ps->a->next++;
}

void Print(SLL* ps)
{
	for (int x = ps->head; x <= ps->a->next; x++)
	{
		cout << ps->a->data << " ";
	}
}

int main()
{
	SLL s;
	Init(&s);

	for (int x = 'A'; x <= 'I'; x++)
	{
		Push(&s,x);
	}
	Print(&s);

	return 0;
}