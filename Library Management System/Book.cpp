#include "Book.h"

Book::Book(const std::string& title, const std::string& author, const std::string& genre) :
	m_title{ title }, m_author{ author }, m_genre{ genre }, m_status{ true } {}

void Book::set_title(const std::string& title) {
	m_title = title;
}

void Book::set_author(const std::string& author) {
	m_author = author;
}

void Book::set_genre(const std::string& genre) {
	m_genre = genre;
}

void Book::set_status(bool status) {
	m_status = status;
}

void Book::set_date(time_t& time) {
	m_due_date = time;
}

time_t Book::get_date() const {
	return m_due_date;
}

std::string Book::get_title() const {
	return m_title;
}

std::string Book::get_author() const {
	return m_author;
}

std::string Book::get_genre() const {
	return m_genre;
}

bool Book::get_status() const {
	return m_status;
}