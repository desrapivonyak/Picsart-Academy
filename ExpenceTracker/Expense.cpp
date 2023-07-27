#include "Expense.hpp"

Expense::Expense(const int amount, const std::string& category, const std::string& description, const Date& date)
	: m_amount{ amount }
	, m_category{ category }
	, m_description{ description }
	, m_date{ date }
{
}

void Expense::set_amount(const int amount) {
	m_amount = amount;
}

int Expense::get_amount() const {
	return m_amount;
}

void Expense::set_category(const std::string& category) {
	m_category = category;
}

std::string Expense::get_category() const {
	return m_category;
}

void Expense::set_description(const std::string& description) {
	m_description = description;
}

std::string Expense::get_description() const {
	return m_description;
}

void Expense::set_date(const Date& date) {
	m_date = date;
}

Date Expense::get_date() const {
	return m_date;
}