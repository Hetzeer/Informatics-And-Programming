#ifndef SNAKE_H
#define SNAKE_H

#include "conio.h"
#include "stdio.h"
#include "Point.h"
#include "GameField.h"
#include "ctime"
#include <vector>

class Snake : public GameField
{
public:
	Snake(int _width, int _height);

	void addCell(int _x, int _y);

	// Turning
	void turnUp();
	void turnDown();
	void turnLeft();
	void turnRight();

	int selfIntersection();

	int getSnakeSize();

	void update();

private:
	std::vector<Point> cells; // for show snake in console
	char direction; // current direction where snake goes
	Point fruit; // fruit

	void drawSnake();

	bool isWin();


};
#endif
