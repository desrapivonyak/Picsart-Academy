#include "Consumption.h"
#include <iostream>

void Consumption::set_consumption(const Customer& customerID, const std::string& start, const std::string& end, double consumption) {
	m_consumption.customerID = customerID;
	m_consumption.consumption = consumption;
	m_consumption.startDate = start;
	m_consumption.endDate = end;
}

std::pair<std::string, double> Consumption::get_consumption() const{
	return std::make_pair(m_consumption.customerID.get_name(), m_consumption.consumption);
}

std::pair<std::string, std::string> Consumption::get_period() const {
	return std::make_pair(m_consumption.startDate, m_consumption.endDate);
}

void Consumption::add_consumption() {
	std::cout << "Consumption input.\n";
	m_consumption.customerID.registeration();
	std::cout << "Enter consumption period in format DD-MM-YYYY:\n";
	std::cout << "Start date:\n";
	std::string date;
	std::cin >> date;
	m_consumption.startDate = date;
	std::cout << "End date:\n";
	std::cin >> date;
	m_consumption.endDate = date;
	std::cout << "Enter customer's consumption:\n";
	double c;
	std::cin >> c;
	m_consumption.consumption = c;
}