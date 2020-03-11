
#include "Date.h"

void daycheck(int *d, int *_d, int *m, int *y)
{
	bool y4;
	int mm = *m;
	int vis[12] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if ((*y % 4) || (*y % 100 == 0 && *y % 400)) { y4 = false; }
	else y4 = true;

	if (y4 == false) {}
	else { vis[1] = 29; };
	if (*_d > vis[mm]) {
		while (*d > *_d% vis[mm]) {
			*d = *_d % vis[mm];
			mm++;
		}
		if (*d == 0) { *d = 1; };
		mm += (*_d / vis[0]) % 12;
		*y += (mm / 12) + *_d / 365;
	}
	else
	{
		*d = *_d;
	}
	*_d = *d;
	*m = mm;
}

Date::Date() {
	this->d = 1;
	this->m = 1;
	this->y = 1;
}

Date::Date(int _d, int _m, int _y) {
	this->d = _d;
	this->m = _m;
	this->y = _y;
}

Date::Date(const Date& c) {
	this->d = c.d;
	this->m = c.m;
	this->y = c.y;
}

Date::~Date() {
	this->d = 0;
	this->m = 0;
	this->y = 0;
}

int Date::Get_D() { return this->d; }
int Date::Get_M() { return this->m; }
int Date::Get_Y() { return this->y; }

void Date::Set_D(int _d) {


	daycheck(&d, &_d, &m, &y);

}
void Date::Set_M(int _m) {

	if (_m > 12) {
		this->m = _m % 12;
		this->y += _m / 12;
	}
	else {
		this->m = _m;
	}

}
void Date::Set_Y(int _y) {

	this->y = _y;
}

void Date::print() {
	std::cout << Get_D() << "." << Get_M() << ":" << Get_Y() << std::endl;
}

void Date::input() {
	int d, m, y;
	std::cout << "Enter day - ";
	std::cin >> d;
	std::cout << "Enter month - ";
	std::cin >> m;
	std::cout << "Enter year - ";
	std::cin >> y;

	Set_Y(y);
	Set_M(m);
	Set_D(d);

	cout << "Entered date: ";
	print();

}


void Date::inputStr() {
	int  i = 0, j = 0, da, mo, ye;
	int zer = (int)'0';
	char str[100];
	char d[3], m[3], y[5];

	std::cout << "Enter date in format dd.mm:yyyy" << std::endl;
	std::cin >> str;

	while (str[i] != '.' && str[i] != ',' && str[i] != ' ' && str[i] != ':')
	{
		d[j] = str[i];
		i++; j++;
	}
	i++; j = 0;
	da = (((int)d[0] - zer) * 10) + ((int)d[1] - zer);

	while (str[i] != ':' && str[i] != ',' && str[i] != ' ' && str[i] != '.') {
		m[j] = str[i];
		i++; j++;
	}
	j = 0; i++;
	mo = (((int)m[0] - zer) * 10) + ((int)m[1] - zer);

	while (i < 10) {
		y[j] = str[i];
		i++; j++;
	}

	ye = (((int)y[0] - zer) * 1000) + (((int)y[1] - zer) * 100) + (((int)y[2] - zer) * 10) + ((int)y[3] - zer);

	Set_Y(ye);
	Set_M(mo);
	Set_D(da);
}

Date& Date::operator=(const Date& c) {
	d = c.d;
	m = c.m;
	y = c.y;
	return *this;
}

Date Date::operator-(const Date& c) {
	Date res;
	int tmp, tmp2;
	res.d = this->d - c.d;
	res.m = this->m - c.m;
	res.y = this->y - c.y;
	tmp = res.d;
	res.Set_D(tmp);
	tmp = res.m;
	res.Set_M(tmp);
	return res;
}

Date Date::operator+(const Date& c) {
	Date res;
	int tmp;
	res.d = this->d + c.d;
	res.m = this->m + c.m;
	if (c.y > y) {
		res.y = this->y + (c.y - y);
	}
	else { if (y > c.y) { res.y = this->y + abs((c.y - y)); } }
	tmp = res.d;
	res.Set_D(tmp);
	tmp = res.m;
	res.Set_M(tmp);
	return res;
}

bool Date::operator==(const Date& c) {
	bool res;
	res = (d == c.d) && (m == c.m) && (y == c.y);
	return res;
}

bool Date::operator!=(const Date& c) {
	bool res;
	res = (d != c.d) || (m != c.m) || (y != c.y);
	return res;
}

std::ostream& operator << (std::ostream& in, const Date& c) {
	in << c.d << ".";
	in << c.m << ":";
	in << c.y;
	return in;
}

std::istream& operator >> (std::istream& out, Date& c) {
	out >> c.d >> c.m >> c.y;
	return out;
}