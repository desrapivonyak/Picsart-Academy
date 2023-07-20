#pragma once
#include "Book.h"
#include <vector>

class Member
{
public:
	Member() {}
	Member(const std::string& name, const std::string& contact) : m_name{name}, m_contact{contact} {}
	~Member() = default;
public:
	void set_name(const std::string&);
	void set_contact(const std::string&);
	void add_borrowed(Book*);
	void return_borrowed(Book*);
	std::string get_name() const;
	std::string get_contact() const;
	std::vector<Book*> get_borrowed() const;
private:
	std::string m_name;
	std::string m_contact;
	std::vector<Book*> m_borrowed;
};

