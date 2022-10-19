#include "Circle2D.h"
#include<cmath>

Circle2D::Circle2D(double x, double y, double radius) {
	this->x = x;
	this->y = y;
	this->radius = radius;
	numberOfCircles++;
}
Circle2D::Circle2D(const Circle2D& other) {
	this->x = other.getX();
	this->y = other.getY();
	this->radius = other.getRadius();
	numberOfCircles++;
}
Circle2D::~Circle2D() {
	numberOfCircles--;
}

double Circle2D::getX() const { return x; }
double Circle2D::getY() const { return y; }
double Circle2D::getRadius() const { return radius; }

int Circle2D::numberOfCircles = 0;
int Circle2D::getNumberOfCircles() { return numberOfCircles; }

bool Circle2D::overlaps(const Circle2D& circle)
{
	//NOTE: for overlap, get distance between points and subtract both radii
	// if the result is > 0 they do not overlap
	double distanceBetweenCenters = sqrt(pow(x - circle.getX(), 2) + pow(y - circle.getY(), 2));
	double gapSize = distanceBetweenCenters - (radius + circle.getRadius());

	return gapSize <= 0;
}