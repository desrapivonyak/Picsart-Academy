#pragma once
#include "Deliveries.hpp"
#include "User.hpp"
#include <vector>
#include <fstream>

class Tracking
{
public:
	Tracking() = default;
	~Tracking() = default;
public:
	void add_deliveries(Deliveries*);
	std::vector<Deliveries*> get_deliveries() const;
	std::string track_status(Deliveries*);
	void change_status(Deliveries*);
	Date schedule_delivery(Deliveries*);
	void generate_receipt();
private:
	std::vector<Deliveries*> m_deliveries;
};