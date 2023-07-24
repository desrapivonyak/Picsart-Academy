#pragma once
#include "Customer.hpp"
#include "Travel.hpp"
#include <vector>

class System
{
public:
	System() = default;
	~System() = default;
public:
	void add_travel(Travel*);
	std::vector<Travel*> get_travel() const;
	void search_by_price(const int, const int);
	void booking(Travel*, int);
	void generate_ticket();
private:
	std::string m_ticket;
	std::vector<Travel*> m_travels;
};

