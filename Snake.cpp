#include "Snake.h"

Snake::Snake(int _width, int _height) : GameField(_width, _height, true)
{
	cells.push_back(Point(generateHeadX(), generateHeadY())); // random position for head
	for(int i = 0; i < 4; i++)
		addCell(0, 0);
	direction = 'a';
	fruit.setPoint(generateX(), generateY()); // random position for fruit
}

void Snake::addCell(int _x, int _y)
{
	cells.push_back(Point(_x, _y)); // and cell to the end;
}

void Snake::turnUp()
{
	if(direction != 's')
		direction = 'w'; // w is default key for turning up
}

void Snake::turnDown()
{
	if(direction != 'w')
		direction = 's'; // s is default key for turning down
}

void Snake::turnLeft()
{
	if(direction != 'd')
		direction = 'a'; // a is default key for turning left
}

void Snake::turnRight()
{
	if(direction != 'a')
		direction = 'd'; // d is default key for turning right
}

void Snake::drawSnake()
{
	for (int i = 0; i < cells.size(); i++) {
		cells[i].draw();
	}
}

int Snake::getSnakeSize()
{
	return cells.size();
}

int Snake::selfIntersection() // intersec head with body
{
	for (int i = 1; i < cells.size(); i++) {
		if (cells[0].pointInsersection(cells[i])) {
			return 1;
		}
	}
	return 0;
}

bool Snake::isWin()
{
	return winableValue - cells.size() == 0;
}

void Snake::update()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
	// clearing screen
	system("cls");
	// draw game field
	std::cout << "\tCurrent Size: " << cells.size();
	std::cout << "\t\tLeft for win: " << winableValue - cells.size() << "\n";

	drawGameField();
	
	// body follows head
	for (int i = cells.size() - 1; i > 0; i--) {
		cells[i-1].copyPosition(cells[i]);
	}

	// make head ability to turn 
	switch (direction) {
		case 'w' : 
			setGameStatus(cells[0].moveUp());
			break;
		case 's' : 
			setGameStatus(cells[0].moveDown(FIELD_HEIGHT));
			break;
		case 'a' : 
			setGameStatus(cells[0].moveLeft());
			break;
		case 'd' : 
			setGameStatus(cells[0].moveRight(FIELD_WIDTH));
			break;
	}
	
	// check for win;

	if (isWin()) {
		setWinStatus(true);
		setGameStatus(false);
	}

	// dont let head eat its body, if true - game over
	if (selfIntersection()) {
		setGameStatus(false);
	}

	// intersection with fruit
	if (fruit.getX() == cells[0].getX() and fruit.getY() == cells[0].getY()) {
		addCell(0, 0);
		fruit.setPoint(generateX(), generateY()); // random position for fruit
	}
	// draw main section
	drawSnake();
	fruit.draw('*');
	// fps
	Sleep(100);
}
