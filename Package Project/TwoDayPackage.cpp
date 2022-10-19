#include "TwoDayPackage.h"
#include<iostream>

TwoDayPackage::TwoDayPackage(const std::string& name, const std::string& adress, const std::string& city, const std::string& state, int ZIP, double w, double cost, double fee) :
	Package(name, adress, city, state, ZIP, w, cost) {
	bool hasError = false;
	try { setFlatFee(fee); }
	catch (int ex) { std::cout << "Flat fee must be > 0.0" << std::endl; hasError = true; }
	// used to undo the ID increase in case the object passes the base class constructor but not this one
	(hasError) ? ID-- : ID = ID;
}

void TwoDayPackage::setFlatFee(double fee) {
	if (fee <= 0) throw 1;
	this->fee = fee;
}

double TwoDayPackage::calculateCost() const {
	return Package::calculateCost() + fee;
}

void TwoDayPackage::printPackageInfo() const {
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "Two Day Package id " << ID << ':' << std::endl;
	std::cout << std::endl;
	std::cout << name << std::endl;
	std::cout << address << std::endl;
	std::cout << city << ", " << state << ' ' << ZIP << std::endl;
	std::cout << std::endl;
	std::cout << "Cost: $" << calculateCost() << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
}