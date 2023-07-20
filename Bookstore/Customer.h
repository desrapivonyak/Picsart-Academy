#pragma once
#include "Book.h"
#include <vector>
#include <map>

class Customer
{
public:
	Customer() {};
	Customer(const std::string&, const std::string&);
	~Customer() = default;
public:
	void set_name(const std::string&);
	void set_contact(const std::string&);
	void purchase(Book*, int);
	int calculate_total();
	std::pair<int, int> get_purchased_history() const;
	std::vector <Book*> get_purchased_books() const;
	std::string get_name() const;
	std::string get_contact() const;
	std::map<Book*, int> get_shopping_cart() const;
	void add_to_cart(Book*, int);
	void remove_from_cart(Book*, int);
private:
	std::string m_name;
	std::string m_contact;
	std::map<Book*, int> m_shopping_cart;
	int m_cart_total_cost;
	std::vector<Book*> m_purchased_books;
	int m_purchased_amount{};
	int m_purchased_count{};
};

