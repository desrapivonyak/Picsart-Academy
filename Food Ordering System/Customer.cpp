#include "Customer.h"

Customer::Customer(const std::string& name, const std::string& contact) : m_name(name), m_contact(contact) {}

void Customer::set_name(const std::string& name) {
	m_name = name;
}

void Customer::set_contact(const std::string& contact) {
	m_contact = contact;
}

void Customer::set_payment(const PaymentMethod& payment) {
	m_payment = payment;
}

std::string Customer::get_name() const {
	return m_name;
}

std::string Customer::get_contact() const {
	return m_contact;
}

PaymentMethod Customer::get_payment() const {
	return m_payment;
}
