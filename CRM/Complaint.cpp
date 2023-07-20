#include "Complaint.h"
#include <iostream>

void Complaint::set_description(const std::string& description) {
	m_description = description;
}

void Complaint::set_sale(const Sale& sale) {
	m_sale.set_ammount(sale.get_ammount());
	m_sale.set_period(sale.get_period());
	m_sale.set_date(sale.get_date());
}

std::string Complaint::get_description() const {
	return m_description;
}

Sale Complaint::get_sale() const {
	return m_sale;
}

void Complaint::register_interation() {
	std::cout << "Complaint registeration started:\n";
	std::cout << "Enter complaint description:\n";
	std::string descr;
	std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	std::getline(std::cin, descr);
	set_description(descr);
	m_sale.register_interation();
}

std::string Complaint::inter_info() {
	std::string result{};
	result = "*Complaint:\n";
	result += " -Complaint description: " + get_description() + "\n";
	result += m_sale.inter_info();
	return result;
}
