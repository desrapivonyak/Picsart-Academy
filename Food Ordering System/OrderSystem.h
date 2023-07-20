#pragma once
#include "Customer.h"
#include "Restaurant.h"
#include <iostream>

class OrderSystem
{
public:
	OrderSystem(const Customer&);
	~OrderSystem() = default;
public:
	void set_orderNumber(int);
	int get_order_number() const;
	std::pair<std::string, int> placeOrder(const Restaurant&);
	void trackOrder(int);
	std::string bill_generation(const std::string&, const Restaurant&);
	void report_to_console(const std::string&);
	void report_to_txt(const std::string&);
private:
	std::string get_current_time();
private:
	int m_orderNumber;
	Customer m_custom;
};

