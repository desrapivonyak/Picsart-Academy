#pragma once
#include "Donor.hpp"
#include <vector>
#include <fstream>

struct Date {
	int day{ 1 };
	int month{ 1 };
	int year{ 1990 };
};

struct Operation {
	std::string operation_type;
	double counts_ml;
	std::string blood_type;
	Date donation_date;
};


class BloodBank
{
public:
	BloodBank() = default;
	~BloodBank() = default;
public:
	std::vector<std::pair<Blood, Date>> get_units() const;
	void donation(Donor*, const Date&);
	void utilization(const int);
	void search_blood(const std::string&);
	void generate_report();
private:
	std::vector<Operation> m_operations;
	std::vector<std::pair<Blood, Date>> m_blood_units;
};

