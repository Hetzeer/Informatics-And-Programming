#ifndef POINT_H
#define POINT_H
#include "windows.h"
#include <iostream>

class Point
{
public:
	// Concstuctors
	Point();
	Point(int _x, int _y);
	Point(const Point& point);

	// Getters and setters 
	void setPoint(int _x, int _y);
	int getX();
	int getY();

	// Movement
	bool moveUp();
	bool moveDown(int _height);
	bool moveLeft();
	bool moveRight(int _width);

	// Draw and other stuff
	void draw(char s='#');
	void copyPosition(Point& point);
	int pointInsersection(Point& point);

private:
	int x;
	int y;


	void goToXY(int _x, int _y);
};
#endif
