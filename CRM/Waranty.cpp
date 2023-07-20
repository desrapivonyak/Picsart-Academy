#include "Waranty.h"
#include <iostream>

void Waranty::set_cost(double cost) {
	m_cost = cost;
}

void Waranty::set_sale(const Sale& sale) {
	m_sale.set_ammount(sale.get_ammount());
	m_sale.set_period(sale.get_period());
	m_sale.set_date(sale.get_date());
}

double Waranty::get_cost() const {
	return m_cost;
}

Sale Waranty::get_sale() const {
	return m_sale;
}

void Waranty::register_interation() {
	std::cout << "Warranty registeration started:\n";
	std::cout << "Enter service cost:\n";
	double cost;
	std::cin >> cost;
	set_cost(cost);
	m_sale.register_interation();
}

std::string Waranty::inter_info() {
	std::string result{};
	result = "*Warranty:\n";
	result += " -Service cost: " + std::to_string(get_cost()) + "\n";
	result += m_sale.inter_info();
	return result;
}
