#ifndef THERMOMETER_H
#define THERMOMETER_H
#include "Observation.h"
class Thermometer
{
public:
	Thermometer();
	Thermometer(Date _date, Time _time, float _temperature);
	Thermometer(const Thermometer& thermometer);
	~Thermometer();

	void getFirstTimeAndDate();
	void addObservation(Date _date, Time _time, float _temperature);
	void getObservation(Date _date, Time _time);
	void getSeriesOfObserv(Date _date);
	void getAverageTemperature(Date _date);
	void getAverageTemperature(int _month);
	void getAverageTemperature();
	void getAverageByDaytime(int _month);
	void getAverageByNighttime(int _month);
	void writeFile(std::string path);
	void readFile(std::string path);

private:
	Observation* m_observation;
	int m_amountOfObservation;
};

#endif

