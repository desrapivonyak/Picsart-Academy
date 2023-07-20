#pragma once
#include "Interation.h"
#include "Sale.h"

class Waranty : public Interation
{
public:
	Waranty() = default;
	~Waranty() = default;
public:
	void set_cost(const double);
	void set_sale(const Sale&);
	double get_cost() const;
	Sale get_sale() const;
	void register_interation() override;
	std::string inter_info() override;
private:
	double m_cost;
	Sale m_sale;
};

