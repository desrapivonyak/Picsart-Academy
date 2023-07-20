#include "MedHistoryReportCreatation.hpp"
#include <fstream>

void MedHistoryReport::set_report(RegisterForm* user) {
    std::string report = "Details about patient:";
    report += "\n----------------------------------------\n";
    report += "Name: " + user->get_name() + "\nGender : " + dynamic_cast<Patient*>(user)->get_gender();
    report += "\nBirthday: " + dynamic_cast<Patient*>(user)->get_birthday();
    report += "\nContact: " + dynamic_cast<Patient*>(user)->get_contact();
    report += "\n----------------------------------------\n";
    report += "\nMedical History Report for " + user->get_name() + ":\n";
    report += "----------------------------------------\n";
    report += dynamic_cast<Patient*>(user)->get_medhistory();
    m_report = report;
}

std::string MedHistoryReport::get_report() const {
    return m_report;
}