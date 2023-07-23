#pragma once
#include "Taxi.hpp"
#include "User.hpp"
#include <vector>

class System
{
public:
	System() = default;
	~System() = default;
public:
	void add_taxi(Taxi*);
	void calculate_ride(Taxi*, const int);
	void book_taxi(const User&, const int);
	void generate_receipt();
private:
	int m_fee;
	const int m_min_fee = 300;
	std::string m_receipt;
	std::vector<Taxi*> m_taxies;
};

