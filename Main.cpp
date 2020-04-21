#include "Thermometer.h"

int main()
{
	bool isRunning = true;
	int choice;
	const std::string output = "Output.txt";
	const std::string input = "Input.txt";
	Date date;
	Time time;
	float temperature;
	std::cout << "Programm running..." << std::endl;
	std::cout << "First observation: " << std::endl;
	enterObservation(date, time, temperature);
	Thermometer year20(date, time, temperature);
	system("cls");
	while (isRunning) {
		system("pause");
		system("cls");
		std::cout << "Choose: " << std::endl << "1 - Get first time and date\t\t2 - Add observation\n3 - Get observation by date and time\t" <<
		"4 - Get series of observations by date\n5 - Get average temperature by date\t6 - Get average temperature by month\n" <<
		"7 - Get average temperature by all time\t8 - Get average temperature by daytime\n9 - Get average temperature by night\t10 - Write observations into file\n"
		<<"11 - Read observations from file\t" << "12 - Exit" << std::endl;
		std::cin >> choice;
		switch (choice) {
			case 1 :
				year20.getFirstTimeAndDate();
				break;
			case 2 :
				enterObservation(date, time, temperature);
				year20.addObservation(date, time, temperature);
				break;
			case 3 :
				enterDateAndTime(date, time);
				year20.getObservation(date, time);
				break;
			case 4 :
				enterDate(date);
				year20.getSeriesOfObserv(date);
				break;
			case 5 :
				enterDate(date);
				year20.getAverageTemperature(date);
				break;
			case 6 :
				enterDate(date);
				year20.getAverageTemperature(date.s_month);
				break;
			case 7 :
				year20.getAverageTemperature();
				break;
			case 8 :
				enterDate(date);
				year20.getAverageByDaytime(date.s_month);
				break;
			case 9 :
				enterDate(date);
				year20.getAverageByNighttime(date.s_month);
				break;
			case 10 :
				year20.writeFile(output);
				break;
			case 11 :
				year20.readFile(input);
				break;
			case 12 :
				isRunning = false;
				break;
			default :
				break;
		}
	}
}

