#include <iostream>
#include <string>
using namespace std;


/*void Split_URL(const string& url)
{
	size_t u1 = url.find(':'); // find�����ִ����ַ���һ�γ��ֵ�λ���±�
	if (u1 != string::npos)
	{
		cout << url.substr(0, u1)<<endl;
	}

	size_t u2 = url.find('/', u1 + 3); // find�����ִ����ַ���һ�γ��ֵ�λ���±�
	if (u2 != string::npos)
	{
		cout << url.substr(u1 + 3, u2 - (u1 + 3)) << endl;
	}

	cout << url.substr(u2 + 1) << endl;
}*/

//�����ַ������һ�����ʵĳ��ȣ������Կո����
void Last_letter_lenth()
{
	string s;
	getline(cin, s); // getlineֻ���������вŽ�����cin�������л�ո�ͽ���
	size_t pos = s.rfind(' ');
	cout << s.size() - (pos + 1) << endl;
}

// ��֤���Ĵ�
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