#ifndef COMPLEX_H
#define COMPLEX_H

class Complex
{
public:
	Complex();
	Complex(double newReal, double newImg);

	//getters
	double getReal() const;
	double getImg() const;

	//setters
	void setReal(double newReal);
	void setImg(double newImg);

	void printComplex() const;
	Complex addition(Complex &comp);

private:
	double real;
	double img;
};

#endif

