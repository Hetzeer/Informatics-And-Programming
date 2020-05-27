#include <iostream>
#include "Snake.h"

HANDLE Console = GetStdHandle(STD_OUTPUT_HANDLE);
COORD Cursor;

void setCursor(bool visible, DWORD size)
{
	if (size == 0)
		size = 20;

	CONSOLE_CURSOR_INFO lpCursor;
	lpCursor.bVisible = visible;
	lpCursor.dwSize = size;
	SetConsoleCursorInfo(Console, &lpCursor);
}

void setCursorPosition(int _x, int _y)
{
	Cursor.X = _x;
	Cursor.Y = _y;
	SetConsoleCursorPosition(Console, Cursor);
}

void enterData(int* width, int* height, int* scoreForWin)
{
	std::cout << "\n";
	std::cout << "\t\t\t\t\t\tEnter width of GameField\n\t\t\t\t\t\t\t>> ";
	std::cin >> *width;
	std::cout << "\t\t\t\t\t\tEnter height of GameField\n\t\t\t\t\t\t\t>> ";
	std::cin >> *height;
	do {
		std::cout << "\t\t\t\t\t\tEnter winable value\n\t\t\t\t\t\t\t>> ";
		std::cin >> *scoreForWin;
		if (*scoreForWin <= 5)
			std::cout << "\t\t\t\t\t\tStandart size of snake is 5\n";
	} while (*scoreForWin <= 5);
}

int main()
{
	HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);

	int width;
	int height;
	int scoreForWin;
	
	setCursor(false, 0);
	srand((unsigned)time(NULL));
	system("title  Snake Game");

	Snake snake(50, 20);
	snake.drawWelcomeScreen();

	enterData(&width, &height, &scoreForWin);

	snake = Snake(width, height);
	snake.setWinableValue(scoreForWin);

	system("pause");

	char op = 'g';

	while (op != 'e' and snake.getGameStatus()) {
		if (_kbhit()) {
			op = _getch();
		}
		if (snake.getGameStatus() == false) {
			snake.drawGameOverScreen();
			exit(0);
		}
		switch (op) {
			case 'w' : 
				snake.turnUp();
				break;
			case 's' : 
				snake.turnDown();
				break;
			case 'a' : 
				snake.turnLeft();
				break;
			case 'd' : 
				snake.turnRight();
				break;

			case 'p' :
				op = 'g';
				setCursorPosition(0, snake.getHeight() + 4);
				std::cout << "\tPAUSE\n";
				system("pause");
				break;
		}
		snake.update();
	}

	setCursorPosition(0, snake.getHeight() + 4);
	system("pause");
	system("cls");

	if (snake.getWinStatus()) {
		snake.drawWinScreen();
	}
	else {
		snake.drawGameOverScreen();
		std::cout << "\n\t\t\t\tYour score: " << snake.getSnakeSize() << "\n";
	}
}