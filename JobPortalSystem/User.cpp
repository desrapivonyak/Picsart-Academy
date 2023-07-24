#include "User.hpp"

User::User(const std::string& name, const std::string& contact, const std::string& resume, const int salary) :
	m_name{ name }, m_contact{ contact }, m_resume{ resume }, m_salary_exceptions{ salary } {}

void User::set_name(const std::string& name) {
	m_name = name;
}

void User::set_contact(const std::string& contact) {
	m_contact = contact;
}
	
void User::set_resume(const std::string& resume) {
	m_resume = resume;
}
	
void User::set_salary(const int salary) {
	m_salary_exceptions = salary;
}
	
void User::add_notification(const std::string & noti) {
	m_notifications.push_back(noti);
}
	
int User::get_salaray() const {
	return m_salary_exceptions;
}
	
std::string User::get_name() const {
	return m_name;
}
	
std::string User::get_contact() const {
	return m_contact;
}
	
std::string User::get_resume() const {
	return m_resume;
}
	
std::vector<std::string> User::get_notifications() const
{
	return m_notifications;
}