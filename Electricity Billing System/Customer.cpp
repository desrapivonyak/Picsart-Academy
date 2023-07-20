#include "Customer.h"
#include <iostream>

void Customer::set_name(const std::string& name) {
	m_name = name;
}

void Customer::set_contact(const std::string& contact) {
	m_contact = contact;
}

void Customer::set_meter(const int meter) {
	m_meter = meter;
}

std::string Customer::get_name() const {
	return m_name;
}

std::string Customer::get_contact() const {
	return m_contact;
}

int Customer::get_meter() const {
	return m_meter;
}

void Customer::registeration() {
	std::cout << "Enter customer details:\nName:\n";
	std::string name;
	std::cin >> name;
	set_name(name);
	std::cout << "Contact information:\n";
	std::string contact;
	std::cin >> contact;
	set_contact(contact);
	std::cout << "Meter number:\n";
	int meter;
	std::cin >> meter;
	set_meter(meter);
}
