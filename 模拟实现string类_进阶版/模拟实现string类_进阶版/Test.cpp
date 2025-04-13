#include "string.h" // 展开后向上寻找所要函数  

int main()
{
	Zeker::string s1("hello");
	Zeker::string s2("word");
	Zeker::string s3(s1);

	s1 = s2;
	for (size_t i = 0;i < s1.size();i++)
	{
		cout << s1[i];
	}
	cout << endl;
	cout<< s1<<endl;
	cout << s3 << endl;

	cout << s3.insert(2, "xx") << endl;
	cout << s3.find( "xx") << endl;

	cout << int(s1 == s3) << endl;
	return 0;
}