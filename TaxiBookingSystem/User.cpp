#include "User.hpp"

User::User(const std::string& name, const std::string& contact) : m_name{ name }, m_contact{ contact } {}

void User::set_contact(const std::string& contact) {
	m_contact = contact;
}

std::string User::get_contact() const {
	return m_contact;
}

void User::set_name(const std::string& name) {
	m_name = name;
}

std::string User::get_name() const {
	return m_name;
}