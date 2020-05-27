#ifndef GAMEFIELD_H
#define GAMEFIELD_H

#include <iostream>
class GameField
{
public:
	// Basic constructors
	GameField();
	GameField(int _width, int _height, bool _status);

	// Getters and Setters
	bool getGameStatus();
	void setGameStatus(bool _status);

	bool getWinStatus();
	void setWinStatus(bool _status);

	void setWinableValue(int _value);

	void drawGameField();
	void drawWelcomeScreen();
	void drawWinScreen();
	void drawGameOverScreen();

	int generateX();
	int generateY();

	int generateHeadX();
	int generateHeadY();

	int getWidth();
	int getHeight();

protected:
	int winableValue;
	int FIELD_WIDTH;
	int FIELD_HEIGHT;

private:
	bool gameStatus;
	bool winStatus;
};
#endif
