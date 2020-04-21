#include "Data.h"
std::ostream& operator<<(std::ostream& out, const Date& date)
{
	out << "Date: " << date.s_day << "." << date.s_month << "." << date.s_year;
	return out;
}
std::istream& operator>>(std::istream& in, Date& date)
{
	char tmp;
	in >> date.s_day;
	tmp = in.get();
	in >> date.s_month;
	tmp = in.get();
	in >> date.s_year;
	return in;
}

bool operator==(const Date& _date1, const Date& _date2)
{
	bool isDay = _date1.s_day == _date2.s_day;
	bool isMonth = _date1.s_month == _date2.s_month;
	bool isYear = _date1.s_year == _date2.s_year;
	return isDay and isMonth and isYear;
}

Date::Date(int _day, int _month, int _year) : s_day(_day), s_month(_month), s_year(_year) { }

Date::Date() : s_day(0), s_month(0), s_year(0) { }


std::ostream& operator<<(std::ostream& out, const Time& time)
{
	out << "Time: " << time.s_hour << ":" << time.s_minute << ":" << time.s_second;
	return out;
}

std::istream& operator>>(std::istream& in, Time& time)
{
	char tmp;
	in >> time.s_hour;
	tmp = in.get();
	in >> time.s_minute;
	tmp = in.get();
	in >> time.s_second;
	return in;

}

bool operator==(const Time& _time1, const Time& _time2)
{
	bool isHour = _time1.s_hour == _time2.s_hour;
	bool isMinute = _time1.s_minute == _time2.s_minute;
	bool isSecond = _time1.s_second == _time2.s_second;
	return isHour and isMinute and isSecond;
}

Time::Time(int _hour, int _minute, int _second) : s_hour(_hour), s_minute(_minute),
s_second(_second)
{ }

Time::Time() : s_hour(0), s_minute(0), s_second(0) { }


void enterObservation(Date& date, Time& time, float& temperature)
{
	std::cout << "Date: ";
	std::cin >> date;
	std::cout << "Time: ";
	std::cin >> time;
	std::cout << "Temperature: ";
	std::cin >> temperature;
}

void enterDateAndTime(Date& date, Time& time)
{
	std::cout << "Date: ";
	std::cin >> date;
	std::cout << "Time: ";
	std::cin >> time;
}

void enterDate(Date& date)
{
	std::cout << "Date: ";
	std::cin >> date;
}