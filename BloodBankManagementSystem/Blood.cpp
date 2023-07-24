#include "Blood.hpp"

Blood::Blood(const double count, const std::string& type) : m_type{ type }, m_count{ count } {}

void Blood::set_count(const double c) {
	m_count = c;
}

double Blood::get_count() const {
	return m_count;
}

void Blood::set_type(const std::string& type) {
	m_type = type;
}

std::string Blood::get_type() const {
	return m_type;
}
