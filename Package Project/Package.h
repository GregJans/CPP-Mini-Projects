#ifndef PACKAGE_H
#define PACKAGE_H
#include<string>

class Package
{
public:
	static int ID;
	//constructor
	Package(const std::string& name, const std::string& adress, const std::string& city, const std::string& state, int ZIP, double weight, double cost);
	//mutators
	void setWeight(double weight);
	void setCostPerOunce(double cost);
	//general functions
	double calculateCost() const;
	void printPackageInfo() const;

protected:
	std::string name, address, city, state;
	int ZIP;
	double cost, weight;
};

#endif