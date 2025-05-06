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
// 给你两个字符串 word1 和 word2 。请你从 word1 开始，通过交替添加字母来合并字符串。
// 如果一个字符串比另一个字符串长，就将多出来的字母追加到合并后字符串的末尾。返回合并后的字符串。
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

    
//给定两个字符串s和t它们只包含小写字母,字符串 t 由字符串s随机重排，然后在随机位置添加一个字母。
//请找出在 t 中被添加的字母。a-z:97-122
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
//给你两个字符串 haystack 和 needle ，请你在 haystack 字符串中找出needle 字符串
//的第一个匹配项的下标（下标从 0 开始）。如果 needle 不是 haystack 的一部分，则返回  -1 。
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

//给定两个字符串 s 和 t ，编写一个函数来判断 t 是否是 s 的 字母异位词。
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

//给定一个非空的字符串 s ，检查是否可以通过由它的一个子串重复多次构成。
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