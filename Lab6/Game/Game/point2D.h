#pragma once

#include <iostream>
#include <math.h>
#include <string>

// 
// // class declarations
// 

class Point2D {
private:
	float x, y;
public:
	// Constructor for incerting x and y.
	Point2D(float x, float y);
	// Copy constructor.
	Point2D(const Point2D& p);
	// Empty constructor.
	Point2D();

	float distance(Point2D p);

	float getx();
	float gety();

	std::string toString();

	Point2D operator+(const Point2D& p);

	Point2D operator-(const Point2D& p);

	void operator=(const Point2D& p);

	bool operator==(const Point2D& p);
	bool operator!=(const Point2D& p);

	void print();
};
