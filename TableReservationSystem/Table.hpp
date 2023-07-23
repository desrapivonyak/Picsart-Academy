#pragma once
#include <string>

class Table
{
public:
	Table(const int, const int);
	~Table() = default;
public:
	void set_capacity(const int);
	int get_capacity() const;
	void set_table_number(const int);
	int get_table_number() const;
	void set_status(const bool);
	bool get_status() const;
private:
	int m_capacity;
	int m_table_num;
	bool m_status;
};

