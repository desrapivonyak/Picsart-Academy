#pragma once
#include "RegisterForm.hpp"
#include <chrono>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>

struct MedicalHistory {
	std::vector<std::string> diagnoses;
	std::vector<std::string> treatments;
	std::vector<std::string> medications;
	void addDiagnosis(const std::string& diagnosis) {
		diagnoses.push_back(diagnosis);
	}
	void addTreatment(const std::string& treatment) {
		treatments.push_back(treatment);
	}

	void addMedication(const std::string& medication) {
		medications.push_back(medication);
	}
};

struct DateOfBirth {
	unsigned int day{ 1 };
	unsigned int month{ 1 };
	unsigned int year{ 1900 };
};

class Patient : public RegisterForm
{
public:
	void set_gender(char);
	void set_birthday(const DateOfBirth&);
	void set_medhistory(const MedicalHistory&);
	std::string get_gender() const;
	std::string get_birthday() const;
	std::string get_medhistory() const;
	std::string get_current_time();
	void set_report();
	std::string get_report() const;
	void registeration() override;
	void report_to_console();
	void report_to_txt();
private:
	std::string m_gender;
	DateOfBirth m_bithday;
	MedicalHistory m_medhistory;
	std::string m_current_time;
	std::string m_report;
};