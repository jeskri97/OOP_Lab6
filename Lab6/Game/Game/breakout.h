#pragma once

#include <vector>
#include "shapes.h"

class Breakout {
private:
	std::vector<Shape*> wall;
	Rectangle plank;
	Circle ball;
public:
	Breakout();
	void render(SDL_Renderer* renderer);
};