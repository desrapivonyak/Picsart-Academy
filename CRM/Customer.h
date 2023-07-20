#pragma once
#include "Interation.h"
#include <string>
#include <vector>

class Interation;

class Customer
{
public:
	Customer() = default;
	~Customer() = default;
public:
	void set_name(const std::string&);
	void set_contact(const unsigned int);
	std::string get_name() const;
	std::string get_contact() const;
	std::string generate_report();
	void registeration();
	void add_interation(Interation*);
	void report_to_console();
	std::string get_current_time();
	void report_to_txt();
private:
	std::vector<Interation*> m_history;
	std::string m_name;
	int m_contact;
};
