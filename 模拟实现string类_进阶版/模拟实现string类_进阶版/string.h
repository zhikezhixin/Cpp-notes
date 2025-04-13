#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cassert>
using namespace std;

namespace Zeker
{
const size_t npos = -1; // ͨ�õġ���ʵ���޹صĳ���

class string
{
friend ostream& operator<<(ostream& out, const string& s);   //����"<<"���ܶ�����public����Ϊ��Ա����
friend istream& operator>>(istream& in, string& s);          //��Ա�������������������this,��"<<"�������������ostream�����
public:                                                       
string(const char* str = "");
string(const string& str);

~string();
size_t size()const;
size_t capacity()const;
const char* c_str()const;

void dilatation(size_t n);
void append(const char* str); // ׷���ַ���
void push_back(char ch);
void resize(size_t n, char ch = '\0');
void erase(size_t pos, size_t len = npos);
size_t find(char ch, size_t pos = 0); 
size_t find(const char* str, size_t pos = 0); 
string& insert(size_t pos, char ch);
string& insert(size_t pos, const char* str);

char& operator[](size_t i);
const char& operator[](size_t i)const;
string& operator+= (const string & str);
string& operator+= (char ch);
string& operator+= (const char* str);
string& operator= (const string& str);
bool operator==(const char* str);
bool operator==(const string& str);
bool operator!=(const char* str);
bool operator!=(const string& str);
bool operator<=(const string& str);
bool operator>=(const string& str);
bool operator<(const string& str);
bool operator>(const string& str);

private:
char* _str;
size_t _size;
size_t _capacity;
};

}