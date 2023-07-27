#pragma once
#include <string>

struct Date {
	int day{ 1 };
	int month{ 1 };
	int year{ 1990 };
};

class Expense
{
public:
	Expense(const int, const std::string&, const std::string&, const Date&);
	~Expense() = default;
public:
	void set_amount(const int);
	int get_amount() const;
	void set_category(const std::string&);
	std::string get_category() const;
	void set_description(const std::string&);
	std::string get_description() const;
	void set_date(const Date&);
	Date get_date() const;
private:
	int m_amount;
	std::string m_category;
	std::string m_description;
	Date m_date;
};