#include "Rectangle2D.h"
#include<iostream>

int main()
{
	Rectangle2D r1(2, 2, 5.5, 4.9), r2(4, 5, 10.5, 3.2), r3(3, 5, 2.3, 5.4);

	std::cout << "r1 " << ((r1.contains(3, 3)) ? "does" : "does not") << " contain (3, 3)" << std::endl;
	std::cout << "r1 " << ((r1.contains(r2)) ? "does" : "does not") << " contain r2" << std::endl;
	std::cout << "r1 " << ((r1.overlaps(r3)) ? "does" : "does not") << " overlap r3" << std::endl;
}