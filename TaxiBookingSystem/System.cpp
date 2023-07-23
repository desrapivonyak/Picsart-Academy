#include "System.hpp"
#include <iostream>
#include <fstream>

void System::add_taxi(Taxi* taxi) {
	m_taxies.push_back(taxi);
}

void System::calculate_ride(Taxi* taxi, const int distance) {
	m_fee = m_min_fee + taxi->get_coefficient() * (distance - 3) * 100;
}

void System::book_taxi(const User& user, const int dest) {
	for (auto taxi : m_taxies) {
		if (taxi->get_status()) {
			calculate_ride(taxi, dest);
			taxi->set_status(false);
			m_receipt = "Taxi booked by " + user.get_name();
			m_receipt += "\nDriver is " + taxi->get_driver();
			m_receipt += "\nRide fee will be " + std::to_string(m_fee) + " AMD\n";
			generate_receipt();
			return;
		}
	}
	std::cout << "There is not any available taxi right now." << std::endl;
}

void System::generate_receipt() {
	std::cout << m_receipt << std::endl;
	std::ofstream output("Receipt.txt");
	if (output.is_open()) {
		output << m_receipt << std::endl;
		output.close();
		std::cout << "Receipt created successfully." << std::endl;
	}
	else {
		std::cout << "Failed to create receipt." << std::endl;
	}
}

