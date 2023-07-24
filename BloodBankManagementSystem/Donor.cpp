#include "Donor.hpp"

Donor::Donor(const std::string& name, const std::string& contact, const Blood& blood) : m_name{ name }, m_contact{ contact }, m_blood{ blood } {}

void Donor::set_contact(const std::string& contact) {
	m_contact = contact;
}

std::string Donor::get_contact() const {
	return m_contact;
}

void Donor::set_name(const std::string& name) {
	m_name = name;
}

std::string Donor::get_name() const {
	return m_name;
}

Blood Donor::get_blood() const {
	return m_blood;
}