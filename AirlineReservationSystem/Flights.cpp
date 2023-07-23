#include "Flights.hpp"

Flight::Flight(const int number, const int seats, const std::string& origin, const std::string& dest, const Date& date) :
	m_flight_num{ number }, m_available_seats{ seats }, m_origin{ origin }, m_destination{ dest }, m_date{ date } {}

void Flight::set_flight_number(const int num) {
	m_flight_num = num;
}

int Flight::get_flight_number() const {
	return m_flight_num;
}

void Flight::set_seats(const int seats) {
	m_available_seats = seats;
}

int Flight::get_available_seats() const {
	return m_available_seats;
}

void Flight::set_origin(const std::string& origin) {
	m_origin = origin;
}

std::string Flight::get_origin() const {
	return m_origin;
}

void Flight::set_destination(const std::string& dest) {
	m_destination = dest;
}

std::string Flight::get_destination() const {
	return m_destination;
}

void Flight::set_date(const Date& date) {
	m_date = date;
}

Date Flight::get_date() const {
	return m_date;
}

