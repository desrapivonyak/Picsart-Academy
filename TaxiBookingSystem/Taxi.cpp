#include "Taxi.hpp"

Taxi::Taxi(const std::string& num, const std::string& driver, const Class& cl) :
	m_taxi_number{ num }, m_driver_name{ driver }, m_class{ cl }
{
	set_coefficient();
	set_status(true);
}

void Taxi::set_number(const std::string& num) {
	m_taxi_number = num;
}

std::string Taxi::get_number() const {
	return m_taxi_number;
}

void Taxi::set_driver(const std::string& driver) {
	m_driver_name = driver;
}

std::string Taxi::get_driver() const {
	return m_driver_name;
}

void Taxi::set_status(bool status) {
	m_status = status;
}

bool Taxi::get_status() const {
	return m_status;
}

void Taxi::set_class(const Class& cl) {
	m_class = cl;
}

Class Taxi::get_class() const {
	return m_class;
}

void Taxi::set_coefficient() {
	switch (get_class())
	{
	case START:
		m_coefficient = 1.0;
		break;
	case COMFORT:
		m_coefficient = 1.8;
		break;
	case BUISINESS:
		m_coefficient = 3.0;
		break;
	default:
		break;
	}
}

double Taxi::get_coefficient() const {
	return m_coefficient;
}