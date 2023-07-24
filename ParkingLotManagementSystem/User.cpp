#include "User.hpp"

User::User(const std::string& name, const SIZE& size) : m_name{ name }, m_vehicle_size{ size } {}

void User::set_name(const std::string& name) {
	m_name = name;
}

std::string User::get_name() const {
	return m_name;
}

void User::set_size(const SIZE& size) {
	m_vehicle_size = size;
}

SIZE User::get_size() const {
	return m_vehicle_size;
}
