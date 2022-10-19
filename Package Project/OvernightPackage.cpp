#include "OvernightPackage.h"
#include<iostream>

OvernightPackage::OvernightPackage(const std::string& name, const std::string& adress, const std::string& city, const std::string& state, int ZIP, double w, double cost, double fee) :
	Package(name, adress, city, state, ZIP, w, cost) {
	bool hasError = false;
	try { setOvernightFeePerOunce(fee); }
	catch (int ex) { std::cout << "Overnight Fee must be > 0.0" << std::endl; hasError = true; }
	// used to undo the ID increase in case the object passes the base class constructor but not this one
	(hasError) ? ID-- : ID = ID;
}

double OvernightPackage::calculateCost() const {
	return (cost + fee) * weight;
}

void OvernightPackage::setOvernightFeePerOunce(double fee) {
	if (fee <= 0) throw 1;
	this->fee = fee;
}

void OvernightPackage::printPackageInfo() const {
	std::cout << "------------------------------------------------------" << std::endl;
	std::cout << "Overnight Package id " << ID << ':' << std::endl;
	std::cout << std::endl;
	std::cout << name << std::endl;
	std::cout << address << std::endl;
	std::cout << city << ", " << state << ' ' << ZIP << std::endl;
	std::cout << std::endl;
	std::cout << "Cost: $" << calculateCost() << std::endl;
	std::cout << "------------------------------------------------------" << std::endl;
}