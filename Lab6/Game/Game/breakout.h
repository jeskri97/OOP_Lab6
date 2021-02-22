#pragma once

#include <vector>
#include <algorithm>
#include "shapes.h"

class Breakout {
private:
	int gameResX, gameResY;
	//std::vector<Rectangle> wall;
	std::vector<std::vector<Rectangle>> wall;
	Rectangle plank;
	Circle ball;
	int ballSpeedX, ballSpeedY;
	bool gameOver;
public:
	//Breakout(std::vector<Rectangle> wall, int xRes, int yRes);
	Breakout(int bricksPerRow, int numberOfRows, int xRes, int yRes);
	void render(SDL_Renderer* renderer);
	void movePlank(int move);
	void brickCheck();
	void moveBall();
	bool getGameOver();
};