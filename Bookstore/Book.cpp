#include "Book.h"

Book::Book(const std::string& title, const std::string& author, int price, int quantity) 
	: m_title{ title }, m_author{ author }, m_price{ price }, m_quantity{ quantity } {}

void Book::set_title(const std::string& title) {
	m_title = title;
}

void Book::set_author(const std::string& author) {
	m_author = author;
}

void Book::set_price(int price) {
	m_price = price;
}

void Book::set_quantity(int quantity) {
	m_quantity = quantity;
}

std::string Book::get_title() const {
	return m_title;
}

std::string Book::get_author() const {
	return m_author;
}

int Book::get_price() const {
	return m_price;
}

int Book::get_quantity() const {
	return m_quantity;
}