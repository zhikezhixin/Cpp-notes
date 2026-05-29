#include <iostream>
using namespace std;


//lambda表达式（定义在函数中的匿名函数）格式：[捕捉列表](参数){函数体}
void test1()
{
	int a = 3, b = 4; 

	auto add1 = [](int x1, int x2) { return x1 + x2;};
	add1(a, b); //直接传参给lambda表达式

	auto add2 = [a, b]() {return a + b; };
	add2(); //直接捕捉

	auto add3 = [=]() {return a + b; };
	add3(); //捕捉父作用域内所有值传递的变量

	auto swap1 = [&a, &b]() {
		int x = a;
		a = b;
		b = a;
		};
	swap1();
}

int main()
{
	test1();
	return 0;
}