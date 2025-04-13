#include <iostream>
#include <string>
using namespace std;


/*void Split_URL(const string& url)
{
	size_t u1 = url.find(':'); // find返回字串或字符第一次出现的位置下标
	if (u1 != string::npos)
	{
		cout << url.substr(0, u1)<<endl;
	}

	size_t u2 = url.find('/', u1 + 3); // find返回字串或字符第一次出现的位置下标
	if (u2 != string::npos)
	{
		cout << url.substr(u1 + 3, u2 - (u1 + 3)) << endl;
	}

	cout << url.substr(u2 + 1) << endl;
}*/

//计算字符串最后一个单词的长度，单词以空格隔开
void Last_letter_lenth()
{
	string s;
	getline(cin, s); // getline只有遇到换行才结束，cin遇到换行或空格就结束
	size_t pos = s.rfind(' ');
	cout << s.size() - (pos + 1) << endl;
}

// 验证回文串
/*class solution
{
public:
	bool is_Char_or_Number(char ch)
	{
		if ((ch >= 'a' && ch <= 'z') || (ch >= '0' && ch <= '9'))
			return true;
		return false;
	}
	bool ispalindrome(string s)
	{
		for (auto& ch : s)
		{
			if (ch >= 'A' && ch <= 'Z')
				ch += 32;
		}
		int begin = 0;
		int end = s.size() - 1;
		while (begin < end)
		{
			while ((begin < end) && is_Char_or_Number(begin))
				++begin;
			while ((begin < end) && is_Char_or_Number(end))
				--end;
			if (s[begin] != s[end])
				return false;
		}
		return true;
	}
};*/


int main()
{
	//Split_URL("https://support.lenovo.com/us/zc/");
	//Last_letter_lenth();
	return 0;
}