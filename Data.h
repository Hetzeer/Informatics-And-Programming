#ifndef DATA_H
#define DATA_H

#include <iostream>
#include <fstream>
#include <string>

struct Date
{
	int s_day;
	int s_month;
	int s_year;
	Date(int _day, int _month, int _year);
	Date();
};

struct Time
{
	int s_hour;
	int s_minute;
	int s_second;
	Time(int _hour, int _minute, int _second);
	Time();
};

std::ostream& operator<<(std::ostream& out, const Date& date);
std::istream& operator>>(std::istream& in, Date& date);
bool operator==(const Date& _date1, const Date& _date2);

std::ostream& operator<<(std::ostream& out, const Time& time);
std::istream& operator>>(std::istream& in, Time& time);
bool operator==(const Time& _time1, const Time& _time2);

void enterObservation(Date& date, Time& time, float& temperature);
void enterDateAndTime(Date& date, Time& time);
void enterDate(Date& date);

#endif
