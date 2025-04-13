#include "string.h"

int main()
{
	Zeker::string s1("hello");
	Zeker::string s2(s1);
	for (size_t i = 0; i < strlen(s1.c_str());i++) 
	{
		cout << s1.c_str()[i];
	}
	cout << s2.c_str() << endl;
	return 0;
}