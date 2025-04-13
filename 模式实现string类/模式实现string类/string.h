#pragma once
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
using namespace std;


namespace Zeker
{
	class string
	{
	public:
		string(const char* str = "");
		string(const string& s);
		string& operator=(const string& s);
		~string();
		const char* c_str()const; // 常量成员函数：不改变当前成员函数的值
		size_t size();
		char& operator[](size_t i);

	private:
		char* _str; 
		size_t _size;
		size_t _capacity; 
	};

}