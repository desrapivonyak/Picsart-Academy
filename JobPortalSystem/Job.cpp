#include "Job.hpp"

Job::Job(const std::string& title, const std::string& descr, const std::string& req, const std::string& comp, const int sal) :
	m_title{ title }, m_description{ descr }, m_requirments{ req }, m_company{ comp }, m_salary { sal }, m_status{ true } {}

void Job::set_title(const std::string& title) {
	m_title = title;
}

void Job::set_description(const std::string& desc) {
	m_description = desc;
}

void Job::set_requirments(const std::string& req) {
	m_requirments = req;
}
	
void Job::set_company(const std::string& comp) {
	m_company = comp;
}
	
void Job::set_status(const bool st) {
	m_status = st;
}
	
void Job::set_salary(const int salary) {
	m_salary = salary;
}
	
bool Job::get_status() const {
	return m_status;
}
	
int Job::get_salary() const {
	return m_salary;
}
	
std::string Job::get_title() const {
	return m_title;
}
	
std::string Job::get_description() const {
	return m_description;
}
	
std::string Job::get_requirments() const {
	return m_requirments;
}
	
std::string Job::get_company() const {
	return m_company;
}