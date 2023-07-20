#include "Doctor.hpp"
#include <stdexcept>
#include <iostream>

void Doctor::set_specalization(const std::string& specalization) {
	m_specalization = specalization;
}

void Doctor::set_yearsofexperience(unsigned int years) {
	if (years >= 0) {
		m_yearsofexperience = years;
	}
	else {
		throw std::runtime_error("Invalid number!");
	}
}

std::string Doctor::get_specialization() const {
	return m_specalization;
}

unsigned int Doctor::get_yearsofexperience() const {
	return m_yearsofexperience;
}

void Doctor::registeration() {
	std::string input;
	std::cout << "Enter doctor's name:" << std::endl;
	std::getline(std::cin, input);
	set_name(input);
	std::cout << "Enter doctor's specialization:" << std::endl;
	std::getline(std::cin, input);
	set_specalization(input);
	std::cout << "Enter doctor's years of experience:" << std::endl;
	std::getline(std::cin, input);
	set_yearsofexperience(std::stoul(input));
	std::cout << "Enter doctor's contact information:" << std::endl;
	std::getline(std::cin, input);
	set_contact(std::stoul(input));
}