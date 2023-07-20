#pragma once
#include "Interation.h"
#include "Customer.h"

struct Date {
	int day{ 1 };
	int month{ 1 };
	int year{ 1900 };
};

class Sale : public Interation
{
public:
	Sale() = default;
	~Sale() = default;
public:
	void set_ammount(const double);
	void set_period(const int);
	void set_date(const Date&);
	double get_ammount() const;
	int get_period() const;
	Date get_date() const;
	void register_interation() override;
	std::string inter_info() override;
private:
	double m_ammount;
	int m_waranty_period;
	Date m_date;
};