#include "LotManagement.hpp"
#include <iostream>
#include <fstream>

void LotManagement::add_spaces(Parking* parking) {
	m_parking_spaces.push_back(parking);
}

std::vector<Parking*> LotManagement::get_spaces() const {
	return m_parking_spaces;
}

std::string LotManagement::get_reciept() const {
	return m_reciept;
}

void LotManagement::set_fee(const int min_fee) {
	m_fee = min_fee;
}

int LotManagement::get_fee() const {
	return m_fee;
}

void LotManagement::calculate_fee(const User& user, const int duration) {
	switch (user.get_size())
	{
	case SIZE::COMPACT:
		set_fee(duration * SIZE::COMPACT);
		break;
	case SIZE::LARGE:
		set_fee(duration * SIZE::LARGE);
		break;
	case SIZE::REGULAR:
		set_fee(duration * SIZE::REGULAR);
		break;
	default:
		break;
	}
}

void LotManagement::reserve_space(const User& user, const int duration) {
	for (auto space : get_spaces()) {
		if (space->get_size() == user.get_size() && space->get_status()) {
			space->set_status(false);
			calculate_fee(user, duration);
			m_reciept = "Parking space reserved by " + user.get_name();
			m_reciept += " for " + std::to_string(duration) + " minutes.";
			m_reciept += "\nThe fee will be " + std::to_string(get_fee()) + " AMD.";
			return;
		}
	}
	std::cout << "There was not an available space for your car." << std::endl;
}

void LotManagement::generate_reciept() {
	std::cout << get_reciept() << std::endl;
	std::ofstream output("Parking.txt");
	if (output.is_open()) {
		output << get_reciept() << std::endl;
		output.close();
		std::cout << "Receipt generated." << std::endl;
	}
	else {
		std::cout << "Receipt generation failed." << std::endl;
	}
}