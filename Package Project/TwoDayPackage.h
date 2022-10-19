#ifndef TWODAYPACKAGE_H
#define TWODAYPACKAGE_H
#include "Package.h"

class TwoDayPackage : public Package
{
public:
	TwoDayPackage(const std::string& name, const std::string& adress, const std::string& city, const std::string& state, int ZIP, double w, double cost, double fee);

	void setFlatFee(double fee);

	double calculateCost() const;
	void printPackageInfo() const;
private:
	double fee;
};

#endif