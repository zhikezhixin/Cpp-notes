#define _CRT_SECURE_NO_WARNINGS

//������(7)
/*#include <iostream>
using namespace std; 

int main()
{
	int num = 0;
	for (num = 0;num <= 100; num++)
	{
		if (num % 10 == 7|| (num / 10) % 10 == 7 || num % 7 == 0)
		{
			cout << "������" << endl;
		}
		else
		{
			cout << num << endl;
		}
	}
	return 0;
}*/


//�žų˷���
/*#include <iostream>
using namespace std;

int main()
{
	for (int i = 1; i < 10; i++)
	{
		for (int j = 1; j <= i; j++)
		{
			cout << i << "*" << j << "=" << i * j << "\t";
		}
	 	cout << endl;
	}
	return 0;
}*/


//���������ֵ
/*#include <iostream>
#include <ctime>
using namespace std;

int main()
{
	srand((unsigned int)time(NULL));
	int i = 0;
	int max = 0;
	int arr[5] = { rand() % 100,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100 };
	for (i = 0; i < 5; i++)
	{
		cout<<"arr["<<i<<"]=" << arr[i] << " ";
	 }
	cout << endl;
	for (i = 0; i < 5; i++)
	{
		if (arr[i]>max)
		{
			max = arr[i];
		}
	}
	cout << "���������ֵ��:" << max << " ";
	return 0;
}*/


//����Ԫ������
/*#include <iostream>
using namespace std;
#include <ctime>

int main()
{
	srand((unsigned int)time(NULL));
	int arr1[] = {rand()%100,rand() % 100 ,rand() % 100 ,rand() % 100 ,rand() % 100};
	int left = 0;
	int len = sizeof(arr1) / sizeof(arr1[0]);
	int right = len - 1;
	
	cout << "��������ǰ";
	for(int j = 0;j <=  right; j++)
	{
		cout << "arr1[" << j << "]=" << arr1[j]<<"  ";
	}
	cout << endl;
	for (; left < right; left++, right--)
	{
		int tem = arr1[right];
		arr1[right] = arr1[left];
		arr1[left] = tem;
	}
	cout << "�������ú�";
	for (int j = 0; j <= len - 1; j++)
	{
		cout << "arr1[" << j << "]=" << arr1[j] << "  ";
	}
	cout << endl;
	return 0;
}*/








