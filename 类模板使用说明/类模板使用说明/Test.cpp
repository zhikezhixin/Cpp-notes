#include "template.h"

void test_1()
{
	int a = 2, b = 4;
	cout << Add(a, b) << endl;  // ����ģ��ͨ�������Զ��Ƶ�����

	example<double> e; // �ڵ�����ʱ����Ҫ�����������<>��������ָ������������
}
int main()
{
	//test_1();
   return 0;
}