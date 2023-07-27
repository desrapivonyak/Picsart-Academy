#include "Tracker.hpp"
#include <iostream>
#include <algorithm>
#include <fstream>

void Tracker::add_expense(const Expense& expense) {
	m_expences.push_back(expense);
}

std::vector<Expense> Tracker::get_expenses() const {
	return m_expences;
}

void Tracker::generate_report_by_category() {
	for (auto& expense : get_expenses()) {
		if (m_by_category.count(expense.get_category()) > 0) {
			m_by_category[expense.get_category()] += expense.get_amount();
		}
		else {
			m_by_category[expense.get_category()] = expense.get_amount();
		}
	}
}

void Tracker::generate_reoprt_weekly() {
    std::sort(m_expences.begin(), m_expences.end(), [](const Expense& a, const Expense& b) {
        if (a.get_date().month != b.get_date().month) {
            return a.get_date().month < b.get_date().month;
        }
        return a.get_date().day < b.get_date().day;
        });

    for (int i = 0; i < m_expences.size(); ++i) {
        std::vector<Expense> current_week;
        current_week.push_back(m_expences[i]);

        for (int j = i + 1; j < m_expences.size(); ++j) {
            int days_diff = (m_expences[j].get_date().month - m_expences[i].get_date().month) * 30 +
                (m_expences[j].get_date().day - m_expences[i].get_date().day);

            if (days_diff <= 7) {
                current_week.push_back(m_expences[j]);
            }
            else {
                break;
            }
        }

        m_weekly_report.push_back(current_week);
    }
}

#include <algorithm>

void Tracker::generate_report_monthly() {

    std::sort(m_expences.begin(), m_expences.end(), [](const Expense& a, const Expense& b) {
        if (a.get_date().year != b.get_date().year) {
            return a.get_date().year < b.get_date().year;
        }
        if (a.get_date().month != b.get_date().month) {
            return a.get_date().month < b.get_date().month;
        }
        return a.get_date().day < b.get_date().day;
        });

    for (int i = 0; i < m_expences.size(); ++i) {
        std::vector<Expense> current_month;
        current_month.push_back(m_expences[i]);

        for (int j = i + 1; j < m_expences.size(); ++j) {
            int days_diff = (m_expences[j].get_date().year - m_expences[i].get_date().year) * 365 +
                (m_expences[j].get_date().month - m_expences[i].get_date().month) * 30 +
                (m_expences[j].get_date().day - m_expences[i].get_date().day);

            if (days_diff <= 31) {
                current_month.push_back(m_expences[j]);
            }
            else {
                break;
            }
        }

        m_monthly_report.push_back(current_month);
    }
}

void Tracker::save_report_to_file() {
    m_report = "";
    generate_report_by_category();
	for (auto& cat : m_by_category) {
		m_report += "\nCategory: ";
		m_report += cat.first + " - " + std::to_string(cat.second) + " AMD\n";
	}
    generate_reoprt_weekly();
    for (size_t i = 0; i < m_weekly_report.size(); ++i) {
        int total_amount = 0;
        for (const auto& expense : m_weekly_report[i]) {
            total_amount += expense.get_amount();
        }
        m_report += "\nWeek " + std::to_string(i + 1) + " Total: " + std::to_string(total_amount) + " AMD\n";
    }
    generate_report_monthly();
    for (size_t i = 0; i < m_monthly_report.size(); ++i) {
        int total_amount = 0;
        for (const auto& expense : m_monthly_report[i]) {
            total_amount += expense.get_amount();
        }
        m_report += "\nMonth " + std::to_string(i + 1) + " Total: " + std::to_string(total_amount) + " AMD\n";
    }

	std::ofstream output("report.txt");
	if (output.is_open()) {
		output << m_report << std::endl;
		output.close();
		std::cout << "Report created." << std::endl;
	}
	else {
		std::cout << "Error: could not create a report." << std::endl;
	}
    std::cout << m_report << std::endl;
}



