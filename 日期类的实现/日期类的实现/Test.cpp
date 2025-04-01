#include "日期计算器.h"

Date d;
static int day;
void Case1()
{
	cout << "您选择的是日期加法" << endl;
	d.InputeDate();
	cout << "请输入您要加的天数：";
	cin >> day;
	d + day;
	cout << "计算后的日期为：" ;
	d.Show();
	cout << endl;
}

void Case2()
{
	cout << "您选择的是日期减法" << endl;
	d.InputeDate();
	cout << "请输入您要减的天数：";
	cin >> day;
	d - day;
	cout << "计算后的日期为：";
	d.Show();
	cout << endl;

}

void Case3()
{
	cout << "您选择的是日期比较" << endl;
	cout << "请输入第一个日期：";
	d.InputeDate();
	cout << "请输入第二个日期" << endl;
	Date temp;
	temp.InputeDate();
	d.Show();
	char c = d.DateCompare(temp);
	cout << c;
	temp.Show();
	cout << endl;

}

void Case4()
{
	cout << "您选择的是计算日期之差" << endl;
	cout << "请输入第一个日期" << endl;
	d.InputeDate();
	cout << "请输入第二个日期" << endl;
	Date temp;
	temp.InputeDate();
	d.Show(); cout << "和"; temp.Show();
	cout << "相差：" << d.DateSub(temp) << " 天" << endl;
}

int main()
{
	int input = 0;
	
	do 
	{
		
		Menu();
		cin >> input;
		
		switch (input)
		{
		case 1:
			Case1();
			break;
		case 2:
			Case2();
			break;
		case 3:
			Case3();
			break;
		case 4:
			Case4();
			break;
		case 0:
			break;
		default:
			cout << "输入有误，请重新输入" << endl;
			break;
		}
	} while (input);

	system("pause");
	return 0;
}