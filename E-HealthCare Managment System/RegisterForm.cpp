#include "RegisterForm.hpp"
#include <stdexcept>

void RegisterForm::set_name(const std::string& name) {
	m_name = name;
}

void RegisterForm::set_contact(unsigned int contact) {
	if (std::to_string(contact).length() == 10) {
		m_contact = contact;
	}
	else {
		throw std::runtime_error("Invalid number!");
	}
}

std::string RegisterForm::get_name() const {
	return m_name;
}


std::string RegisterForm::get_contact() const {
	std::string result = "+1 ";
	for (int i = 0; i < 10; ++i) {
		if (i == 3) {
			result += ' ';
		}
		result += std::to_string(m_contact)[i];
	}
	return result;
}