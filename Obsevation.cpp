#include "Observation.h"

Observation::Observation()
{
	m_date = Date();
	m_time = Time();
	m_temperature = 0;
}

Observation::Observation(Date _date, Time _time, float _temperature) :
	m_date(_date),
	m_time(_time),
	m_temperature(_temperature)
{ }

Observation::Observation(const Observation& observation)
{
	m_date = observation.m_date;
	m_time = observation.m_time;
	m_temperature = observation.m_temperature;

}

std::ostream& operator<<(std::ostream& out, const Observation& observation)
{
	out << observation.m_date << " " << observation.m_time << " Temperature: " << observation.m_temperature << std::endl;
	return out;
}

Date Observation::getDate()
{
	Date returnDate(m_date.s_day, m_date.s_month, m_date.s_year);
	return returnDate;
}

Time Observation::getTime()
{
	Time returnTime(m_time.s_hour, m_time.s_minute, m_time.s_second);
	return returnTime;
}

float Observation::getTemperature()
{
	return m_temperature;
}

void Observation::setDate(int _day, int _month, int _year)
{
	m_date.s_day = _day;
	m_date.s_month = _month;
	m_date.s_year = _year;
}

void Observation::setDate(Date& _date)
{
	m_date = _date;
}

void Observation::setTime(int _hour, int _minute, int _second)
{
	m_time.s_hour = _hour;
	m_time.s_minute = _minute;
	m_time.s_second = _second;
}

void Observation::setTime(Time& _time)
{
	m_time = _time;
}

void Observation::setTemperature(float _temperature)
{
	m_temperature = _temperature;
}

void Observation::checkData(Date& _date, Time& _time)
{
	if (_date.s_year != m_date.s_year)
		throw 1;
	bool isFirtyOne = _date.s_month == 1 or _date.s_month == 3 or _date.s_month == 5 or
		_date.s_month == 7 or _date.s_month == 8 or _date.s_month == 10 or _date.s_month == 12;
	bool isFirty = _date.s_month == 4 or _date.s_month == 6 or _date.s_month == 9 or _date.s_month == 11;
	bool isTwentyNine = _date.s_month == 2 and (_date.s_month % 4 == 0 and (_date.s_month % 400 == 0 or
		_date.s_month % 100 != 0));
	if (isFirtyOne) {
		if (_date.s_day > 31)
			throw 1;
	}
	else if (isFirty) {
		if (_date.s_day > 30)
			throw 1;
	}
	else if (isTwentyNine) {
		if (_date.s_day > 29)
			throw 1;
	}
	bool isHour = _time.s_hour >= 0 and _time.s_hour <= 24;
	bool isMinute = _time.s_minute >= 0 and _time.s_minute <= 60;
	bool isSecond = _time.s_second >= 0 and _time.s_second <= 60;
	if (!isHour)
		throw 1;
	else if (!isMinute)
		throw 1;
	else if (!isSecond)
		throw 1;

}