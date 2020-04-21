#include "Thermometer.h"

Thermometer::Thermometer()
{
	m_amountOfObservation = 1;
	m_observation = static_cast<Observation*>(operator new[](m_amountOfObservation * sizeof(Observation)));
	for (int i = 0; i < m_amountOfObservation; i++) {
		new (m_observation + i) Observation();
	}
}

Thermometer::Thermometer(Date _date, Time _time, float _temperature)
{
	m_amountOfObservation = 1;
	m_observation = static_cast<Observation*>(operator new[](m_amountOfObservation * sizeof(Observation)));
	for (int i = 0; i < m_amountOfObservation; i++) {
		new (m_observation + i) Observation(_date, _time, _temperature);
	}
	m_observation[0].checkData(_date, _time);
}

Thermometer::Thermometer(const Thermometer& thermometer)
{
	m_amountOfObservation = thermometer.m_amountOfObservation;
	if (this == &thermometer) return;
	if (m_observation == nullptr) {
		throw 1;
	}
	m_observation = static_cast<Observation*>(operator new[](m_amountOfObservation * sizeof(Observation)));
	for (int i = 0; i < m_amountOfObservation; i++) {
		new (m_observation + i) Observation(thermometer.m_observation[i].getDate(),
			thermometer.m_observation[i].getTime(), thermometer.m_observation[i].getTemperature());
	}
}


Thermometer::~Thermometer()
{
	delete[] m_observation;
	m_observation = nullptr;
}

void Thermometer::getFirstTimeAndDate()
{
	std::cout << m_observation[0];
}

void Thermometer::addObservation(Date _date, Time _time, float _temperature)
{
	m_observation[0].checkData(_date, _time);
	m_amountOfObservation += 1;
	Observation* tmpObservation = static_cast<Observation*>(operator new[]
	(m_amountOfObservation * sizeof(Observation)));
	for (int i = 0; i < m_amountOfObservation; i++) {
		new (tmpObservation + i) Observation(m_observation[i]);
	}
	tmpObservation[m_amountOfObservation - 1] = Observation(_date, _time, _temperature);
	delete[] m_observation;
	m_observation = tmpObservation;
}

void Thermometer::getObservation(Date _date, Time _time)
{
	for (int i = 0; i < m_amountOfObservation; i++) {
		if (m_observation[i].getDate() == _date and m_observation[i].getTime() == _time) {
			std::cout << m_observation[i];
		}
	}
}

void Thermometer::getSeriesOfObserv(Date _date)
{
	std::cout << "Series Of Observation by " << _date << std::endl;
	for (int i = 0; i < m_amountOfObservation; i++) {
		if (m_observation[i].getDate() == _date) {
			std::cout << m_observation[i].getTime() << " Temperature: " << m_observation[i].getTemperature() << std::endl;
		}
	}
}

void Thermometer::getAverageTemperature(Date _date)
{
	float averageTemperature = 0;
	float amount = 0;
	for (int i = 0; i < m_amountOfObservation; i++) {
		if (m_observation[i].getDate() == _date) {
			amount++;
			averageTemperature += m_observation[i].getTemperature();
		}
	}
	averageTemperature /= amount;
	std::cout << "Average Temperature by " << _date << " is " << averageTemperature << std::endl;
}

void Thermometer::getAverageTemperature(int _month)
{
	float averageTemperature = 0;
	float amount = 0;
	for (int i = 0; i < m_amountOfObservation; i++) {
		if (m_observation[i].getDate().s_month == _month) {
			amount++;
			averageTemperature += m_observation[i].getTemperature();
		}
	}
	averageTemperature /= amount;
	std::cout << "Average Temperature by " << _month << " month is " << averageTemperature << std::endl;
}

void Thermometer::getAverageTemperature()
{
	float averageTemperature = 0;
	float amount = 0;
	for (int i = 0; i < m_amountOfObservation; i++) {
		amount++;
		averageTemperature += m_observation[i].getTemperature();
	}
	averageTemperature /= amount;
	std::cout << "Average Temperature by All Time is " << averageTemperature << std::endl;
}

void Thermometer::getAverageByDaytime(int _month)
{
	float averageTemperature = 0;
	float amount = 0;
	for (int i = 0; i < m_amountOfObservation; i++) {
		if (m_observation[i].getDate().s_month == _month) {
			if (m_observation[i].getTime().s_hour > 4 and m_observation[i].getTime().s_hour < 18) {
				amount++;
				averageTemperature += m_observation[i].getTemperature();
			}
		}
	}
	averageTemperature += amount;
	std::cout << "Average Temperature by Nighttime by " << _month << " is " << averageTemperature << std::endl;
}

void Thermometer::getAverageByNighttime(int _month)
{
	float averageTemperature = 0;
	float amount = 0;
	for (int i = 0; i < m_amountOfObservation; i++) {
		if (m_observation[i].getDate().s_month == _month) {
			if (m_observation[i].getTime().s_hour < 4 and m_observation[i].getTime().s_hour > 18) {
				amount++;
				averageTemperature += m_observation[i].getTemperature();
			}
		}
	}
	averageTemperature += amount;
	std::cout << "Average Temperature by Nighttime by " << _month << " is " << averageTemperature << std::endl;
}

void Thermometer::writeFile(std::string path)
{
	std::fstream file;
	file.exceptions(std::fstream::badbit | std::fstream::failbit);

	try
	{
		file.open(path, std::fstream::out | std::fstream::app);
	}
	catch (const std::fstream::failure & exception)
	{
		std::cout << "File error: ";
		std::cout << exception.what() << std::endl;
		std::cout << exception.code() << std::endl;

	}

	file << "Amount of Observations: " << m_amountOfObservation << std::endl;
	for (int i = 0; i < m_amountOfObservation; i++) {
		file << i + 1 << " " << m_observation[i];
	}
	file.close();

}

void Thermometer::readFile(std::string path)
{
	int amountOfObservations;
	std::fstream file;
	file.exceptions(std::fstream::badbit | std::fstream::failbit);

	try
	{
		file.open(path, std::fstream::in);
	}
	catch (const std::fstream::failure & exception)
	{
		std::cout << "File error: ";
		std::cout << exception.what() << std::endl;
		std::cout << exception.code() << std::endl;

	}
	if (file.peek() == EOF) {
		std::cout << "File is empty" << std::endl;
	}
	file >> amountOfObservations;
	Date date;
	Time time;
	float temperature;
	for (int i = 0; i < amountOfObservations; i++) {
		file >> date;
		file >> time;
		file >> temperature;
		if (i == 0) {
			m_observation[i].setDate(date);
			m_observation[i].setTime(time);
			m_observation[i].setTemperature(temperature);
			m_observation[i].checkData(date, time);
		}
		else {
			this->addObservation(date, time, temperature);
			m_observation[i].checkData(date, time);
		}
	}
	file.close();
}

