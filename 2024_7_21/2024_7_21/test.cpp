#define _CRT_SECURE_NO_WARNINGS

//���еĹ������������
#include <iostream>
using namespace std;

class Person
{
public:
	Person()// ��Ա���Ը�ֵ
	{
		cout<<"Person�еĹ��캯��" << endl;
	}
	~Person()// �����������
	{
		cout << "Person�е���������" << endl;

	}
};

void test()
{
	Person p;
}

int main()
{
	//test();
	Person p;
	return 0;
}