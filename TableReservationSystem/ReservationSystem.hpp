#pragma once
#include "Customer.hpp"
#include "Table.hpp"
#include <vector>

struct Date {
	int day{ 1 };
	int month{ 1 };
	int year{ 1990 };
};

class ReservationSystem
{
public:
	ReservationSystem() = default;
	~ReservationSystem() = default;
public:
	void add_table(Table*);
	std::vector<Table*> get_tables() const;
	bool search_by_capacity(const int);
	void reserve_table(const Customer&, const Date&, Table*);
private:
	void generate_report();
private:
	std::vector < Table*> m_tables;
	std::string m_report;
};

