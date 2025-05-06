#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;


/*
class Person
{
public:
	virtual void Speak() = 0;
};

class Chinese : public Person
{
public:
	virtual void Speak()
	{
		cout << "Chinese" << endl;
	}
};

class American : public Person
{
public:
	virtual void Speak()
	{
		cout << "American" << endl;
	}
};

void test1()
{
	Person* p = new Chinese;
	p->Speak();
}
*/

/*
// ���������ַ��� word1 �� word2 ������� word1 ��ʼ��ͨ�����������ĸ���ϲ��ַ�����
// ���һ���ַ�������һ���ַ��������ͽ����������ĸ׷�ӵ��ϲ����ַ�����ĩβ�����غϲ�����ַ�����
class Solution {  
public:  
    string mergeAlternately(string word1, string word2) {  
		int i = 0, j = 0;
		string result;
		while (i != word1.size() && j != word2.size())
		{
			result += word1[i++];
			result += word2[j++];

		}
		while (i != word1.size())
		{
			result += word1[i++];
		 }
		while (j != word2.size())
		{
			result += word2[j++];
		}
		return result;
    }  
};  

    
//���������ַ���s��t����ֻ����Сд��ĸ,�ַ��� t ���ַ���s������ţ�Ȼ�������λ�����һ����ĸ��
//���ҳ��� t �б���ӵ���ĸ��a-z:97-122
class Solution {
public:
	char findTheDifference(string s, string t)
	{
		int arr[122] = { 0 };

		for (char ch : s)
		{
			arr[(int)ch] = ch;
		}
		for (char ch : t)
		{
			arr[(int)ch] = ch;
		}
		for (int i = 97; i < 122;i++)
		{
			if (arr[i] % 2 == 1)
			{
				return (char)i;
			}
		}
	}
};
*/

/*
//���������ַ��� haystack �� needle �������� haystack �ַ������ҳ�needle �ַ���
//�ĵ�һ��ƥ������±꣨�±�� 0 ��ʼ������� needle ���� haystack ��һ���֣��򷵻�  -1 ��
class Solution {
public:
	int strStr(string haystack, string needle) {
		const char* str =  strstr(haystack.c_str(), needle.c_str());
		if (str == nullptr)
		{
			return -1;
		}
		return haystack.c_str() - str;
	}
};

void test2()
{
	Solution s;
	s.strStr("hello", "ll");
}
*/

//���������ַ��� s �� t ����дһ���������ж� t �Ƿ��� s �� ��ĸ��λ�ʡ�
class Solution 
{
public:
	bool isAnagram(string s, string t)
	{
		sort(s.begin(), s.end());
		sort(t.begin(), t.end());
		return s == t;
	}
	
};

//����һ���ǿյ��ַ��� s ������Ƿ����ͨ��������һ���Ӵ��ظ���ι��ɡ�
class Solution {
public:
	bool repeatedSubstringPattern(string s) 
	{

	}
};

int main()
{
	//test1();
	//test2();
	system("pause");
	return 0;
}