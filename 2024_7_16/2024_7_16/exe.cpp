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
		cout <<"姓名：" << (p + i)->name 
			 <<"年龄：" << (p + i)->age
			 <<"性别：" << (p + i)->sex << endl;
	}
}

int main()
{
	struct Hero s[5] = {"张飞",38,"男",
		                "李逵",23,"男",
		                "西施",19,"女",
		                "貂蝉",20,"女",
	                    "八戒",48,"男"};
	int len = sizeof(s) / sizeof(s[0]);
	cout << "排序前：" << endl;
	Print(s, len);

	BubbleSort(s,len);
	cout << "排序后：" << endl;

	Print(s, len);

	return 0;
}