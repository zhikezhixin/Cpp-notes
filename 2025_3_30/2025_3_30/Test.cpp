#include <iostream>
using namespace std;

/*namespace MyNamespace {
	int a = 1;
	int b = 2;
	int Add(int a, int b){
		return a + b;
	}
}

int main(){
	cout << MyNamespace::Add(MyNamespace::a, MyNamespace::b) << endl;
	return 0;
}*/

/*int Print(int a, int b = 0, int c = 1)
{
	cout << a << " " << b << " " << c << endl;
	return 0;
}

int main()
{
	Print(1);
	Print(1, 2);
	Print(1, 2, 3);
	return 0;
}*/

/*namespace A
{
	int Add(int a, int b, int c)
	{
		return a + b + c;
	}
	int Add(int a, int b)
	{
		return a + b;
	}
	double Add(double a, double b)
	{
		return a + b;
	}
}
int main()
{
	using namespace A;
	cout << Add(1, 2) << endl;
	cout << Add(1, 2, 3) << endl;
	cout << Add(1.1, 2.2) << endl;
	return 0;
}*/

//引用作为函数返回值
int& Add(int a, int b)
{
	int tmp = a + b;
	return tmp;
}
int main()
{
	int& tmp = Add(1,2);
	Add(3, 4);
	cout <<tmp<<endl;

	return 0;
}