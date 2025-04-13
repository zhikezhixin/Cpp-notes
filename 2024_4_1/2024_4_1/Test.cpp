#include<iostream>
#include <string>
using namespace std;

/*void Test_string1()
{
	string s1;
	s1.resize(5);
	s1.resize(10, 'x');
}*/

// 仅仅反转字符串
/*class Solution
{
public:
	bool IsChar(char ch)
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'))
			return true;
		return false;
	}

	string reverseOnlyLetters(string s)
	{
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end)
		{
			while (begin < end&& IsChar(s[begin]) == false)
			{
				++begin;
			}
			while (begin < end && IsChar(s[end]) == false)
			{
				--end;
			}
			swap(s[begin], s[end]);
			++begin;
			--end;
		}
		return s;
	}
};*/


// 字符串中的第一个唯一字符
/*class Solution
{
public:
	int FirstUniqChar(string s)
	{
		int count[26] = { 0 };
		for (auto ch : s)
		{
			count[(ch - 'a')]++;
		}

		for (size_t i = 0; i < s.size(); ++i)
		{
			if (count[s[i] - 'a'] == 1)
				return i;
		}
		return -1;
	}
};*/

void Test_Find()
{
	string s1("string.cpp");
	string s2("string.cpp.zip");

	size_t pos1 = s1.find('.');
	if (pos1 != string::npos)
	{
		cout << s1.substr(pos1) << endl;
	}

	size_t pos2 = s2.rfind('.');
	if (pos2 != string::npos)
	{
		cout << s2.substr(pos2) << endl;
	}
}

int main()
{
	Test_Find();
	return 0;
}