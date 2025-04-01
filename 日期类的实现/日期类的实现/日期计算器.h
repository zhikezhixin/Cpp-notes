#pragma once
#include <iostream>
using namespace std;

class Date
{
private:
	int  _year;
	int _month;;
	int _day;
	void SetDate(int year, int month, int day);
public:
	Date(int year = 0, int month = 1, int day = 1);
	void Show();
	void InputeDate();

	Date operator+(int day);
	Date operator-(int day);
	Date& operator+=(int day);
	Date& operator-=(int day);
	Date& operator++();
	Date& operator--();
	Date& operator=(const Date& d);
	bool operator>(const Date& d);
	bool operator==(const Date& d);
	bool operator!=(const Date& d);
	bool operator<(const Date& d);
	char DateCompare(const Date& d);
	int DateSub(const Date& d);
};

int GetMonthDay(int year, int month);
void Menu();
