#include "���ڼ�����.h"

void Menu()
{
	cout << "----------��ӭ�������ڼ�����----------" << endl;
	cout << "             1.���ڼӷ�               " << endl;
	cout << "             2.���ڼ���               " << endl;
	cout << "             3.���ڱȽ�               " << endl;
	cout << "             4.��������֮��           " << endl;
	cout << "             0.�˳�" << endl;
	cout << "��ѡ��";
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
	cout << _year << "��" << _month << "��" << _day << "��" ;
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
		cout << "������ �� �� �� :";
		cin >> year >> month >> day;
		if (year < 0 || month < 0 || day < 0)
		{
			cout << "�Ƿ����룡 ����������" << endl;
			continue;
		}
		else if (month > 13 || day > GetMonthDay(year, month))
		{
			cout << "������������������" << endl;
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

	// ������ݲ��������
	for (int year = min._year; year < max._year; ++year)
	{
		days += GetYearDay(year);
	}

	//�������ڴ������
	for (int month = 1; month < max._month; ++month)
	{
		days += GetMonthDay(max._year, month);
	}
	//��ȥ����С������
	for (int month = 1; month < min._month; ++month)
	{
		days -= GetMonthDay(min._year, month);
	}

	// �������ڲ���
	days += max._day - min._day;

	return days;
}
