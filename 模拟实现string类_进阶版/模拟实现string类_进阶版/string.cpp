#include "string.h"

Zeker::string::string(const char* str)
	:_str(nullptr)
{
	_size = strlen(str);
	_capacity = _size;
	_str = new char[_capacity + 1];
	strcpy(_str, str);
}

Zeker::string::string(const string& str)
{
	_size = strlen(str.c_str());
	_capacity = _size;
	_str = new char[_capacity + 1];
	strcpy(_str, str.c_str());
}

Zeker::string::~string()
{
	delete[] _str;
	_str = nullptr;
	_size = _capacity = 0;
}

 size_t Zeker::string::size()const
{
	 return _size;
}

 size_t Zeker::string::capacity()const
 {
	 return _capacity;
 }

 char& Zeker::string::operator[](size_t i)
 {
	 assert(i < _size);
	 return _str[i];
 }
 const char& Zeker::string::operator[](size_t i)const // 第一个const表示该返回值是只读的不可修改
 {                                                    // 第二个const表示该成员函数不能修改成员变量的值
	 assert(i < _size);
	 return _str[i];
 }

 const char* Zeker::string::c_str()const
 {
	 return _str;
 }

 ostream& Zeker::operator<< (ostream& out, const string& s)
 {
	 for (size_t i = 0; i < s.size(); i++)
	 {
		 out << s[i];
	 }
	 return out;
 }

 Zeker::string& Zeker::string::operator= (const string& str)
 {
	 if (this != &str)
	 {
		 char* tmp = new char[str._capacity + 1];
		 strcpy(tmp, str._str);
		 delete[] _str;
		 _str = tmp;
		 _size = str._size;
		 _capacity = str._capacity;
	 }
	return *this;
 }

 bool Zeker::string::operator==(const char* str)
 {
	 return strcmp(_str, str) == 0;
 }

 bool Zeker::string::operator==(const string& str)
 {
	 return strcmp(_str, str.c_str()) == 0;
 }

 bool Zeker::string::operator!=(const char* str)
 {
	 return !(_str == str);
 }

 bool Zeker::string::operator!=(const string& str)
 {
	 return !(_str == str.c_str());
 }

 bool Zeker::string::operator<=(const string& str)
 {
	 return *this < str || *this == str;
 }

 bool Zeker::string::operator>=(const string& str)
 {
	 return *this > str || *this == str;
 }

 bool Zeker::string::operator<(const string& str)
 {
	 return  strcmp(_str, str.c_str()) < 0;
 }

 bool Zeker::string::operator>(const string& str)
 {
	 return  strcmp(_str, str.c_str()) > 0;
 }

 void Zeker::string::dilatation(size_t n)
 {
	 char* newstr = new char[n + 1];
	 strcpy(newstr, _str);
	 delete[] _str;
	 _str = newstr;
	 _capacity = n;
 }


 void Zeker::string::append(const char* str)
 {
	 size_t len = strlen(str);
	 if (len + _size > _capacity)
	 {  //  增容过程
		 size_t newcapacity = len + _size;
		 dilatation(newcapacity);
	 }
	 strcpy(_str + _size, str);
	 _size += len;
 }

 void Zeker::string::push_back(char ch)
 {
	 if ( _size == _capacity)
	 {  //  增容过程
		 size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
		 dilatation(newcapacity);
	 }
	 _str[_size] = ch;
	 _size ++;
 }

 Zeker::string& Zeker::string::operator+= (const string& str)
 {
	 append(str.c_str());
	 return *this;
 }

 Zeker::string& Zeker::string::operator+= (char ch)
 {
	 push_back(ch);
	 return *this;
 }

 Zeker::string& Zeker::string::operator+= (const char* str)
 {
	 append(str);
	 return *this;
 }

 istream& Zeker::operator>>(istream& in, string& s)
 {
	 while (1)
	 {
		 char ch;
		 ch = in.get();
		 if (ch == ' ' || ch == '\n')
		 {
			 break;
		 }
		 else
		 {
			 s += ch;
		 }
	 }
	 return in;
 }

 Zeker::string& Zeker::string::insert(size_t pos, char ch)
 {
	 assert(pos <= _size);
	 if (_size == _capacity)
	 {
		 size_t newcapacity = _capacity == 0 ? 2 : _capacity * 2;
		 dilatation(newcapacity);
	 }
	 
	 int end = _size;
	 while (end >= pos) // 数据后移的同时向前查找pos位置
	 {
		 _str[end + 1] = _str[end];
		 end--;
	 }
	 _str[pos] = ch;
	 ++_size;
	 return *this;
 }

 Zeker::string& Zeker::string::insert(size_t pos, const char* str)
 {
	 size_t len = strlen(str);
	 if (len + _size > _capacity)
	 {  //  增容过程
		 dilatation(len + _size);
	 }
	 int end = _size;
	 while (end >= pos)
	 {
		 _str[end + len] = _str[end];
		 end--;
	 }
	 strncpy(_str + pos, str, len);
	 _size += len;
	 return *this;
 }

 void Zeker::string::resize(size_t n, char ch)
 {
	 if (n < _size)
	 {
		 _str[n] = '\0';
		 _size = n;
	 }
	 else
	 {
		 if (n > _capacity)
		 {
			 dilatation(n);
		 }
		 for (size_t i = _size; i < n; i++)
		 {
			 _str[i] = ch;
		 }
	 }
	 _size = n;
	 _str[_size] = '\0';
 }

 void Zeker::string::erase(size_t pos, size_t len)
 {
	 if (len > _size - pos)
	 {
		 _str[pos] = '\0';
		 _size = pos;
	 }
	 else
	 {
		 size_t i = pos + len;
		 while (i <= _size)
		 {
			 _str[i - len] = _str[i]; // 数据直接迁移len个单位
			 ++i;
		 }
		 _size -= len;
	 }
 }

 size_t Zeker::string::find(char ch,size_t pos)
 {
	 for (size_t i = pos; i < _size; i++)
	 {
		 if (_str[i] == ch)
			 return i;
	 }
	 return npos;
 }
 size_t Zeker::string::find(const char* str, size_t pos)
 {
	 char* p = strstr(_str + pos, str);
	 if (p == nullptr)
		 return npos;
	 return p - _str;
 }

