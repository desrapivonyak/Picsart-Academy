#include "Deliveries.hpp"

Deliveries::Deliveries(const std::string& item, const std::string& origin, const std::string& destination, const Date& date) 
	: m_item{ item }
	, m_origin{ origin }
	, m_destination{ destination }
	, m_date{ date }
	, m_status{ PICKUP }
{
}

void Deliveries::set_item(const std::string& item) {
	m_item = item;
}

std::string Deliveries::get_item() const {
	return m_item;
}

void Deliveries::set_origin(const std::string& origin) {
	m_origin = origin;
}

std::string Deliveries::get_origin() const {
	return m_origin;
}

void Deliveries::set_destination(const std::string& destination) {
	m_destination = destination;
}

std::string Deliveries::get_destination() const {
	return m_destination;
}

void Deliveries::set_register_time(const Date& date) {
	m_date.day = date.day;
	m_date.month = date.month;
	m_date.year = date.year;
}

Date Deliveries::get_register_time() const {
	return m_date;
}

void Deliveries::set_status(const TRACKING& status) {
	m_status = status;
}

TRACKING Deliveries::get_status() const {
	return m_status;
}