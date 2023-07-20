#pragma once
#include "Consumption.h"

class Calculation
{
public:
	Calculation() = default;
	~Calculation() = default;
public:
	void set_per_unit();
	const int get_per_unit() const;
	double calculate(const Consumption&);
	std::string generate_report(const Consumption&);
	void report_to_console(const Consumption&);
	void report_to_txt(const Consumption&);
private:
	std::string get_current_time();
private:
	int m_per_unit;
};

