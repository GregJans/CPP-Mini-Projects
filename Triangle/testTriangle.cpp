#include "Triangle.h"

int main() {
    Triangle t1(4, 4, 4, "Red", false);
    Triangle t2(5, 5, 2, "Green", true);
    Triangle t3(5.5, 5.5, 1, "Blue", true);

    t1.display();
    t2.display();
    t3.display();

    std::cout << " (t1 < t2) = " << (t1 < t2) << std::endl;
    std::cout << " (t3 >= t2) = " << (t3 >= t2) << std::endl;
    std::cout << " (t3 != t1) = " << (t3 != t1) << std::endl;
}