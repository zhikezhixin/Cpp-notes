#define _CRT_SECURE_NO_WARNINGS

//#include <iostream>
//using namespace std;
//
//int* Pile_1()
//{
//	int*  local_p1 = new int(10);
//	cout <<"栈区中局部变量local_p1中存放在堆区的地址" << local_p1 << endl;
//	cout <<"存放在栈区局部变量local_p1的地址" << &local_p1 << endl;
//	cout <<"栈区局部变量local_p1指向的堆区地址中存放的数据" << *local_p1 << endl << endl;
//	return local_p1;
//}
//
//void Print_1()
//{
//	int* local_p1 = Pile_1();
//	cout << "栈区中局部变量local_p1中存放在堆区的地址" << local_p1 << endl;
//	cout << "存放在栈区局部变量local_p1的地址" << &local_p1 << endl;
//	cout << "栈区局部变量local_p1指向的堆区地址中存放的数据" << *local_p1 << endl << endl;
//	delete local_p1;
//}
//
//int main()
//{
//	Print_1();
//	return 0;
//}

//引用(给变量起别名)
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

//引用的实质
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

	cout << "a的地址是" << &a << endl;
	cout << "tem的地址是" << &tem << endl;
	cout << "Print(a)的地址是" << &Print(a) << endl;

	return 0;
}































