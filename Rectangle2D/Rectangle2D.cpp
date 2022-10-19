#include "Rectangle2D.h"

Rectangle2D::Rectangle2D() {
	setX(0);
	setY(0);
	setWidth(1);
	setHeight(1);
}
Rectangle2D::Rectangle2D(double newX, double newY, double newWidth, double newHeight) {
	setX(newX);
	setY(newY);
	setWidth(newWidth);
	setHeight(newHeight);
}

//getters
double Rectangle2D::getX() const { return x; }
double Rectangle2D::getY() const { return y; }
double Rectangle2D::getWidth() const { return width; }
double Rectangle2D::getHeight() const { return height; }
//setters
void Rectangle2D::setX(double newX) { x = newX; }
void Rectangle2D::setY(double newY) { y = newY; }
void Rectangle2D::setWidth(double newWidth) { width = newWidth; }
void Rectangle2D::setHeight(double newHeight) { height = newHeight; }

bool Rectangle2D::contains(double x, double y) const {
	bool inx, iny;
	inx = (getX() - getWidth() / 2) <= x && x <= (getX() + getWidth() / 2);
	iny = (getY() - getHeight() / 2) <= y && y <= (getY() + getHeight() / 2);

	return (inx && iny);
}
bool Rectangle2D::contains(const Rectangle2D& r) const {
	// if the center is not inside, the inner rectaangle will not be inside the outer
	if (!contains(r.getX(), r.getY())) return false;

	bool inx, iny;
	inx = (r.getX() - r.getWidth() / 2) >= (getX() - getWidth() / 2) && (getX() + getWidth() / 2) >= (r.getX() + r.getWidth() / 2);
	iny = (r.getY() - r.getHeight() / 2) >= (getY() - getHeight() / 2) && (getY() + getHeight() / 2) >= (r.getY() + r.getHeight() / 2);

	return (inx && iny);
}

bool Rectangle2D::overlaps(const Rectangle2D& r) const {
	// can skip function if we alredy know rectangle is contained / it must overlap
	if (contains(r)) return true;

	bool crossesTop, crossesBottom, crossesLeft, crossesRight;
	bool betweenX, betweenY;

	double objectLeft, objectRight, objectTop, objectBottom;
	double rLeft, rRight, rTop, rBottom;

	// storing the border locations so the math does not need to be repeated
	objectLeft = getX() - getWidth() / 2;
	objectRight = getX() + getWidth() / 2;
	objectTop = getY() + getHeight() / 2;
	objectBottom = getY() - getHeight() / 2;

	rLeft = r.getX() - r.getWidth() / 2;
	rRight = r.getX() + r.getWidth() / 2;
	rTop = r.getY() + r.getHeight() / 2;
	rBottom = r.getY() - r.getHeight() / 2;

	// checks if r crosses any of the borders of the object
	crossesLeft = rRight >= objectLeft && objectLeft >= rLeft ;
	crossesRight = rRight >= objectRight && objectRight >= rLeft;

	crossesBottom = rTop >= objectBottom && objectBottom >= rBottom;
	crossesTop = rTop >= objectTop && objectTop >= rBottom;

	// checks if the entirety of r is contained within two of the object's borders
	betweenX = rRight <= objectRight && rLeft >= objectLeft;
	betweenY = rTop <= objectTop && rBottom >= objectBottom;

	// checks if r crosses a border on each axis
	// ex: if r crosses the left border but is way above the object, then they do not overlap
	// if r crosses the left border but is inbetween the top and bottom border it should still overlap
	if (crossesLeft || crossesRight) {
		return (crossesBottom || crossesTop || betweenY);
	}
	else if (crossesBottom || crossesTop) {
		return (crossesLeft || crossesRight || betweenX);
	}
	else {
		return false;
	}
}