#pragma once
#include <string>
#include "Customer.h"

class Customer;

class Interation
{
public:
	virtual std::string inter_info() = 0;
	virtual void register_interation() = 0;
};