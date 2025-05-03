#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

//分装一个立方体的类

class Cube
{
private:
	int L;
	int W;
	int H;

public:
	void InputLong(int Long)
	{
		L = Long;
		
	}
	void InputWide(int Wide)
	{
		W = Wide;
	}
	void InputHigh(int High)
	{
		H = High;
	}
	int OutputLong()
	{
		return L;

	}
	int OutputWide()
	{
		return W;
	}
	int OutputHigh()
	{
		return H;
	}

	int CalculateArea()
	{
		return (2 * (L * W + L * H + W * H));
	}
	int CalculateVolum()
	{
		return (L * W * H);
	}
	bool LocalCompare(Cube& c2)
	{
		if (L == c2.OutputLong() && W == c2.OutputWide() && H == c2.OutputHigh())
		{
			return true;
		}
		return false;
	}
};

int main()
{
	Cube c1;
	int Long_1, Wide_1, High_1;
	cout << "请输入立方体1的长，宽，高：" << endl;
	cin >> Long_1 >> Wide_1 >> High_1;
	
	c1.InputLong(Long_1);
	c1.InputWide(Wide_1);
	c1.InputHigh(High_1);

	cout << "您输入的长，宽，高分别是：" << c1.OutputLong() << ","
		<< c1.OutputWide() << ","
		<< c1.OutputHigh() << endl;

	cout << "立方体1的面积是" << c1.CalculateArea() << endl
		 << "方体1的体积是" << c1.CalculateVolum() << endl;


	Cube c2;
	int Long_2, Wide_2, High_2;
	cout << "请输入立方体2的长，宽，高：" << endl;
	cin >> Long_2 >> Wide_2 >> High_2;
	
	c2.InputLong(Long_2);
	c2.InputWide(Wide_2);
	c2.InputHigh(High_2);
	cout << "您输入的长，宽，高分别是：" << c2.OutputLong() << ","
		<< c2.OutputWide() << ","
		<< c2.OutputHigh() << endl;

	cout << "立方体2的面积是" << c2.CalculateArea() << endl
		<< "方体2的体积是" << c2.CalculateVolum() << endl;

	int tem1 = c1.LocalCompare(c2);
	if (tem1)
	{
		cout << "立方体1和2相等" << endl;
	}
	else
	{
		cout << "立方体1和2不相等" << endl;
	}

	return 0;
}