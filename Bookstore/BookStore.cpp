#include "BookStore.h"
#include <fstream>
#include <iostream>

BookStore::BookStore(const std::vector<Book*>& books, const std::vector<Customer*>& customers) :
	m_books(books), m_customers(customers) {}

void BookStore::add_books(Book* book) {
	m_books.push_back(book);
}

void BookStore::add_customers(Customer* customer) {
	m_customers.push_back(customer);
}

std::pair<int, int> BookStore::book_purchase_history() {
	int count{};
	int amount{};
	for (auto customer : m_customers) {
		amount += customer->get_purchased_history().second;
		count += customer->get_purchased_history().first;
	}
	return std::make_pair(count, amount);
}

void BookStore::history_to_txt() {
	std::string filename = "Bookstore_history.txt";
	std::ofstream output(filename);
	if (output.is_open()) {
		output << "Purchase book history: " << book_purchase_history().first << " books for " << book_purchase_history().second << "AMD\n";
		std::cout << "File created successfully." << std::endl;
		output.close();
	}
	else {
		std::cout << "Failed to create file." << std::endl;
	}
}