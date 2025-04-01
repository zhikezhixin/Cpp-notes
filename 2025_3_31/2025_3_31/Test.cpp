#include <iostream>
#include <string>
using namespace std;

void Test_Iterator()
{
	string s1("abcdefg");

	//������--> ���������������õ���������
	string::iterator it1 = s1.begin();  //���������
	while (it1 != s1.end())  //s1.end()�������һ���ַ�����һ��λ�õĵ�ַ
	{
		*it1 -= 1;
		it1++;
	}
	it1 = s1.begin();
	while (it1 != s1.end())
	{
		cout << *it1;
		it1++;
	}
	cout << endl;

	for (auto ch : s1)  // auto�Զ��жϱ�������
	{                   // ��s1��ÿһ��Ԫ�ظ�������ch
		cout << ch;
	}
	cout << endl;

	string::reverse_iterator it2 = s1.rbegin();  //���������
	while (it2 != s1.rend())  //s1.rend()���ص�һ���ַ�λ��
	{
		*it2 -= 1;
		it2++;
	}
	it2 = s1.rbegin();
	while (it2 != s1.rend())
	{
		cout << *it2;
		it2++;
	}
	cout << endl;

	for (auto ch : s1)  // auto�Զ��жϱ�������
	{                   // ��s1��ÿһ��Ԫ�ظ�������ch
		cout << ch;
	}
	cout << endl;
}

void translate_to_int(string& s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		int num = s[i] - '0'; // ���ַ�ת��Ϊ����
		cout << num;
	}
}

int main()
{
	/*string s1("hello ");
	string s2("world");
	s1 += s2;
	cout << s1 << endl;

	for (size_t i = 0; i < s1.size(); i++)
	{
		s1[i] += 1;
	}
	cout << s1 << endl;*/

	//Test_Iterator();

	// ���ַ���ת��Ϊ����
	string s("12345");
	translate_to_int(s);
	return 0;
}