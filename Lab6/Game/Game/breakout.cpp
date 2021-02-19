
#include "breakout.h"

Breakout::Breakout(std::vector<std::vector<Rectangle>> wall, int xRes, int yRes) {
	this->gameOver = false;
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
	// Set up the speed for the ball.
	srand(time(NULL));
	this->ballMovementX = xRes / 320 - (rand() % (xRes / 350) * 2);
	this->ballMovementY = yRes / 180;
}
void Breakout::render(SDL_Renderer* renderer) {
	// Render plank.
	this->plank.render(renderer);
	// Render wall bricks.
	int i_end = this->wall.size();
	for (int i = 0; i < i_end; i++) {
		int j_end = this->wall[i].size();
		for (int j = 0; j < j_end; j++) {
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

	// If going to hit the plank.
	if (this->ball.getPos().getx() - this->ball.getRad() <= this->plank.getPos().getx() + (this->plank.getWidth() / 2) &&
		this->ball.getPos().getx() + this->ball.getRad() >= this->plank.getPos().getx() - (this->plank.getWidth() / 2) &&
		this->ball.getPos().gety() - this->ball.getRad() <= this->plank.getPos().gety() + (this->plank.getHeight() / 2) &&
		this->ball.getPos().gety() + this->ball.getRad() >= this->plank.getPos().gety() - (this->plank.getHeight() / 2)) {
		// Bounce upwards.
		if (this->ballMovementY > 0)
			this->ballMovementY *= -1.01;

		if (this->ball.getPos().getx() < this->plank.getPos().getx() && this->ballMovementX > -(this->gameResY / 180))
			this->ballMovementX = this->ballMovementX - (this->gameResX / 1280);
		else if (this->ball.getPos().getx() > this->plank.getPos().getx() && this->ballMovementX < (this->gameResY / 180))
			this->ballMovementX = this->ballMovementX + (this->gameResX / 1280);
	}

	// Check if ball hits a brick.
	this->brickCheck();
	// End game if ball hits the bottom of the screen.
	if (newPos.gety() + this->ball.getRad() > this->gameResY) {
		this->gameOver = true;
	}
	// Bounce on walls.
	if (newPos.getx() - this->ball.getRad() < 0 || newPos.getx() + this->ball.getRad() > this->gameResX) {
		this->ballMovementX = this->ballMovementX * -1;
		Point2D newPos = currentPos + Point2D(this->ballMovementX, 0);
	}
	// Bounce on roof.
	if (newPos.gety() - this->ball.getRad() < 0) {
		this->ballMovementY = this->ballMovementY * -1;
		Point2D newPos = currentPos + Point2D(0, this->ballMovementY);
	}
	// Update the ball position.
	this->ball.setPos(newPos);
}
void Breakout::brickCheck() {
	Point2D currentPos = this->ball.getPos();
	float signX = 1, signY = 1;

	int tmp_i = -1, tmp_j = -1;
	float dx, dy;

	// Go trough every row.
	for (int i = 0; i < this->wall.size(); i++) {
		// Go trough every brick in row.
		for (int j = 0; j < wall[i].size(); j++) {

			// If inside brick bounds.
			if (this->ball.getPos().getx() - this->ball.getRad() <= this->wall[i][j].getPos().getx() + (this->wall[i][j].getWidth() / 2) &&
				this->ball.getPos().getx() + this->ball.getRad() >= this->wall[i][j].getPos().getx() - (this->wall[i][j].getWidth() / 2) &&
				this->ball.getPos().gety() - this->ball.getRad() <= this->wall[i][j].getPos().gety() + (this->wall[i][j].getHeight() / 2) &&
				this->ball.getPos().gety() + this->ball.getRad() >= this->wall[i][j].getPos().gety() - (this->wall[i][j].getHeight() / 2)) {

				float tmp_dx = this->ball.getPos().getx() - this->wall[i][j].getPos().getx();
				float tmp_dy = this->ball.getPos().gety() - this->wall[i][j].getPos().gety();
				if (tmp_i == -1) {
					dx = tmp_dx;
					dy = tmp_dy;
					tmp_i = i;
					tmp_j = j;
				}
				// If new radius is smaller.
				else if (tmp_dx * tmp_dx + tmp_dy * tmp_dy < dx * dx + dy * dy) {
					dx = tmp_dx;
					dy = tmp_dy;
					tmp_i = i;
					tmp_j = j;
				}
			}
		}
	}
	if (tmp_i != -1) {
		// Approaching from the side.
		if(dx == 0 || (abs(dy) / abs(dx)) < (this->wall[tmp_i][tmp_j].getHeight() / this->wall[tmp_i][tmp_j].getWidth()))
			this->ballMovementX *= -1.01;
		else
			this->ballMovementY *= -1.01;
		// Remove block.
		this->wall[tmp_i].erase(this->wall[tmp_i].begin() + tmp_j);
	}
}
bool Breakout::getGameOver() {
	return this->gameOver;
}