#pragma once
#include "Customer.h"

struct ConsumptionRecord {
	Customer customerID;
	std::string startDate;
	std::string endDate;
	double consumption;
};

class Consumption
{
public:
	Consumption() = default;
	~Consumption() = default;
public:
	void set_consumption(const Customer&, const std::string&, const std::string&, double);
	std::pair<std::string, double> get_consumption() const;
	std::pair<std::string, std::string> get_period() const;
	void add_consumption();
private:
	ConsumptionRecord m_consumption;
};