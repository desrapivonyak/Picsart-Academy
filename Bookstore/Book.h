#pragma once
#include <string>

class Book
{
public:
	Book() {};
	Book(const std::string&, const std::string&, int, int);
public:
	void set_title(const const std::string&);
	void set_author(const std::string&);
	void set_price(int);
	void set_quantity(int);
	std::string get_title() const;
	std::string get_author() const;
	int get_price() const;
	int get_quantity() const;
private:
	std::string m_title;
	std::string m_author;
	int m_price;
	int m_quantity;
};

