#ifndef OVERNIGHTPACKAGE_H
#define OVERNIGHTPACKAGE_H
#include "Package.h"

class OvernightPackage : public Package
{
public:
	OvernightPackage(const std::string& name, const std::string& adress, const std::string& city, const std::string& state, int ZIP, double w, double cost, double fee);

	double calculateCost() const;
	void setOvernightFeePerOunce(double fee);
	void printPackageInfo() const;
private:
	double fee;
};

#endif