#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
using namespace std;

struct Hero
{
	string name;
	int age;
	string sex;
};

void BubbleSort(struct Hero* p, int len)
{
	for (int i = 0; i < len - 1; i++)
	{
		for (int j = 0; j < len - 1 - i; j++)
		{
			if ((p + j)->age > (p + j + 1)->age)
			{
				struct Hero tem = *(p + j + 1);
				*(p + j +1) = *(p + j);
				*(p + j) = tem;
			}
		}
	}
}

void Print(struct Hero* p, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout <<"������" << (p + i)->name 
			 <<"���䣺" << (p + i)->age
			 <<"�Ա�" << (p + i)->sex << endl;
	}
}

int main()
{
	struct Hero s[5] = {"�ŷ�",38,"��",
		                "����",23,"��",
		                "��ʩ",19,"Ů",
		                "����",20,"Ů",
	                    "�˽�",48,"��"};
	int len = sizeof(s) / sizeof(s[0]);
	cout << "����ǰ��" << endl;
	Print(s, len);

	BubbleSort(s,len);
	cout << "�����" << endl;

	Print(s, len);

	return 0;
}