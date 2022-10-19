#pragma once
#include<vector>
#include<string>

template<typename T>
class Matrix {
public:
	Matrix(std::vector<std::vector<T>>&);
	Matrix(int nRows, int nCols);

	void print() const;
	Matrix operator+(const Matrix&);
	Matrix operator*(const Matrix&);

	std::string getAttendance() const;

private:
	//two dimanesional vector (a vector of vectors)
	std::vector<std::vector<T>> data;

	int getRows() const;
	int getCols() const;

};