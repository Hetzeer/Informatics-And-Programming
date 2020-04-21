#ifndef OBSERVATION_H
#define OBSERVATION_H
#include "Data.h"

class Observation
{
public:
	Observation();
	Observation(Date _date, Time _time, float _temperature);
	Observation(const Observation& observation);

	friend std::ostream& operator<<(std::ostream& out, const Observation& observation);

	Date getDate();
	Time getTime();
	float getTemperature();

	void setDate(int _day, int _month, int _year);
	void setDate(Date& _date);
	void setTime(int _hour, int _minute, int _second);
	void setTime(Time& _time);
	void setTemperature(float _temperature);

	void checkData(Date& _date, Time& _time);
private:
	Date m_date;
	Time m_time;
	float m_temperature;
};

#endif