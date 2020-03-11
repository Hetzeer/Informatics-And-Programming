#include "Date.h"

int main() {

	int d = 11, m = 3, y = 2020, vib;

	Date d1, d2, res;


	Date now(d, m, y);
	do {
		now.print();
		system("pause");
		do {
			cout << "1 - Enter date string\n2 - Enter date in separate values\n3 - Use input operator overload\n";
			cin >> vib;
		} while (1 > vib || vib > 3);
		if (vib == 1)
			d1.inputStr();
		else if (vib == 2)
			d1.input();
		else
			cin >> d1;
		do {

			do {
				system("cls");
				cout << "The entered date using the method" << endl;
				d1.print();
				cout << "Entered date using overload" << endl;
				cout << d1;

				cout << endl << "Your actions:" << endl;
				cout << "\n1)Addition" << endl;
				cout << "2)Subtraction" << endl;
				cout << "3)Are the dates not equal?" << endl;
				cout << "4)Are the dates equal?" << endl;
				cout << "0)Exit" << endl;
				cin >> vib;
			} while (0 > vib || vib > 5);
			switch (vib)
			{
			case 1:
				cout << "Enter the second date" << endl;
				d2.input();
				res = d1 + d2;
				cout << "Result: " << res << endl;
				break;
			case 2:	cout << "Enter a deductible date" << endl;
				d2.input();
				res = d1 - d2;
				cout << "Result: " << res << endl;
				break;
			case 3:cout << "What to compare with" << endl;
				d2.input();
				if (d1 == d2)
					cout << "Dates are equal" << endl;
				else
					cout << "Dates are not equal" << endl;
				break;
			case 4:
				cout << "What to compare with" << endl;
				d2.input();
				if (d1 != d2)
					cout << "Dates are not equal" << endl;
				else
					cout << "Dates are equal" << endl; break;
			case 0: break;
			default: break;
			}
			system("pause");
		} while (vib != 0 && vib != 5);
	} while (vib == 5);
}