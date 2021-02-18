
#include "breakout.h"

//Breakout::Breakout(std::vector<Rectangle> wall, int xRes, int yRes) {
//	this->gameResX = xRes;
//	this->gameResY = yRes;
//	// Setup the wall.
//	this->wall = wall;
//	// Setup the plank.
//	int plankYPos = yRes / 6;
//	this->plank.setPos(Point2D(xRes / 2, plankYPos * 5));
//	this->plank.setVal(this->wall[0].getWidth(), this->wall[0].getHeight());
//	this->plank.setColor(0, 255, 255, 255);
//	// Setup the ball.
//	this->ball.setRad(yRes / 25);
//	this->ball.setPos(this->plank.getPos() + Point2D(0, -(this->ball.getRad() * 2)));
//	this->ball.setColor(0, 255, 255, 255);
//	srand(time(NULL));
//	this->ballMovementX = xRes / 256 - (rand() % (xRes / 256) * 2);
//	this->ballMovementY = yRes / 144;
//}
Breakout::Breakout(std::vector<std::vector<Rectangle>> wall, int xRes, int yRes) {
	this->gameResX = xRes;
	this->gameResY = yRes;
	// Setup the wall.
	this->wall = wall;
	// Setup the plank.
	int plankYPos = yRes / 6;
	this->plank.setPos(Point2D(xRes / 2, plankYPos * 5));
	this->plank.setVal(this->wall[0][0].getWidth(), this->wall[0][0].getHeight());
	this->plank.setColor(0, 255, 255, 255);
	// Setup the ball.
	this->ball.setRad(yRes / 25);
	this->ball.setPos(this->plank.getPos() + Point2D(0, -(this->ball.getRad() * 2)));
	this->ball.setColor(0, 255, 255, 255);
	srand(time(NULL));
	this->ballMovementX = xRes / 256 - (rand() % (xRes / 256) * 2);
	this->ballMovementY = yRes / 144;
}
void Breakout::render(SDL_Renderer* renderer) {
	// Render plank.
	this->plank.render(renderer);
	// Render wall bricks.
	for (int i = 0; i < this->wall.size(); i++) {
		for (int j = 0; j < this->wall[i].size(); j++) {
			this->wall[i][j].render(renderer);
		}
	}
	// Render ball.
	this->ball.render(renderer);
}
void Breakout::movePlank(int move) {
	Point2D currentPos = this->plank.getPos();
	Point2D newPos = currentPos + Point2D(move, 0);
	this->plank.setPos(newPos);
}
void Breakout::moveBall() {
	Point2D currentPos = this->ball.getPos();
	Point2D newPos = currentPos + Point2D(this->ballMovementX, this->ballMovementY);
	this->ball.setPos(newPos);
	// Bounce on walls.
	if (newPos.getx() - this->ball.getRad() < 0 || newPos.getx() + this->ball.getRad() > this->gameResX) {
		this->ballMovementX = this->ballMovementX * -1;
		Point2D newPos = currentPos + Point2D(this->ballMovementX, 0);
	}
	if (newPos.gety() - this->ball.getRad() < 0 || newPos.gety() + this->ball.getRad() > this->gameResY) {
		this->ballMovementY = this->ballMovementY * -1;
		Point2D newPos = currentPos + Point2D(0, this->ballMovementY);
	}
	this->ball.setPos(newPos);
	this->breakBrick();
}
void Breakout::breakBrick() {
	Point2D currentPos = this->ball.getPos();
	if (this->ball.getPos().gety() - this->ball.getRad() <= this->wall[0][0].getPos().gety() + (this->wall[0][0].getHeight() / 2)) {
		for (int i = 0; i < wall[0].size(); i++) {
			if (wall[0][i].getPos().getx() - (wall[0][i].getWidth() / 2) <= this->ball.getPos().getx() - this->ball.getRad()) {
				if (this->ballMovementY < 0) {
					this->ballMovementY = this->ballMovementY * -1;
					Point2D newPos = currentPos + Point2D(0, this->ballMovementY);
				}
				wall[0].erase(wall[0].begin() + i);
			}
		}
	}
}