#define _CRT_SECURE_NO_WARNINGS

// Guess Number
#include <iostream>
using namespace std;
#include <ctime>

void menu()
{
	cout << "请选择：" << endl;
	cout << "1. Enter" << endl;
	cout << "0.Exit" << endl;
}

void GuessNumber()
{
	srand((unsigned int)time(NULL));
	int min = 0;
	int max = 0;
	cout << "请选择你想要猜测的区间" << endl << "请输入区间最小值:" ;
	cin >> min;
	cout << "请输入区间最大值：";
	cin >> max;
	int num = min + (rand() % (max - min + 1));
	while (1)
	{
		int guess = 0;
		cout << "请输入猜测的数字：";
		cin >> guess;
		if (guess<min||guess>max)
		{
			cout << "请输入您所选择的区间中的数字";
			break;
		}
		else 
		{
			if (guess > num)
			{
				cout << "猜大了" << endl;
			}
			else if (guess < num)
			{
				cout << "猜小了" << endl;
			}
			else
			{
				cout << "猜对了" << endl;
				break;
			}
		}
		
	}
}
int main()
{
	int input = 0;
	while (1)
	{
		menu();
		cin >> input;
		switch (input)
		{
		case 1:
			GuessNumber();
			break;
		case 0:
			cout << "已退出！" << endl;
			goto end;
		default :
			cout << "请输入正确选项！" << endl;
			break;
		}
		

	}
	end:
	
	return 0;
}











