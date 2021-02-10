
#include <iostream>

#include "point2D.h"

// 
// // class definitions
// 

// Constructor for incerting x and y.
Point2D::Point2D(float x, float y) {
	this->x = x;
	this->y = y;
}
Point2D::Point2D(const Point2D& p) {
	this->x = p.x;
	this->y = p.y;
}
Point2D::Point2D() {
	this->x = 0.0f;
	this->y = 0.0f;
}

float Point2D::distance(Point2D p) {
	// distance = sqrt((x_2-x_1)²+(y_2-y_1)²)
	return sqrt((p.getx() - this->x) * (p.getx() - this->x) + (p.gety() - this->y) * (p.gety() - this->y));
}
float Point2D::getx() { return this->x; }
float Point2D::gety() { return this->y; }

std::string Point2D::toString() {
	std::string s = "[";
	s += std::to_string(this->x);
	s += ",";
	s += std::to_string(this->y);
	s += "]";
	return s;
}

Point2D Point2D::operator+(const Point2D& p) {
	float xi, yi;
	xi = this->x + p.x;
	yi = this->y + p.y;
	return Point2D(xi, yi);
}
Point2D Point2D::operator-(const Point2D& p) {
	float xi, yi;
	xi = this->x - p.x;
	yi = this->y - p.y;
	return Point2D(xi, yi);
}
void Point2D::operator=(const Point2D& p) {
	this->x = p.x;
	this->y = p.y;
}

bool Point2D::operator==(const Point2D& p) {
	return (this->x == p.x && this->y == p.y);
}
bool Point2D::operator!=(const Point2D& p) {
	return !(this->x == p.x && this->y == p.y);
}

void Point2D::print() {
	printf("x / y : %g / %g\n", this->x, this->y);
}