#pragma once
#include "Expense.hpp"
#include <vector>
#include <map>

class Tracker
{
public:
	Tracker() = default;
	~Tracker() = default;
public:
	void add_expense(const Expense&);
	std::vector<Expense> get_expenses() const;
	void generate_report_by_category();
	void generate_reoprt_weekly();
	void generate_report_monthly();
	void save_report_to_file();
private:
	std::string m_report;
	std::vector<std::vector<Expense>> m_weekly_report;
	std::vector<std::vector<Expense>> m_monthly_report;
	std::map<std::string, int> m_by_category;
	std::vector<Expense> m_expences;
};

