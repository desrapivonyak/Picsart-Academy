#include "AirlineReservationSystem.hpp"
#include <iostream>
#include <fstream>

void AirlineReservationSystem::add_flight(Flight* flight) {
	flights.push_back(flight);
}

std::vector<Flight*> AirlineReservationSystem::get_flights() const {
	return flights;
}

Flight* AirlineReservationSystem::search_by_origin(const std::string& origin) {
	for (auto flight : flights) {
		if (flight->get_origin() == origin) {
			return flight;
		}
	}
	return NULL;
}

Flight* AirlineReservationSystem::search_by_destination(const std::string& dest) {

	for (auto flight : flights) {
		if (flight->get_destination() == dest) {
			return flight;
		}
	}
	return NULL;
}

Flight* AirlineReservationSystem::search_by_date(const Date& date) {
	for (auto flight : flights) {
		if (flight->get_date().day == date.day && flight->get_date().day == date.day && flight->get_date().day == date.day)
		{
			return flight;
		}
	}
	return NULL;
}

void AirlineReservationSystem::book_flight(const User& user, Flight* fl) {
	for (auto flight : flights) {
		if (fl->get_flight_number() == flight->get_flight_number()) {
			if (flight->get_available_seats() == 0) {
				m_ticket = "There is no available seats in this flight.\n";
			}
			else {
				m_ticket = "Ticket owner: " + user.get_name();
				m_ticket += "\nDeparture from : " + flight->get_origin();
				m_ticket += "\nArrival to : " + flight->get_destination();
				m_ticket += "\nDeparture date : " + std::to_string(flight->get_date().day);
				m_ticket += "/" + std::to_string(flight->get_date().month);
				m_ticket += "/" + std::to_string(flight->get_date().year);
				fl->set_seats(fl->get_available_seats() - 1);
			}
		}
		else {
			m_ticket = "There is no such flight.\n";
		}
		generate_ticket();
	}
}

void AirlineReservationSystem::generate_ticket() {
	std::cout << m_ticket << std::endl;
	std::string filename = "ticket.txt";
	std::ofstream output(filename);
	if (output.is_open()) {
		output << m_ticket << std::endl;
		std::cout << "Ticket generated successfully!" << std::endl;
		output.close();
	}
	else {
		std::cout << "Ticket generation failed!" << std::endl;
	}
}