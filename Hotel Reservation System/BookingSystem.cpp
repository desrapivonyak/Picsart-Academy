#include "BookingSystem.h"
#include <iostream>
#include <fstream>

BookingSystem::BookingSystem(Room* room) {
	m_rooms.push_back(room);
}

void BookingSystem::add_room(Room* room) {
	m_rooms.push_back(room);
}

void BookingSystem::set_cost(const Room& room, int days) {
	if (room.get_type() == Type::SINGLE) {
		m_cost_for_reservation = room.get_cost() * days;
	}
	else if (room.get_type() == Type::DOUBLE) {
		m_cost_for_reservation = room.get_cost() * days;
	}
	else if (room.get_type() == Type::SUIT) {
		m_cost_for_reservation = room.get_cost() * days;
	}
}

int BookingSystem::get_bill () const {
	return m_cost_for_reservation;
}

void BookingSystem::book_single(Customer* customer, unsigned int days) {
	bool ind;
	for (auto room : m_rooms) {
		if (room->get_type() == SINGLE && room->get_status())
		{
			set_cost(*room, days);
			m_bill = "Single room reserved by " + customer->get_name() + " for " + std::to_string(days) + " days ";
			m_bill += " and overall bill is " + std::to_string(get_bill()) + " AMD.";
			room->set_status(false);
			ind = false;
			break;
		}
		else {
			ind = true;
		}
	}
	if (ind) {
		std::cout << "There wasn't single room availible for reservation." << std::endl;
	}
}

void BookingSystem::book_double(Customer* customer, unsigned int days) {
	bool ind;
	for (auto room : m_rooms) {
		if (room->get_type() == DOUBLE && room->get_status())
		{
			set_cost(*room, days);
			m_bill = "Double room reserved by " + customer->get_name() + " for " + std::to_string(days) + " days ";
			m_bill += " and overall bill is " + std::to_string(get_bill()) + " AMD.";
			room->set_status(false);
			ind = false;
			break;
		}
		else {
			ind = true;
		}
	}
	if (ind) {
		std::cout << "There wasn't double room availible for reservation." << std::endl;
	}
}

void BookingSystem::book_suit(Customer* customer, unsigned int days) {
	bool ind;
	for (auto room : m_rooms) {
		if (room->get_type() == SUIT && room->get_status())
		{
			set_cost(*room, days);
			m_bill = "Suit room reserved by " + customer->get_name() + " for " + std::to_string(days) + " days ";
			m_bill += " and overall bill is " + std::to_string(get_bill()) + " AMD.";
			room->set_status(false);
			ind = false;
			break;
		}
		else {
			ind = true;
		}
	}
	if (ind) {
		std::cout << "There wasn't suit room availible for reservation." << std::endl;
	}
}

void BookingSystem::bill_to_console() {
	std::cout << m_bill << std::endl;
	bill_to_txt();
}

void BookingSystem::bill_to_txt() {
	std::string filename = "Bill.txt";
	std::ofstream output(filename, std::ios::app);
	if (output.is_open()) {
		output << m_bill << std::endl;
		std::cout << "Bill saved successfully!" << std::endl;
		output.close();
	}
	else {
		std::cout << "Failed to save bill!" << std::endl;
	}
}