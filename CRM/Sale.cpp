#include "Sale.h"
#include <stdexcept>
#include <iostream>

void Sale::set_ammount(const double amount) {
	if (amount > 0) {
		m_ammount = amount;
	}
	else {
		throw std::runtime_error("Invalid amount!");
	}
}

void Sale::set_period(const int period) {
	if (period >= 0) {
		m_waranty_period = period;
	}
	else {
		throw std::runtime_error("The waranty period can not be less than 0 days!");
	}
}

void Sale::set_date(const Date& date) {
	m_date.day = date.day;
	m_date.month = date.month;
	m_date.year = date.year;
}

double Sale::get_ammount() const {
	return m_ammount;
}

int Sale::get_period() const {
	return m_waranty_period;
}

Date Sale::get_date() const {
	return m_date;
}

void Sale::register_interation() {
	std::cout << "Sale registeration started:\n";
	std::cout << "Enter amount:\n";
	double amount;
	std::cin >> amount;
	set_ammount(amount);
	int period;
	std::cout << "Enter warianty period in days:\n";
	std::cin >> period;
	set_period(period);
	std::cout << "Enter sale date (day, month, year):\n";
	Date date;
	std::cin >> date.day >> date.month >> date.year;
	set_date(date);
}

std::string Sale::inter_info() {
	std::string result{};
	result = "*Sale:\n";
	result += " -Date: " + std::to_string(get_date().day) + "-" + std::to_string(get_date().month) + "-" + std::to_string(get_date().year);
	result += "\n -Amount: " + std::to_string(get_ammount());
	result += "\n -Waranty period: " + std::to_string(get_period());
	return result;
}