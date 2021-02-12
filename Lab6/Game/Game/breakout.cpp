
#include "breakout.h"

Breakout::Breakout() {
	this->plank.setPos(Point2D(640, 960));
	this->plank.setVal(100, 25);
	this->plank.setColor(0, 0, 255, 255);
}
void Breakout::render(SDL_Renderer* renderer) {
	this->plank.render(renderer);
}