#ifndef CIRCLE2D_H
#define CIRCLE2D_H
class Circle2D
{
public:
	Circle2D(double x = 0, double y = 0, double radius = 0);
	Circle2D(const Circle2D& other);
	~Circle2D();

	double getX() const;
	double getY() const;
	double getRadius() const;

	static int numberOfCircles;
	static int getNumberOfCircles();

	bool overlaps(const Circle2D& circle);

private:
	double x, y;
	double radius;
};
#endif


