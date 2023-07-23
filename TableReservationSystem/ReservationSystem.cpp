#include "ReservationSystem.hpp"
#include <iostream>
#include <fstream>

void ReservationSystem::add_table(Table* table) {
	m_tables.push_back(table);
}

std::vector<Table*> ReservationSystem::get_tables() const {
	return m_tables;
}

bool ReservationSystem::search_by_capacity(const int cap) {
	for (auto table : m_tables) {
		if (table->get_capacity() == cap) {
			return true;
		}
	}
	return false;
}

void ReservationSystem::reserve_table(const Customer& customer, const Date& date, Table* table) {
	for (auto t : m_tables) {
		if (t->get_status() && search_by_capacity(table->get_capacity())) {
			m_report = "Table reserved by " + customer.get_name();
			m_report += "\nTable number: " + std::to_string(t->get_table_number());				
			m_report += "\nSeats count: " + std::to_string(t->get_capacity());
			m_report += "\nReserved for: " + std::to_string(date.day) + "/" + std::to_string(date.month);
			m_report += "/" + std::to_string(date.year) + "\n";
			generate_report();
			return;
		}
	}
	std::cout << "The table could not be found or already reserved." << std::endl;
}

void ReservationSystem::generate_report() {
	std::cout << m_report << std::endl;
	std::ofstream output("Report.txt");
	if (output.is_open()) {
		output << m_report << std::endl;
		output.close();
		std::cout << "Report created successfully." << std::endl;
	}
	else {
		std::cout << "Failed to create report." << std::endl;
	}
}