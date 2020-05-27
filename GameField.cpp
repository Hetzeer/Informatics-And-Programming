#include "GameField.h"

GameField::GameField() : FIELD_WIDTH(20), FIELD_HEIGHT(20), gameStatus(true), winStatus(false), winableValue(6) { }

GameField::GameField(int _FIELD_WIDTH, int _FIELD_HEIGHT, bool _status) : FIELD_WIDTH(_FIELD_WIDTH), FIELD_HEIGHT(_FIELD_HEIGHT),
	gameStatus(_status), winStatus(false), winableValue(6)
{
	if (FIELD_WIDTH < 10 or FIELD_HEIGHT < 10) {
		throw 1;
	}
}

bool GameField::getGameStatus()
{
	return gameStatus;
}

void GameField::setGameStatus(bool _status)
{
	gameStatus = _status;
}


bool GameField::getWinStatus()
{
	return winStatus;
}

void GameField::setWinStatus(bool _status)
{
	winStatus = _status;
}

void GameField::setWinableValue(int _value)
{
	winableValue = _value;
}

void GameField::drawGameField()
{
	int k = 0;
	for (int i = 1; i <= FIELD_HEIGHT; i++)
	{
		if (i == 1 || i == FIELD_HEIGHT)
			for (int c = 1; c <= FIELD_WIDTH; c++) {
				std::cout << "-";
			}
		else
		{
			std::cout << "|";
			for (int c = 1; c <= (FIELD_WIDTH - 2); c++) std::cout << " ";
			std::cout << "|";

		}
		std::cout << "\n";
	}
	std::cout << "\tp - pause, e - exit\n";
}

void GameField::drawWelcomeScreen()
{
	std::cout << "\t\t\t\t__          ________ _      _____ ____  __  __ ______ \n";
	std::cout << "\t\t\t\t\\ \\        / /  ____| |    / ____/ __ \\|  \\/  |  ____|\n";
	std::cout << "\t\t\t\t \\ \\  /\\  / /| |__  | |   | |   | |  | | \\  / | |__   \n";
	std::cout << "\t\t\t\t  \\ \\/  \\/ / |  __| | |   | |   | |  | | |\\/| |  __|  \n";
	std::cout << "\t\t\t\t   \\  /\\  /  | |____| |___| |___| |__| | |  | | |____ \n";
	std::cout << "\t\t\t\t    \\/  \\/___|______|______\\_____\\____/|_|__|_|______|\n";
	std::cout << "\t\t\t\t        |__   __/ __ \\  |__   __| |  | |  ____|       \n";
	std::cout << "\t\t\t\t           | | | |  | |    | |  | |__| | |__          \n";
	std::cout << "\t\t\t\t           | | | |  | |    | |  |  __  |  __|         \n";
	std::cout << "\t\t\t\t           | | | |__| |    | |  | |  | | |____        \n";
	std::cout << "\t\t\t\t           |_|__\\____/ _   |_|  |_|  |_|______|       \n";
	std::cout << "\t\t\t\t            / ____| \\ | |   /\\   | |/ /  ____|        \n";
	std::cout << "\t\t\t\t           | (___ |  \\| |  /  \\  | ' /| |__           \n";
	std::cout << "\t\t\t\t            \\___ \\| . ` | / /\\ \\ |  < |  __|          \n";
	std::cout << "\t\t\t\t            ____) | |\\  |/ ____ \\| . \\| |____         \n";
	std::cout << "\t\t\t\t           |_____/|_| \\_/_/    \\_\\_|\\_\\______|        \n";
}

void GameField::drawWinScreen()
{
	std::cout << "\t\t\t__     ______  _    _       __          _______ _   _ \n";
	std::cout << "\t\t\t\\ \\   / / __ \\| |  | |      \\ \\        / /_   _| \\ | |\n";
	std::cout << "\t\t\t \\ \\_/ / |  | | |  | |       \\ \\  /\\  / /  | | |  \\| |\n";
	std::cout << "\t\t\t  \\   /| |  | | |  | |        \\ \\/  \\/ /   | | | . ` |\n";
	std::cout << "\t\t\t   | | | |__| | |__| |         \\  /\\  /   _| |_| |\\  |\n";
	std::cout << "\t\t\t   |_|  \\____/ \\____/           \\/  \\/   |_____|_| \\_|\n";
}

void GameField::drawGameOverScreen()
{
	std::cout << "\t   _____          __  __ ______       ______      ________ _____   \n";
	std::cout << "\t  / ____|   /\\   |  \\/  |  ____|     / __ \\ \\    / /  ____|  __ \\  \n";
	std::cout << "\t | |  __   /  \\  | \\  / | |__       | |  | \\ \\  / /| |__  | |__) | \n";
	std::cout << "\t | | |_ | / /\\ \\ | |\\/| |  __|      | |  | |\\ \\/ / |  __| |  _  /  \n";
	std::cout << "\t | |__| |/ ____ \\| |  | | |____     | |__| | \\  /  | |____| | \\ \\  \n";
	std::cout << "\t  \\_____/_/    \\_\\_|  |_|______|     \\____/   \\/   |______|_|  \\_\\ \n"; 
}

int GameField::generateX()
{
	int x;
	do {
		x = rand() % FIELD_WIDTH;
	} while (x <= 1 or x >= FIELD_WIDTH-1);
	return x;
}
int GameField::generateY()
{
	int y;
	do {
		y = rand() % FIELD_HEIGHT;
	} while (y <= 1 or y >= FIELD_HEIGHT-1);
	return y;
}

int GameField::generateHeadX()
{
	int x;
	do {
		x = rand() % FIELD_WIDTH;
	} while (x <= 6 or x >= FIELD_WIDTH-6);
	return x;
}
int GameField::generateHeadY()
{
	int y;
	do {
		y = rand() % FIELD_HEIGHT;
	} while (y <= 6 or y >= FIELD_HEIGHT-6);
	return y;
}


int GameField::getWidth()
{
	return FIELD_WIDTH;
}

int GameField::getHeight()
{
	return FIELD_HEIGHT;
}
