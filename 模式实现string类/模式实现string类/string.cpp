#include "string.h"
//ֻҪ��������ĳ�Ա���������۶�����ͷ�ļ�����ʵ���ļ��У������Ƕ����Է������˽�г�Ա
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
  