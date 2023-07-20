#pragma warning(disable: 4996)
#include "Calculation.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <fstream>
#include <chrono>

void Calculation::set_per_unit() {
	std::cout << "Enter rate per unit for electricity:\n";
	int unit;
	std::cin >> unit;
	m_per_unit = unit;
}

const int Calculation::get_per_unit() const {
	return m_per_unit;
}

double Calculation::calculate(const Consumption& consum) {
	double cost = get_per_unit();
	cost *= consum.get_consumption().second;
	return cost;
}

std::string Calculation::generate_report(const Consumption& consum) {
	std::string report;
	report += consum.get_consumption().first + "'s electricity bill report from " + consum.get_period().first + " to " + consum.get_period().second + ":\n";
	report += "\nConsumption: " + std::to_string(consum.get_consumption().second) + "kWh";
	report += "\nRate per unit for electricity: " + std::to_string(get_per_unit()) + "AMD";
	report += "\nBill for the period: " + std::to_string(calculate(consum)) + "AMD\n";
	return report;
}

void Calculation::report_to_console(const Consumption& obj) {
	std::cout << generate_report(obj);
}

std::string Calculation::get_current_time() {
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);
	std::tm* localTime = std::localtime(&currentTime);
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d", localTime);

	return std::string(buffer);
}

void Calculation::report_to_txt(const Consumption& obj) {
	std::string report = generate_report(obj);
	std::string filename = obj.get_consumption().first + "_" + get_current_time() + ".txt";
	std::ofstream output(filename);
	if (output.is_open()) {
		output << report;
		std::cout << "Report created successfully!" << std::endl;
		output.close();
	}
	else {
		std::cout << "Failed to create report!" << std::endl;
	}
}