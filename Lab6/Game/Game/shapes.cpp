
#include <iostream>
#include <math.h>

#include "shapes.h"

Shape::Shape(Point2D pos, int color[4]) {
	this->pos = pos;
	for (int i = 0; i < 4; i++) {
		if (color[i] < 0 || color[i] > 255) {
			printf("\nERROR: Invalid color value, setting color value of ");
			switch (i)
			{
			case 0:
				printf("Red to 0\n");
				this->color[i] = 0;
				break;
			case 1:
				printf("Green to 0\n");
				this->color[i] = 0;
				break;
			case 2:
				printf("Blue to 0\n");
				this->color[i] = 0;
				break;
			case 3:
				printf("Alpha to 0\n");
				this->color[i] = 0;
				break;
			default:
				break;
			}
		}
		else
			this->color[i] = color[i];
	}
}
Shape::Shape() {
	this->pos = Point2D(0, 0);
	this->color[0] = 0;
	this->color[1] = 0;
	this->color[2] = 0;
	this->color[3] = 0;
}
void Shape::setPos(Point2D pos) {
	this->pos = pos;
}
Point2D Shape::getPos() {
	return this->pos;
}
int* Shape::getColor() {
	return this->color;
}

Rectangle::Rectangle(Point2D pos, int color[4], float width, float height)
	: Shape(pos, color) {
	this->width = width;
	this->height = height;
	this->halfWidth = width / 2;
	this->halfHeight = height / 2;
}
Rectangle::Rectangle()
	: Shape() {
	this->width = 0;
	this->height = 0;
	this->halfWidth = 0;
	this->halfHeight = 0;
}
void Rectangle::render(SDL_Renderer* renderer) {
	Point2D pos = this->getPos();
	//std::string sPos = pos.toString();
	int* color = this->getColor();
	//printf("\nRectangle\nPos:\t%s\nWidth / Height:\t%g / %g\n", sPos.c_str(), this->width, this->height);

	// Set draw color
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
	// Draw shape
	SDL_RenderDrawLine(renderer, pos.getx() + halfWidth, pos.gety() - halfHeight, pos.getx() - halfWidth, pos.gety() - halfHeight);
	SDL_RenderDrawLine(renderer, pos.getx() - halfWidth, pos.gety() - halfHeight, pos.getx() - halfWidth, pos.gety() + halfHeight);
	SDL_RenderDrawLine(renderer, pos.getx() - halfWidth, pos.gety() + halfHeight, pos.getx() + halfWidth, pos.gety() + halfHeight);
	SDL_RenderDrawLine(renderer, pos.getx() + halfWidth, pos.gety() + halfHeight, pos.getx() + halfWidth, pos.gety() - halfHeight);
}

Triangle::Triangle(Point2D pos, int color[4], float base, float height)
	: Shape(pos, color) {
	this->base = base;
	this->height = height;
	this->halfBase = base / 2;
	this->halfHeight = height / 2;
}
Triangle::Triangle()
	: Shape() {
	this->base = 0;
	this->height = 0;
	this->halfBase = 0;
	this->halfHeight = 0;
}
void Triangle::render(SDL_Renderer* renderer) {
	Point2D pos = this->getPos();
	//std::string sPos = pos.toString();
	int* color = this->getColor();
	//printf("\nTriangle\nPos:\t%s\nBase / Height:\t%g / %g\n", sPos.c_str(), this->base, this->height);

	// Set draw color
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
	// Draw shape
	SDL_RenderDrawLine(renderer, pos.getx(), pos.gety() - halfHeight, pos.getx() - halfBase, pos.gety() + halfHeight);
	SDL_RenderDrawLine(renderer, pos.getx() - halfBase, pos.gety() + halfHeight, pos.getx() + halfBase, pos.gety() + halfHeight);
	SDL_RenderDrawLine(renderer, pos.getx() + halfBase, pos.gety() + halfHeight, pos.getx(), pos.gety() - halfHeight);
}

Circle::Circle(Point2D pos, int color[4], float radius)
	: Shape(pos, color) {
	this->radius = radius;
}
Circle::Circle()
	: Shape() {
	this->radius = 0;
}
void Circle::render(SDL_Renderer* renderer) {
	Point2D pos = this->getPos();
	//std::string sPos = pos.toString();
	int* color = this->getColor();
	//printf("\nCircle\nPos:\t%s\nRadius:\t%g\n", sPos.c_str(), this->radius);

	// Set draw color
	SDL_SetRenderDrawColor(renderer, color[0], color[1], color[2], color[3]);
	// Amount of points.
	int points = 20;
	// The step size.
	float step = 360 / points;
	// Degrees starting at 0.
	float degree = 0.0f;
	// Draw shape
	while (degree < 360) {
		float x1 = cos(degree * (PI / 180)) * this->radius + pos.getx();
		float y1 = sin(degree * (PI / 180)) * this->radius + pos.gety();
		degree += step;
		float x2 = cos(degree * (PI / 180)) * this->radius + pos.getx();
		float y2 = sin(degree * (PI / 180)) * this->radius + pos.gety();
		//printf("\nx1: %g\ty1: %g\nx2: %g\ty2: %g\n", x1, y1, x2, y2);
		SDL_RenderDrawLine(renderer, x1, y1, x2, y2);
	}
}