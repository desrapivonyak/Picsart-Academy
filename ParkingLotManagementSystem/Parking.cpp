#include "Parking.hpp"

Parking::Parking(const int num, const SIZE& size) : m_number{ num }, m_size{ size }, m_status{ true } {}

void Parking::set_status(bool st) {
	m_status = st;
}

bool Parking::get_status() const {
	return m_status;
}

void Parking::set_number(const int num) {
	m_number = num;
}

int Parking::get_number() const {
	return m_number;
}

void Parking::set_size(const SIZE& size) {
	m_size = size;
}

SIZE Parking::get_size() const {
	return m_size;
}