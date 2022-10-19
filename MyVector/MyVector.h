#ifndef MYVECTOR_H
#define MYVECTOR_H


template<typename T>
class MyVector
{
public:
	MyVector();
	MyVector(const MyVector& other);
	~MyVector();

	// Class Functions
	void push_back(T value); //adds new element to end of vector
	void print() const; // prints content of vector
	T pop_back(); // returns the last element and removes it from vector
	void clear();

	//Added functions for assignment
	void deleteElement(int index);
	void removeDuplicate();
	void sort();


private:
	T* elements;
	unsigned vectorSize, vectorCapacity;
};

#endif



