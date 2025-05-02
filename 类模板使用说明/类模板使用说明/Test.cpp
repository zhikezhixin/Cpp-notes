#include "template.h"

void test_1()
{
	int a = 2, b = 4;
	cout << Add(a, b) << endl;  // 函数模板通常可以自动推到类型

	example<double> e; // 在调用类时，需要在类名后加上<>，并给出指定的数据类型
}
int main()
{
	//test_1();
   return 0;
}