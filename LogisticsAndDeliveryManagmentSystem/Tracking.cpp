#include "Tracking.hpp"
#include <iostream>
#include <fstream>

void Tracking::add_deliveries(Deliveries* delivery) {
	m_deliveries.push_back(delivery);
}

std::vector<Deliveries*> Tracking::get_deliveries() const {
	return m_deliveries;
}

std::string Tracking::track_status(Deliveries* delivery) {
	if (delivery->get_status() == PICKUP) {
		return "Your item is in warehouse.";
	}
	else if (delivery->get_status() == ON_TRANSIT) {
		return "Your item is on its way";
	}
	return "Your item delivered.";
}

void Tracking::change_status(Deliveries* delivery) {
	if (delivery->get_status() == PICKUP) {
		delivery->set_status(ON_TRANSIT);
	}
	else if (delivery->get_status() == ON_TRANSIT) {
		delivery->set_status(DELIVERED);
	}
}

Date Tracking::schedule_delivery(Deliveries* delivery) {
	Date estimated_date{};

	if (delivery->get_register_time().month == 12) {
		estimated_date.year = delivery->get_register_time().year + 1;
	}
	else {
		estimated_date.month = delivery->get_register_time().month + 1;
		estimated_date.year = delivery->get_register_time().year;
	}

	bool k = delivery->get_register_time().month == 4 ||
		delivery->get_register_time().month == 6 ||
		delivery->get_register_time().month == 9 ||
		delivery->get_register_time().month == 11;

	if (delivery->get_register_time().day >= 19)
	{

		if (delivery->get_register_time().month == 2) {
			estimated_date.day = 12 - (28 - delivery->get_register_time().day);
		}
		else if (k) {
			estimated_date.day = 12 - (30 - delivery->get_register_time().day);
		}
		else {
			if (delivery->get_register_time().day == 19) {
				estimated_date.day = 31;
			}
			else {
				estimated_date.day = 12 - (31 - delivery->get_register_time().day);
			}
		}
	}
	else {
		estimated_date.day = delivery->get_register_time().day + 12;
	}
	return estimated_date;
}

void Tracking::generate_receipt() {
	std::string receipt;
	for (auto item : m_deliveries) {
		receipt = item->get_item() + "\nfrom: " + item->get_origin() + "\nto: " + item->get_destination();
		receipt += "\nregistered on: " + std::to_string(item->get_register_time().day) + "/" + std::to_string(item->get_register_time().month);
		receipt += "/" + std::to_string(item->get_register_time().year);
		receipt += "\nestimated delivery time: " + std::to_string(schedule_delivery(item).day) + "/";
		receipt += std::to_string(schedule_delivery(item).month) + "/" + std::to_string(schedule_delivery(item).year);
		std::cout << receipt << std::endl;
		std::string filename = std::to_string(item->get_register_time().year) + std::to_string(item->get_register_time().month) +
			std::to_string(item->get_register_time().day) + item->get_item();
		std::ofstream output(filename + ".txt");
		if (output.is_open()) {
			output << receipt << std::endl;
			output.close();
		}
	}
}