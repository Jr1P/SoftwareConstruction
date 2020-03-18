#include <iostream>
#include <cmath>
using namespace std;

class Date
{
public:
	Date(int y, int m, int d);
	void nextDay();
	void print();
private:
	int year;
	int month;
	int day;
};

Date::Date(int y, int m, int d)
{
	year = y;
	month = m;
	day = d;
}

void Date::nextDay()
{
	if (month == 2)
	{
		if ((year % 400 == 0) || ((year % 100) && (year % 4 == 0)))
		{
			if (day == 29)
			{
				month++;
				day = 1;
			}
			else day++;
		}
		else
		{
			if (day == 28)
			{
				month++;
				day = 1;
			}
			else day++;
		}
	}
	else if (month == 12 && day == 31)
	{
		year++;
		month = 1;
		day = 1;
	}
	else if (((month <= 7 && (month & 1)) || (month >= 8 && !(month & 1)))&& day == 31)
	{
		month++;
		day = 1;
	}
	else if (((month <= 7 && !(month & 1)) || (month >= 8 && (month & 1))) && day == 30)
	{
		month++;
		day = 1;
	}
	else
		day++;
}

void Date::print()
{
	cout << month << '-' << day << '-' << year << '\n';
}

int main()
{
	Date dd(1998, 10, 2);
	for(int i = 1; i <= 160; i++)
	{
		dd.print();
		dd.nextDay();
	}
	return 0;
}