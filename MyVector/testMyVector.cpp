#include "MyVector.h"
#include "MyVector.cpp"
#include<cstdlib>
#include<ctime>

void main()
{
	srand(time(NULL));

	MyVector<int> vec1;
	// adds 20 random numbers [0, 20]
	for (int i = 0; i < 20; i++) {
		vec1.push_back(rand() % 21);
	}

	std::cout << "The content of the vector is:" << std::endl;
	vec1.print();

	vec1.removeDuplicate();

	std::cout << std::endl << "The content of the vector after removing duplicates is:" << std::endl;
	vec1.print();

	vec1.sort();

	std::cout << std::endl << "The content of the vector after sorting is:" << std::endl;
	vec1.print();
}