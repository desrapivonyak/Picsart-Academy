#pragma once
#include "Room.h"
#include "Customer.h"
#include <vector>

class BookingSystem
{
public:
	BookingSystem() {};
	BookingSystem(Room*);
	~BookingSystem() = default;
public:
	void add_room(Room*);
	void set_cost(const Room&, int);
	int get_bill() const;
	void book_single(Customer*, unsigned int);
	void book_double(Customer*, unsigned int);
	void book_suit(Customer*, unsigned int);
	void bill_to_console();
	void bill_to_txt();
private:
	std::vector<Room*> m_rooms;
	unsigned int m_cost_for_reservation;
	std::string m_bill;
};

