#define _CRT_SECURE_NO_WARNINGS

// Guess Number
#include <iostream>
using namespace std;
#include <ctime>

void menu()
{
	cout << "��ѡ��" << endl;
	cout << "1. Enter" << endl;
	cout << "0.Exit" << endl;
}

void GuessNumber()
{
	srand((unsigned int)time(NULL));
	int min = 0;
	int max = 0;
	cout << "��ѡ������Ҫ�²������" << endl << "������������Сֵ:" ;
	cin >> min;
	cout << "�������������ֵ��";
	cin >> max;
	int num = min + (rand() % (max - min + 1));
	while (1)
	{
		int guess = 0;
		cout << "������²�����֣�";
		cin >> guess;
		if (guess<min||guess>max)
		{
			cout << "����������ѡ��������е�����";
			break;
		}
		else 
		{
			if (guess > num)
			{
				cout << "�´���" << endl;
			}
			else if (guess < num)
			{
				cout << "��С��" << endl;
			}
			else
			{
				cout << "�¶���" << endl;
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
			cout << "���˳���" << endl;
			goto end;
		default :
			cout << "��������ȷѡ�" << endl;
			break;
		}
		

	}
	end:
	
	return 0;
}











