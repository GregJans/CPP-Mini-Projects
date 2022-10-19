#include "Complex.h"
#include<iostream>

Complex::Complex() {
	setReal(0.0);
	setImg(0.0);
}

Complex::Complex(double newReal, double newImg) {
	setReal(newReal);
	setImg(newImg);
}

//getters
double Complex::getReal() const { return real; }
double Complex::getImg() const { return img; }

//setters
void Complex::setReal(double newReal) { real = newReal; }
void Complex::setImg(double newImg) { img = newImg; }

void Complex::printComplex() const {
	// manualy putting the + and - to keep the printouts consistant with the demo given
	// ex: prints 3 - 4i rather than 3 -4i
	std::cout << getReal() << ((getImg() < 0) ? " - " : " + ") << abs(getImg()) << 'i' << std::endl;
}

Complex Complex::addition(Complex& comp) {
	double newReal = getReal() + comp.getReal();
	double newImg = getImg() + comp.getImg();

	return Complex(newReal, newImg);
}
