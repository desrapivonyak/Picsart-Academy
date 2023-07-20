#pragma warning(disable: 4996)
#include "Patient.hpp"
#include <iostream>
#include <stdexcept>
#include <fstream>

void Patient::set_gender(char gender) {
	if (gender == 'M' || gender == 'm') {
		m_gender = "Male";
	}
	if(gender == 'f' || gender == 'F') {
		m_gender = "Female";
	}
	else {
		m_gender = "Other";
	}
}

void Patient::set_birthday(const DateOfBirth& birthday) {
	if (birthday.day > 31 || birthday.month == 0 || birthday.month > 12 || (birthday.month == 2 && birthday.day > 29)) {
		throw std::runtime_error("Invalid data!");
	}
	m_bithday.day = birthday.day;
	m_bithday.month = birthday.month;
	m_bithday.year = birthday.year;
}

void Patient::set_medhistory(const MedicalHistory& medhistory) {
	
	for (auto& diagnosis : medhistory.diagnoses) {
		m_medhistory.addDiagnosis(diagnosis);
	}
	
	for (auto& treatment : medhistory.treatments) {
		m_medhistory.addTreatment(treatment);
	}

	for (auto& medication : medhistory.medications) {
		m_medhistory.addMedication(medication);
	}
}

std::string Patient::get_gender() const {
	return m_gender;
}

std::string Patient::get_birthday() const {
	std::string result = "";
	result += std::to_string(m_bithday.day);
	result += "/";
	result += std::to_string(m_bithday.month);
	result += "/";
	result += std::to_string(m_bithday.year);
	return result;
}

std::string Patient::get_medhistory() const {
	std::string result{};
	result += "Diagnoses:\n";
	for (auto& diagnosis : m_medhistory.diagnoses) {
		result += "-" + diagnosis;
	}
	result += "\nTreatments:\n";
	for (auto& treatment : m_medhistory.treatments) {
		result += "-" + treatment;
	}
	result += "\nMedications:\n";
	for (auto& medication : m_medhistory.medications) {
		result += "-" + medication;
	}
	return result;
}

std::string Patient::get_current_time() {
	auto now = std::chrono::system_clock::now();
	std::time_t currentTime = std::chrono::system_clock::to_time_t(now);

	std::tm* localTime = std::localtime(&currentTime);
	char buffer[80];
	std::strftime(buffer, sizeof(buffer), "%Y%m%d", localTime);

	return std::string(buffer);
}

void Patient::set_report() {
	std::string report = "Details about patient:";
	report += "\n----------------------------------------\n";
	report += "Name: " + this->get_name() + "\nGender : " + this->get_gender();
	report += "\nBirthday: " + this->get_birthday();
	report += "\nContact: " + this->get_contact();
	report += "\n----------------------------------------\n";
	report += "\nMedical History Report for " + this->get_name() + ":\n";
	report += "----------------------------------------\n";
	report += this->get_medhistory();
	m_report = report;
}

std::string Patient::get_report() const {
	return m_report;
}

void Patient::registeration() {
	std::string input;
	std::cout << "Enter patient's name:" << std::endl;
	std::cin >> input;
	set_name(input);

	char g;
	std::cout << "Enter patient's gender (M/F):" << std::endl;
	std::cin >> g;
	set_gender(g);

	DateOfBirth birth{};
	std::cout << "Enter patient's birthday:" << std::endl;
	std::cout << "Day of the birth:" << std::endl;
	std::cin >> birth.day;
	std::cout << "Month of the birth:" << std::endl;
	std::cin >> birth.month;
	std::cout << "Year of the birth:" << std::endl;
	std::cin >> birth.year;
	set_birthday(birth);

	MedicalHistory med;
	std::cout << "Enter patient's medical conditions:" << std::endl;
	std::string diagnosis, treatment, medication;
	char addMore;
	do {
		std::cout << "Enter diagnosis: ";
		std::cin >> diagnosis;
		med.addDiagnosis(diagnosis);

		std::cout << "Enter treatment: ";
		std::cin >> treatment;
		med.addTreatment(treatment);

		std::cout << "Enter medication: ";
		std::cin >> medication;
		med.addMedication(medication);

		std::cout << "Add more medical records? (Y/N): ";
		std::cin >> addMore;
	} while (addMore == 'Y' || addMore == 'y');
	set_medhistory(med);

	unsigned int num{};
	std::cout << "Enter patient's contact information:" << std::endl;
	std::cin >> num;
	set_contact(num);
}

void Patient::report_to_console() {
	std::cout << "\nHere is detailed report about patient:\n";
	std::cout << get_report() << std::endl;
}

void Patient::report_to_txt() {
	std::cout << this->get_current_time();
	std::string filename = get_name() + "_" + this->get_current_time() + ".txt";
	std::ofstream output(filename);
	if (output.is_open()) {
		output << get_report() << "\n";
		std::cout << "Report created successfully!" << std::endl;
		output.close();
	}
	else {
		std::cout << "Failed to create report!" << std::endl;
	}
}