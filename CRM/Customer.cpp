#pragma warning(disable: 4996)
#include "Customer.h"
#include <iostream>
#include <fstream>
#include <chrono>
#include <stdexcept>
#include "Sale.h"
#include "Waranty.h"
#include "Complaint.h"
#include <cstdio>

void Customer::set_name(const std::string& name) {
	m_name = name;
}

void Customer::set_contact(const unsigned int contact) {
	if (std::to_string(contact).length() < 6 || std::to_string(contact).length() > 20) {
		throw std::runtime_error("Invalid number!");
	}
	m_contact = contact;
}

std::string Customer::get_name() const {
	return m_name;
}

std::string Customer::get_contact() const {
	std::string result = "+(374) ";
	result += std::to_string(m_contact);
	return result;
}

void Customer::registeration() {
	std::cout << "Start customer registeration:\n";
	std::string name;
	std::cout << "Enter customers name:\n";
	std::cin >> name;
	set_name(name);
	std::cout << "Enter customers contact information:\n";
	int telephone;
	std::cin >> telephone;
	set_contact(telephone);
	char answer = 'Y';
	while (answer == 'Y' || answer == 'y') {
		std::cout << "What type of interation do you want to add? (1: Sale, 2: Warranty service, 3. Complaint)\n";
		int it_type;
		std::cin >> it_type;
		if (it_type == 1) {
			Interation* inter = new Sale();
			add_interation(inter);
			inter = nullptr;
		}
		else if (it_type == 2) {
			Interation* inter = new Waranty();
			add_interation(inter);
			inter = nullptr;
		}
		else if (it_type == 3)
		{
			Interation* inter = new Complaint();
			add_interation(inter);
			inter = nullptr;
		}
		std::cout << "Add another interation (Y/N)?\n";
		std::cin >> answer;
	}
}

void Customer::add_interation(Interation* inter) {
	inter->register_interation();
	m_history.push_back(inter);
}

std::string Customer::generate_report() {
	std::string report{};
	registeration();
	report += "Here is the detailed information about customer and his interation history : \n";
	report += "---------------------------------------------------------------------------\n";
	report += "Name: " + get_name() + "\nContact: " + get_contact();
	report += "\n---------------------------------------------------------------------------\n";
	report += "Interaion hystory:\n";
	int i = 1;
	for (auto inter : m_history) {
		report += "\n" + std::to_string(i) + ".-";
		report += inter->inter_info();
		++i;
	}
	report += "\n---------------------------------------------------------------------------\n";
	return report;
}

void Customer::report_to_console() {
	std::cout << generate_report() << std::endl;
}

std::string Customer::get_current_time() {
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	std::tm* localTime = std::localtime(&currentTime);
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d", localTime);

	return std::string(buffer);
}

void Customer::report_to_txt() {
	std::string report = generate_report();
	std::string filename = get_name() +"_" + get_current_time() + ".txt";
	std::ofstream output(filename);
	if (output.is_open()) {
		output << report << "\n";
		std::cout << "Report created successfully!" << std::endl;
		output.close();
	}
	else {
		std::cout << "Failed to create report!" << std::endl;
	}
}