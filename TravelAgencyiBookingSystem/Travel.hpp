#pragma once
#include <string>

class Travel
{
public:
	Travel(const std::string&, const int, const int);
	~Travel() = default;
public:
	void set_destination(const std::string&);
	std::string get_destination() const;
	void set_price(const int);
	int get_price() const;
	void set_slots(const int);
	int get_slots() const;
private:
	std::string m_destination;
	int m_price;
	int m_slots;
};

