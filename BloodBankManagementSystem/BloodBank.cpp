#include "BloodBank.hpp"
#include "Donor.hpp"
#include <vector>
#include <fstream>
#include <iostream>

std::vector<std::pair<Blood, Date>> BloodBank::get_units() const {
	return m_blood_units;
}

void BloodBank::donation(Donor* donor, const Date& date) {
	Operation operation;
	operation.operation_type = "Blood donation ";
	m_blood_units.push_back(std::make_pair(donor->get_blood(), date));
	operation.blood_type = donor->get_blood().get_type();
	operation.counts_ml = donor->get_blood().get_count() * 0.01;
	operation.donation_date = date;
	m_operations.push_back(operation);
}

void BloodBank::utilization(const int curr_year) {
	m_blood_units.erase(
		std::remove_if(m_blood_units.begin(), m_blood_units.end(), [this, &curr_year](const std::pair<Blood, Date>& unit) {
			if (unit.second.year <= curr_year - 5) {
				Operation operation;
				operation.operation_type = "Blood utilization ";
				operation.blood_type = unit.first.get_type();
				operation.counts_ml = unit.first.get_count() * 0.01;
				operation.donation_date = { unit.second.day, unit.second.month, curr_year };
				m_operations.push_back(operation);
				return true;
			} 
			return false;}), m_blood_units.end());
}

void BloodBank::search_blood(const std::string& b_type) {
	for (auto& unit : get_units()) {
		if (unit.first.get_type() == b_type) {
			std::cout << "We have blood of that type." << std::endl;
			return;
		}
	}
	std::cout << "There is not that type of blood in our bank." << std::endl;
}

void BloodBank::generate_report() {
	std::string report = "";
	for (auto& op : m_operations) {
		report += "--------------------------------------------\n";
		report += op.operation_type + "details:\n";
		report += "Date - ";
		report += std::to_string(op.donation_date.day);
		report += "/";
		report += std::to_string(op.donation_date.month);
		report += "/";
		report += std::to_string(op.donation_date.year) + "\n";
		report += "Blood count in ml - " + std::to_string(op.counts_ml) + " ml\nBlood type - " + op.blood_type + "\n";
	}
	std::cout << report << std::endl;
	std::ofstream output("Report.txt");
	if (output.is_open()) {
		output << report << std::endl;
		output.close();
		std::cout << "Report generated." << std::endl;
	}
	else {
		std::cout << "Failed to generate report." << std::endl;
	}
}