#include "���ڼ�����.h"

Date d;
static int day;
void Case1()
{
	cout << "��ѡ��������ڼӷ�" << endl;
	d.InputeDate();
	cout << "��������Ҫ�ӵ�������";
	cin >> day;
	d + day;
	cout << "����������Ϊ��" ;
	d.Show();
	cout << endl;
}

void Case2()
{
	cout << "��ѡ��������ڼ���" << endl;
	d.InputeDate();
	cout << "��������Ҫ����������";
	cin >> day;
	d - day;
	cout << "����������Ϊ��";
	d.Show();
	cout << endl;

}

void Case3()
{
	cout << "��ѡ��������ڱȽ�" << endl;
	cout << "�������һ�����ڣ�";
	d.InputeDate();
	cout << "������ڶ�������" << endl;
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
	cout << "��ѡ����Ǽ�������֮��" << endl;
	cout << "�������һ������" << endl;
	d.InputeDate();
	cout << "������ڶ�������" << endl;
	Date temp;
	temp.InputeDate();
	d.Show(); cout << "��"; temp.Show();
	cout << "��" << d.DateSub(temp) << " ��" << endl;
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
			cout << "������������������" << endl;
			break;
		}
	} while (input);

	system("pause");
	return 0;
}