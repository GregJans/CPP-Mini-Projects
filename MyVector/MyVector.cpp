#include "MyVector.h"
#include <iostream>

template<typename T>
MyVector<T>::MyVector()
{
	vectorSize = 0;
	vectorCapacity = 10;
	elements = new T[vectorCapacity];
}

template<typename T>
MyVector<T>::MyVector(const MyVector& other)
{
	this->vectorSize = other.vectorSize;
	this->vectorCapacity = other.vectorCapacity;
	this->elements = new T[vectorCapacity];

	for (int i = 0; i < vectorSize; i++) {
		this->elements[i] = other.elements[i];
	}
}
template<typename T>
MyVector<T>::~MyVector()
{
	delete[] elements;
}

// TODO
template<typename T>
void MyVector<T>::push_back(T value)
{
	if (vectorSize < vectorCapacity) {
		elements[vectorSize] = value;
		vectorSize++;
	}
	else {
		this->vectorCapacity *= 2;
		T* temp = elements;
		elements = new T[vectorCapacity];

		for (int i = 0; i < vectorSize; i++) {
			this->elements[i] = temp[i];
		}

		delete[] temp;
		push_back(value);
	}
}//adds new element to end of vector

template<typename T>
void MyVector<T>::print() const
{
	for (int i = 0; i < vectorSize; i++) {
		std::cout << elements[i] << ' ';
	}
	std::cout << std::endl;
}// prints content of vector

template<typename T>
T MyVector<T>::pop_back()
{
	if (vectorSize == 0) return T(); //return default value for whatever type
	else return elements[--vectorSize];
}// returns the last element and removes it from vector

template<typename T>
void MyVector<T>::clear()
{
	delete[] elements;
	vectorSize = 0;
	vectorCapacity = 10;
	T* elements = new T[vectorCapacity];
}

template<typename T>
void MyVector<T>::deleteElement(int index)
{
	// makes sure index is within a valid range
	if (0 <= index && index <= vectorSize) {
		for (index; index < vectorSize; index++) {
			elements[index] = elements[index + 1];
		}
		// removes the last element since it is a duplicate
		this->pop_back();


		if (vectorSize <= vectorCapacity / 2) {
			vectorCapacity /= 2;
			T* temp = elements;
			elements = new T[vectorCapacity];

			for (int i = 0; i < vectorSize; i++) {
				elements[i] = temp[i];
			}

			delete[] temp;
		}
	}
}

template<typename T>
void MyVector<T>::removeDuplicate()
{
	// loop through each element
	for (int i = 0; i < vectorSize; i++) {
		// loop thriugh the rest of the elements to compare
		for (int j = i + 1; j < vectorSize; j++) {
			if (elements[i] == elements[j]) {
				this->deleteElement(j);
			}
		}
	}
}

template<typename T>
void MyVector<T>::sort() 
{
	int minValueIndex;
	for (int currentIteration = 0; currentIteration < vectorSize; currentIteration++) {
		minValueIndex = currentIteration;
		for (int i = currentIteration; i < vectorSize; i++) {
			if (elements[i] < elements[minValueIndex]) {
				minValueIndex = i;
			}
		}
		// swap the min value and the value at the currentIteration index
		T temp = elements[currentIteration];
		elements[currentIteration] = elements[minValueIndex];
		elements[minValueIndex] = temp;
	}
}

