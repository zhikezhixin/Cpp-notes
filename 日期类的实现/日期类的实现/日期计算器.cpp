#include "日期计算器.h"

void Menu()
{
	cout << "----------欢迎进入日期计算器----------" << endl;
	cout << "             1.日期加法               " << endl;
	cout << "             2.日期减法               " << endl;
	cout << "             3.日期比较               " << endl;
	cout << "             4.计算日期之差           " << endl;
	cout << "             0.退出" << endl;
	cout << "请选择：";
}

int GetMonthDay(int year, int month)
{
	int days[13] = { 0,31,28,31,30,31,30,31,31,30,31,30,31 };
	if (month == 2 && (year % 4 == 0 && year % 100 != 0) || year % 400 == 0)
		return 29;
	else
		return days[month];
}

int GetYearDay(int year)
{
	if ( (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0) )
		return 366;
	return 365;
}

Date::Date(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}


void Date::Show()
{
	cout << _year << "年" << _month << "月" << _day << "日" ;
}


void Date::SetDate(int year, int month, int day)
{
	_year = year;
	_month = month;
	_day = day;
}

void Date::InputeDate()
{
	int year, month, day;
	while(true)
	{
		cout << "请输入 年 月 日 :";
		cin >> year >> month >> day;
		if (year < 0 || month < 0 || day < 0)
		{
			cout << "非法输入！ 请重新输入" << endl;
			continue;
		}
		else if (month > 13 || day > GetMonthDay(year, month))
		{
			cout << "日期有误，请重新输入" << endl;
			continue;
		}
		else
		{
			SetDate(year, month, day);
			break;
		}
	}
}

Date& Date::operator=(const Date& d)
{
	_year = d._year;
	_month = d._month;
	_day = d._day;

	return *this;
}


Date Date::operator+(int day)
{
	if (day < 0)
	{
		return (*this - (-day) );
	}
	Date ret(*this);
	ret += day;
	
	return ret;
}

Date Date::operator-(int day)
{
	if (day < 0)
	{
		return (*this + (-day));
	}
	Date ret(*this);
	ret -= day;
	
	return ret;
}

Date& Date::operator+=(int day)
{
	if (day < 0)
	{
		return (*this -= (-day));
	}
	Date ret(*this);
	ret._day += day;
	while (ret._day > GetMonthDay(ret._year, ret._month))
	{
		ret._day -= GetMonthDay(ret._year, ret._month);
		ret._month++;
		if (ret._month == 13)
		{
			ret._year++;
			ret._month = 1;
		}
	}
	*this = ret;
	return *this;
}

Date& Date::operator-=(int day)
{
	if (day < 0)
	{
		return (*this += (-day));
	}
	Date ret(*this);
	ret._day -= day;
	while (ret._day <= 0)
	{
		ret._month--;
		if (ret._month == 0)
		{
			ret._year--;
			ret._month = 12;
		}
		ret._day += GetMonthDay(ret._year, ret._month);
	}
	*this = ret;
	return *this;
}

Date& Date::operator++()
{
	return (*this += 1);
}

Date& Date::operator--()
{
	return (*this -= 1 );
}

bool Date::operator>(const Date& d)
{
	if (_year > d._year)
	{
		return true;
	}
	else if (_year == d._year && _month > d._month)
	{
		return true;
	}
	else if (_year == d._year && _month == d._month && _day > d._day)
	{
		return true;
	}
	else
		return false;
}

bool Date::operator==(const Date& d)
{
	return _year == d._year && _month == d._month && _day == d._day;
}

bool Date::operator!=(const Date& d)
{
	return !(*this == d);
}

bool Date::operator<(const Date& d)
{
	return (!(*this > d))&& (!(*this == d));
}


char Date::DateCompare(const Date& d)
{
	if (*this > d)
		return '>';
	else if (*this < d)
		return '<';
	else 
		return '=';
}


int Date::DateSub(const Date& d)
{
	Date max = *this;
	Date min = d;
	if (max < min)
	{
		max = d;
		min = *this;
	}
	int days = 0;

	// 计算年份差异的天数
	for (int year = min._year; year < max._year; ++year)
	{
		days += GetYearDay(year);
	}

	//加上日期大的月数
	for (int month = 1; month < max._month; ++month)
	{
		days += GetMonthDay(max._year, month);
	}
	//减去日期小的月数
	for (int month = 1; month < min._month; ++month)
	{
		days -= GetMonthDay(min._year, month);
	}

	// 加上日期差异
	days += max._day - min._day;

	return days;
}
