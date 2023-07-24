#include "Travel.hpp"

Travel::Travel(const std::string& dest, const int price, const int slots)
	: m_destination{ dest }, m_price{ price }, m_slots{ slots } {}

void Travel::set_destination(const std::string& dest) {
	m_destination = dest;
}

std::string Travel::get_destination() const {
	return m_destination;
}

void Travel::set_price(const int price) {
	m_price = price;
}

int Travel::get_price() const {
	return m_price;
}

void Travel::set_slots(const int slots) {
	m_slots = slots;
}

int Travel::get_slots() const {
	return m_slots;
}