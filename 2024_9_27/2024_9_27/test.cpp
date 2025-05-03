#define _CRT_SECURE_NO_WARNINGS
#include"stack.h"

void test()
{
	Stack ps;
	Stack T;
	InitStack(&ps);
	InitStack(&T);
	for (char i = 'a'; i <= 'z'; i++)
	{
		Push(&ps, i);
	}
	DataType tem;
	while (ps.top > 0)
	{
		tem = Pop(&ps);
		if (tem == 't')
		{
			Push(&T, tem);
		}
		else if (tem == 's')
		{
			cout << tem;
			cout << Pop(&T);
		}
		else if(tem == 'k' || tem == 'c' || tem == 'a')
		{
			Push(&T, tem);
		}
		
	}
	while (T.top > 0)
	{
		cout << Pop(&T);
	}
	DistoryStack(&ps);
	DistoryStack(&T);
}
int main()
{
	test();
	return 0;
}