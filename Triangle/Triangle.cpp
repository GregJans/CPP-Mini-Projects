#include "Triangle.h"

Triangle::Triangle() : GeometricObject() {
    side1 = side2 = side3 = 1.0;
}
Triangle::Triangle(double side1, double side2, double side3, const std::string& color, bool filled) : GeometricObject(color, filled) {
    this->side1 = side1;
    this->side2 = side2;
    this->side3 = side3;
}

bool Triangle::operator<(const Triangle& other) const {
    if (!isFilled() && other.isFilled()) return true;
    return getPerimeter() < other.getPerimeter();
}
bool Triangle::operator>=(const Triangle& other) const {
    return !(*this < other);
}
bool Triangle::operator!=(const Triangle& other) const {
    return (getPerimeter() != other.getPerimeter() || (isFilled() && !other.isFilled()));
}

double Triangle::getPerimeter() const {
    return (side1 + side2 + side3);
}

double Triangle::getArea() const {
    double p = (side1 + side2 + side3) / 2;
    return sqrt(p * (p - side1) * (p - side2) * (p - side3));
}

void Triangle::display() const {
    std::cout << std::left << std::setw(16) << " Area:" << std::setw(13) << getArea() << std::endl;
    std::cout << std::left << std::setw(16) << " Perimeter:" << std::setw(13) << getPerimeter() << std::endl;
    std::cout << std::left << std::setw(16) << " Color:" << std::setw(13) << getColor() << std::endl;
    std::cout << std::left << std::setw(16) << " Filled:" << std::setw(13) << isFilled() << std::endl;
    std::cout << " _____________________________" << std::endl;
}