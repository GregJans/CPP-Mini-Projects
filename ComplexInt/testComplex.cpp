#include "Complex.h"

Complex additionTwo(Complex& comp1, Complex& comp2);
Complex additionArray(Complex complexArray[], int size);

int main() 
{
	Complex c1;
	c1.setReal(2.4);
	c1.setImg(4.1);

	Complex c2(3.2, -3.6);

	// both commands should print the same value
	// .printComplex() will print what is returned by the first command
	c1.addition(c2).printComplex();
	additionTwo(c1, c2).printComplex();

	// complex numbers in arr are random values
	Complex c_arr[] = {Complex(1, 4), Complex(3, -6), Complex(5, -1), Complex(2, 7), Complex(2.5, -0.8)};
	//second parameter math is used to get the size of the array (protects hard-coding a size value)
	additionArray(c_arr, sizeof(c_arr) / sizeof(c_arr[0])).printComplex();
}

Complex additionTwo(Complex& comp1, Complex& comp2) {
	return comp1.addition(comp2);
}

Complex additionArray(Complex complexArray[], int size) {
	Complex sum;

	for (int i = 0; i < size; i++) {
		sum = sum.addition(complexArray[i]);
	}

	return sum;
}