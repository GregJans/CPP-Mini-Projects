#ifndef TRIANGLE_H
#define TRIANGLE_H
#include<iostream>
#include<iomanip>
#include<string>

class GeometricObject
{
public:
    GeometricObject() {
        color = "white";
        filled = false;
    }
    GeometricObject(const std::string& color, bool filled) {
        this->color = color;
        this->filled = filled;
    }
    std::string getColor() const {
        return color;
    }
    bool isFilled() const {
        return filled;
    }

private:
    std::string color;
    bool filled;
};

class Triangle : public GeometricObject
{
public:
    Triangle();
    Triangle(double side1, double side2, double side3, const std::string& color, bool filled);
        

    bool operator<(const Triangle& other) const;
    bool operator>=(const Triangle& other) const;
    bool operator!=(const Triangle& other) const;

    double getPerimeter() const;

    double getArea() const;

    void display() const;

private:
    double side1, side2, side3;
};

#endif