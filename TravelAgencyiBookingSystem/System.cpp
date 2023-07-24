#include "System.hpp"
#include <iostream>
#include <fstream>

void System::add_travel(Travel* travel) {
	m_travels.push_back(travel);
}

std::vector<Travel*> System::get_travel() const {
	return m_travels;
}

void System::search_by_price(const int price, const int slot) {
	for (auto travel : get_travel()) {
		if (travel->get_price() == price && travel->get_slots() >= slot) {
			std::cout << "Travel package found.\n" << std::endl;
			return;
		}
	}
	std::cout << "Travel package was not found." << std::endl;
}

void System::booking(Travel* travel, int tic_num) {
	for (auto t : get_travel()) {
		if (t->get_price() == travel->get_price() && t->get_slots() >= tic_num) {
			m_ticket = "Travel package information:";
			m_ticket += "\nDestination - " + t->get_destination() + "\nPackage price - " + std::to_string(t->get_price()) + " USD";
			m_ticket += "\nSlots - " + std::to_string(tic_num) + "\nTicket price - " + std::to_string(t->get_price() * tic_num) + " USD";
			generate_ticket();
			t->set_slots(t->get_slots() - tic_num);
			return;
		}
	}
	std::cout << "All tickets for that travel package were booked." << std::endl;
}

void System::generate_ticket() {
	std::cout << m_ticket << std::endl;
	std::ofstream output("ticket.txt");
	if (output.is_open()) {
		output << m_ticket << std::endl;
		output.close();
		std::cout << "Ticket created." << std::endl;
	}
	else {
		std::cout << "Failed to create ticket." << std::endl;
	}
}