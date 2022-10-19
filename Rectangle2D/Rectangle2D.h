#ifndef RECTANGLE2D_H
#define RECTANGLE2D_H

class Rectangle2D
{
public:
	Rectangle2D();
	Rectangle2D(double newX, double newY, double newWidth, double newHeight);

	//getters
	double getX() const;
	double getY() const;
	double getWidth() const;
	double getHeight() const;
	//setters
	void setX(double newX);
	void setY(double newY);
	void setWidth(double newWidth);
	void setHeight(double newHeight);

	bool contains(double x, double y) const;
	bool contains(const Rectangle2D& r) const;

	bool overlaps(const Rectangle2D& r) const;
private:
	double x, y;
	double width, height;
};

#endif

