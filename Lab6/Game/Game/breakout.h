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
	int ballMovementX, ballMovementY;
public:
	//Breakout(std::vector<Rectangle> wall, int xRes, int yRes);
	Breakout(std::vector<std::vector<Rectangle>> wall, int xRes, int yRes);
	void render(SDL_Renderer* renderer);
	void movePlank(int move);
	void moveBall();
	void breakBrick();
};