#pragma once
#include "Parking.hpp"
#include <string>

class User
{
public:
	User(const std::string&, const SIZE&);
	~User() = default;
public:
	void set_name(const std::string&);
	std::string get_name() const;
	void set_size(const SIZE&);
	SIZE get_size() const;
private:
	std::string m_name;
	SIZE m_vehicle_size;
};

