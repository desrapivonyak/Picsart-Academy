#include "Member.h"

void Member::set_name(const std::string& name) {
	m_name = name;
}

void Member::set_contact(const std::string& contact) {
	m_contact = contact;
}

void Member::add_borrowed(Book* book) {
	m_borrowed.push_back(book);
}

void Member::return_borrowed(Book* book) {
	m_borrowed.pop_back();
}

std::string Member::get_name() const {
	return m_name;
}

std::string Member::get_contact() const {
	return m_contact;
}

std::vector<Book*> Member::get_borrowed() const {
	return m_borrowed;
}