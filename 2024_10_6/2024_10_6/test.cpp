#define _CRT_SECURE_NO_WARNINGS
#include "BracketMatch.h"

int main() 
{
	Stack s;
	InitStack(&s);

	DataType x[100]; // ���������С����Ӧ����
	cout << "please input the brackets: ";
	cin.getline(x, 100);

	int tem = BracketMatch(&s, x);
	if (tem) 
	{
		cout << "match success" << endl;
	}
	else 
	{
		cout << "match fail" << endl;
	}

	DestroyStack(&s);
	return 0;
}

