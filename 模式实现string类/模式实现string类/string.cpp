#include "string.h"
//只要函数是类的成员函数（无论定义在头文件还是实现文件中），它们都可以访问类的私有成员
size_t Zeker::string::size()
{
	return strlen(_str);
}


char& Zeker::string::operator[](size_t i)
{
	return _str[i];
}

Zeker::string::string(const char* str)
	:_str(new char[strlen(str) + 1])
{
	strcpy(_str, str);
}

Zeker::string::~string()
{
	delete[] _str;
	_str = nullptr;
}

const char* Zeker::string::c_str()const
{
	return _str;
}

Zeker::string::string(const string& s)
	:_str(new char[strlen(s._str) + 1])
{
	strcpy(_str, s._str);
}

Zeker::string& Zeker::string::operator=(const string& s)
{
	if (&s != this)
	{
		char* tmp = new char[strlen(s._str) + 1];
		strcpy(tmp, s._str);
		delete[] _str;
		_str = tmp;
	}
	return *this;
}
  