#include <iostream>
#include <string>
using namespace std;

void Test_Iterator()
{
	string s1("abcdefg");

	//迭代器--> 所有容器都可以用迭代器访问
	string::iterator it1 = s1.begin();  //正向迭代器
	while (it1 != s1.end())  //s1.end()返回最后一个字符的下一个位置的地址
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

	for (auto ch : s1)  // auto自动判断变量类型
	{                   // 将s1中每一个元素赋给变量ch
		cout << ch;
	}
	cout << endl;

	string::reverse_iterator it2 = s1.rbegin();  //反向迭代器
	while (it2 != s1.rend())  //s1.rend()返回第一个字符位置
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

	for (auto ch : s1)  // auto自动判断变量类型
	{                   // 将s1中每一个元素赋给变量ch
		cout << ch;
	}
	cout << endl;
}

void translate_to_int(string& s)
{
	for (size_t i = 0; i < s.size(); ++i)
	{
		int num = s[i] - '0'; // 将字符转换为整型
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

	// 将字符串转化为整形
	string s("12345");
	translate_to_int(s);
	return 0;
}