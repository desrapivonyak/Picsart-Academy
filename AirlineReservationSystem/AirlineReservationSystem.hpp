#pragma once
#include "Flights.hpp"
#include "User.hpp"
#include <vector>

class AirlineReservationSystem
{
public:
	AirlineReservationSystem() = default;
	~AirlineReservationSystem() = default;
public:
	void add_flight(Flight*);
	std::vector<Flight*> get_flights() const;
	Flight* search_by_origin(const std::string&);
	Flight* search_by_destination(const std::string&);
	Flight* search_by_date(const Date&);
	void book_flight(const User&, Flight*);
private:
	void generate_ticket();
private:
	std::vector<Flight*> flights;
	std::string m_ticket;
};

