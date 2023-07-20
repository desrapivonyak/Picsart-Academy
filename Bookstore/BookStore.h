#pragma once
#include <vector>
#include "Book.h"
#include "Customer.h"

class BookStore
{
public:
	BookStore() {};
	BookStore(const std::vector<Book*>&, const std::vector<Customer*>&);
public:
	void add_books(Book*);
	void add_customers(Customer*);
	std::pair<int, int> book_purchase_history();
	void history_to_txt();
private:
	std::vector<Book*> m_books;
	std::vector<Customer*> m_customers;
};

