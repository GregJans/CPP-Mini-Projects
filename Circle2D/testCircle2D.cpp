#include "Circle2D.h"
#include<iostream>

int main()
{
	Circle2D* pCir1 = new Circle2D(2, 2, 5.5);
	Circle2D cir2(-6, -3, 1.5);

	std::cout << "Number of objects is " << pCir1->getNumberOfCircles() << std::endl;

	Circle2D cir3(cir2);

	std::cout << "Number of objects is " << cir3.getNumberOfCircles() << std::endl;

	std::cout << "pCir1 overlaps cir2 = " << pCir1->overlaps(cir2) << std::endl;
	std::cout << "cir3 overlaps cir2 = " << cir3.overlaps(cir2) << std::endl;

	delete pCir1;
	std::cout << "Number of objects is " << Circle2D::getNumberOfCircles();

}