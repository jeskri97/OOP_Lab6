#pragma once

#include "SDL.h"
#include <iostream>
#include <math.h>
#include "point2D.h"

#ifndef PI
#define PI    3.14159265358979323846264338327950288
#endif

class Shape {
private:
	// The shapes position
	Point2D pos;
	// Red, Green, Blue, Alpha
	int color[4];
public:
	Shape(Point2D pos, int color[4]);
	Shape();

	virtual void render(SDL_Renderer* renderer) = 0;

	void setPos(Point2D pos);
	void setColor(int red, int green, int blue, int alpha);

	Point2D getPos();
	int* getColor();
};

class Rectangle : public Shape {
private:
	float width, height, halfWidth, halfHeight;
public:
	Rectangle(Point2D pos, int color[4], float width, float height);
	Rectangle();
	void render(SDL_Renderer* renderer);
	void setVal(int width, int height);
	float getWidth();
	float getHeight();
};

class Triangle : public Shape {
private:
	float base, height, halfBase, halfHeight;
public:
	Triangle(Point2D pos, int color[4], float base, float height);
	Triangle();
	void render(SDL_Renderer* renderer);
	void setVal(int base, int height);
};

class Circle : public Shape {
private:
	float radius;
public:
	Circle(Point2D pos, int color[4], float radius);
	Circle();
	void render(SDL_Renderer* renderer);
	void setRad(int radius);
	float getRad();
};