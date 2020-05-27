#include "Point.h"

HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD CursorPosition;

Point::Point() : x(10), y(10) { }


Point::Point(int _x, int _y) : x(_x), y(_y) { }

Point::Point(const Point& point) : x(point.x), y(point.y) { }

void Point::setPoint(int _x, int _y)
{
	x = _x;
	y = _y;
}

int Point::getX()
{
	return x;
}

int Point::getY()
{
	return y;
}

bool Point::moveUp()
{
	y--;
	if (y == 0)
		return false;
	return true;
	
}

bool Point::moveDown(int _height)
{
	y++;
	if (y == _height)
		return false;
	return true;
}

bool Point::moveLeft()
{
	x--;
	if (x == 0)
		return false;
	return true;
}

bool Point::moveRight(int _width)
{
	x++;
	if (x == _width)
		return false;
	return true;
}

void Point::goToXY(int _x, int _y)
{
	CursorPosition.X = _x;
	CursorPosition.Y = _y;
	SetConsoleCursorPosition(console, CursorPosition);
}

void Point::draw(char s)
{
	goToXY(x, y);
	std::cout << s;
}


void Point::copyPosition(Point& point)
{
	point.x = x;
	point.y = y;
}

int Point::pointInsersection(Point& point)
{
	if (point.x == x and point.y == y)
		return 1;
	return 0;
}
