#pragma once
#include <string>

class Customer
{
public:
	Customer() = default;
	~Customer() = default;
public:
	void set_name(const std::string&);
	void set_contact(const std::string&);
	void set_meter(const int);
	std::string get_name() const;
	std::string get_contact() const;
	int get_meter() const;
	void registeration();
private:
	std::string m_name;
	std::string m_contact;
	int m_meter;
};

