#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//using namespace std;
//
//int* Pile_1()
//{
//	int*  local_p1 = new int(10);
//	cout <<"ջ���оֲ�����local_p1�д���ڶ����ĵ�ַ" << local_p1 << endl;
//	cout <<"�����ջ���ֲ�����local_p1�ĵ�ַ" << &local_p1 << endl;
//	cout <<"ջ���ֲ�����local_p1ָ��Ķ�����ַ�д�ŵ�����" << *local_p1 << endl << endl;
//	return local_p1;
//}
//
//void Print_1()
//{
//	int* local_p1 = Pile_1();
//	cout << "ջ���оֲ�����local_p1�д���ڶ����ĵ�ַ" << local_p1 << endl;
//	cout << "�����ջ���ֲ�����local_p1�ĵ�ַ" << &local_p1 << endl;
//	cout << "ջ���ֲ�����local_p1ָ��Ķ�����ַ�д�ŵ�����" << *local_p1 << endl << endl;
//	delete local_p1;
//}
//
//int main()
//{
//	Print_1();
//	return 0;
//}

//����(�����������)
//#include <iostream>
//using namespace std;
//
//void Swap(int& a, int& b)
//{
//	int tem = a;
//	a = b;
//	b = tem;
//}
//
//int& Print(int C)
//{
//	 static int c = 100;
//	cout << "c = " << c << endl;
//
//	return c;
//}
//
//int main()
//{
//	int a = 10;
//	int b = 20;
//	Swap(a, b);
//	cout << "a = " << a << endl;
//	cout << "b = " << b << endl;
//
//	int C = 0;
//
//	int& c = Print(C);
//	cout << "c = " << c << endl;
//
//	Print(C) = 20;
//	cout << "c = " << c << endl;
//
//
//	return 0;
//}

//���õ�ʵ��
#include <iostream>
using namespace std;

int& Print(int& a)
{
	a = 100;
	return a;
}

int main()
{
	int a = 10;
	int &tem = Print(a);

	cout << "a�ĵ�ַ��" << &a << endl;
	cout << "tem�ĵ�ַ��" << &tem << endl;
	cout << "Print(a)�ĵ�ַ��" << &Print(a) << endl;

	return 0;
}































