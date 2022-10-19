#include "Matrix.h"
#include<iostream>
#include<stdexcept>
#include<iomanip>
#include<string>

template <typename T>
Matrix<T>::Matrix(std::vector<std::vector<T>>& data) {
	this->data = data;
}
template <typename T>
Matrix<T>::Matrix(int nRows, int nCols) {
	if (nRows <= 0 || nCols <= 0) throw std::logic_error("Error creating Matrix");

	std::vector<T> test;
	for (int r = 0; r < nRows; r++) {
		for (int c = 0; c < nCols; c++) {
			test.push_back(T());
		}

		data.push_back(test);
	}
}

template <typename T>
Matrix<T> Matrix<T>::operator+(const Matrix& other) {
	if (getRows() != other.getRows() || getCols() != other.getCols()) throw std::logic_error("These two cannot be added");

	Matrix temp(getRows(), getCols());

	for (int r = 0; r < getRows(); r++) {
		for (int c = 0; c < getCols(); c++) {
			temp.data[r][c] = data[r][c] + other.data[r][c];
		}
	}
	return temp;
}

template<typename T>
Matrix<T> Matrix<T>::operator*(const Matrix& other) {
	if (getCols() != other.getRows()) throw std::logic_error("Incorrect dimensions");

	Matrix<T> result(getRows(), other.getCols());
	//T sum;
	
	for (int i = 0; i < result.getRows(); i++) {
		for (int j = 0; j < result.getCols(); j++) {
			for (int k = 0; k < getCols(); k++) {
				result.data[i][j] += this->data[i][k] * other.data[k][j];
			}
		}
	}
	

	return result;
}

template <typename T>
int Matrix<T>::getRows() const {
	return data.size();
}

template <typename T>
int Matrix<T>::getCols() const {
	// can check any row, just choosing the first one
	// in case the row is empty return 0
	return (data.empty()) ? 0 : data[0].size();
}

template <typename T>
void Matrix<T>::print() const {
	for (int r = 0; r < getRows(); r++) {
		for (int c = 0; c < getCols(); c++) {
			std::cout << std::setw(5) << data[r][c];
		}
		std::cout << std::endl;
	}
	std::cout << std::endl;
}

template <typename T>
std::string Matrix<T>::getAttendance() const {

	std::string result;
	char c = 0;

	for (int i = 0; i < getCols(); i++) {
		for (int j = 0; j < getRows(); j++) {
			c += data[i][j];
		}
		result.push_back(c);
	}

	return result;
}
