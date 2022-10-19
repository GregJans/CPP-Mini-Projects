#include "Package.h"
#include<iostream>

int Package::ID = 0;

//constructor
Package::Package(const std::string& name, const std::string& adress, const std::string& city, const std::string& state, int ZIP, double weight, double cost) {
	this->name = name;
	this->address = adress;
	this->city = city;
	this->state = state;
	this->ZIP = ZIP;

	bool hasError = false;
	try { setWeight(weight); }
	catch (int ex) { std::cout << "Weight must be > 0.0" << std::endl; hasError = true; }
	try { setCostPerOunce(cost); }
	catch (int ex) { std::cout << "Cost must be > 0.0" << std::endl; hasError = true; }

	// only add to the ID counter if the package was made sucessfully
	(hasError) ? ID = ID : ID++;
}


//mutators
void Package::setWeight(double weight) {
	if (weight <= 0) throw 1;
	this->weight = weight;
}
void Package::setCostPerOunce(double cost) {
	if (cost <= 0) throw 1;
	this->cost = cost;
}

//general functions
double Package::calculateCost() const {
	return weight * cost;
}
void Package::printPackageInfo() const {
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "Package id " << ID << ':' << std::endl;
	std::cout << std::endl;
	std::cout << name << std::endl;
	std::cout << address << std::endl;
	std::cout << city << ", " << state << ' ' << ZIP << std::endl;
	std::cout << std::endl;
	std::cout << "Cost: $" << calculateCost() << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
}
