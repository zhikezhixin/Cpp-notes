#define _CRT_SECURE_NO_WARNINGS


//使用冒泡排序对数组中元素进行升序排序
/*#include <iostream>
#include <ctime>
using namespace std;

void CreatArray(int* parr)
{
	srand((unsigned int)time(NULL));
	int i = 0;
	for (i = 0; i < 10; i++)
	{
		*(parr+i) = rand() % 10;
	}
	cout << "升序前：";
	for (i = 0; i < 10; i++)
	{
		cout << *(parr + i) << "  ";
	}
}

void BubbleSort(int* parr, int len)
{
	int i = 0;
	int j = 0;
	for (i = 0; i < len - 1; i++)
	{
		for (j = 0; j < len - 1 - i; j++)
		{
			if(*(parr+j)>*(parr+j+1))
			{
				int tem = *(parr + j);
				*(parr + j) = *(parr + j + 1);
				*(parr + j + 1) = tem;
			}
		}
	}
}

int main()
{
	int arr[10] = { 0 };
	CreatArray(arr);
	int len = sizeof(arr) / sizeof(arr[0]);
	BubbleSort(arr,len);

	cout << "升序后：";
	for (int i = 0; i < 10; i++)
	{
		cout << *(arr + i) << "  ";
	}

	return 0;
}*/


//一个老师五名学生
/*#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Student
{
	string sName;
	int score;
};

struct Teacher
{
	string tName;
	struct Student s[5];
};

void initialize(struct Teacher* t, int len)
{
	string NameSeed = "ABCDE";
	srand((unsigned int)time(NULL));
	for (int i = 0; i < len; i++)
	{
		(t + i)->tName = "Teacher_";
		(t + i)->tName += NameSeed[i];
		for (int j = 0; j < 5; j++)
		{
			((t + i)->s + j)->sName = "Student_";
			((t + i)->s + j)->sName += NameSeed[j];
			((t + i)->s + j)->score = rand() % 41 + 60;
		}
	}
}

void Print(struct Teacher* t, int len)
{
	for (int i = 0; i < len; i++)
	{
		cout << (t + i)->tName << ":" << endl;
		for (int j = 0; j < 5; j++)
		{
			cout <<"\t" << ((t + i)->s + j)->sName << "的分数是：" << ((t + i)->s + j)->score << endl;
		}
	}
}

int main()
{
	struct Teacher t[3];
	int len = sizeof(t) / sizeof(t[0]);
	initialize(t, len);
	Print(t, len);


	return 0;
}*/

