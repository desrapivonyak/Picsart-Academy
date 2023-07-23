#include "Customer.hpp"

Customer::Customer(const std::string& name, const std::string& contact) : m_name{ name }, m_contact{ contact } {}

void Customer::set_name(const std::string& name) {
	m_name = name;
}

std::string Customer::get_name() const {
	return m_name;
}

void Customer::set_contact(const std::string& contact) {
	m_contact = contact;
}

std::string Customer::get_contact() const {
	return m_contact;
}