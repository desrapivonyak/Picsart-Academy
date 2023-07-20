#include "Customer.h"

Customer::Customer(const std::string& name, const std::string& contact) : m_name(name), m_contact(contact) {}

void Customer::set_name(const std::string& name) {
	m_name = name;
}

void Customer::set_contact(const std::string& contact) {
	m_contact = contact;
}

std::string Customer::get_name() const {
	return m_name;
}

std::string Customer::get_contact() const {
	return m_contact;
}

std::map<Book*, int> Customer::get_shopping_cart() const {
	return m_shopping_cart;
}

void Customer::add_to_cart(Book* book, int quantity) {
	bool check_missing = true;
	for (auto& cart : m_shopping_cart) {
		if (cart.first->get_title() == book->get_title()) {
			check_missing = false;
			cart.second += quantity;
			break;
		}
	}
	if (check_missing) {
		m_shopping_cart[book] = quantity;
	}
}

void Customer::remove_from_cart(Book* book, int quantity) {
	for (auto& cart : m_shopping_cart) {
		if (cart.first->get_title() == book->get_title()) {
			if (cart.second >= quantity) {
				cart.second -= quantity;
			}
			else {
				cart.second = 0;
			}
		}
	}
}

int Customer::calculate_total() {
	m_cart_total_cost = 0;
	for (auto& cart : m_shopping_cart) {
		m_cart_total_cost += cart.first->get_price() * cart.second;
	}
	return m_cart_total_cost;
}

void Customer::purchase(Book* book, int count) {
	if (m_shopping_cart.find(book) == m_shopping_cart.end()) {
		add_to_cart(book, count);
	}
	remove_from_cart(book, count);
	m_purchased_books.push_back(book);
	m_purchased_amount += book->get_price() * count;
	m_purchased_count += count;
	book->set_quantity(book->get_quantity() - count);
	calculate_total();
}

std::pair<int, int> Customer::get_purchased_history() const {
	return std::make_pair(m_purchased_count, m_purchased_amount);
}

std::vector<Book*> Customer::get_purchased_books() const {
	return m_purchased_books;
}