#define _CRT_SECURE_NO_WARNINGS

//类中的构造和析构函数
#include <iostream>
using namespace std;

class Person
{
public:
	Person()// 成员属性赋值
	{
		cout<<"Person中的构造函数" << endl;
	}
	~Person()// 清理对象或变量
	{
		cout << "Person中的析构函数" << endl;

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