#include "Table.hpp"

Table::Table(const int num, const int capacity) : m_capacity{ capacity }, m_table_num{ num }, m_status{ true } {}

void Table::set_capacity(const int cap) {
	m_capacity = cap;
}

int Table::get_capacity() const {
	return m_capacity;
}

void Table::set_table_number(const int num) {
	m_table_num = num;
}

int Table::get_table_number() const {
	return m_table_num;
}

void Table::set_status(bool st) {
	m_status = st;
}

bool Table::get_status() const {
	return m_status;
}